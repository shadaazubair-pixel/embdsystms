#define F_CPU 16000000UL
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>

//this function initialises PWM
void PWM_init()
{
	DDRD|=(1<<DDD6); //configure PD6 as output

	TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00); //Fast PWM, non-inverting mode

	TCCR0B|=(1<<CS01)|(1<<CS00); //set prescaler as 64

	OCR0A=0; //LED OFF initially
}

//this function sends a string through UART
void UART_send(char *str)
{
	while(*str)
	{
		while(!(UCSR0A&(1<<UDRE0))); //wait until transmit buffer is empty
		UDR0=*str++; //send one character
	}
}

int main(void)
{
	char data[5];
	uint8_t i=0;
	uint8_t brightness;

	UBRR0H=0;
	UBRR0L=103; //set baud rate as 9600

	UCSR0B=(1<<RXEN0)|(1<<TXEN0); //enable transmitter and receiver

	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00); //set character size as 8-bit

	PWM_init();

	while(1)
	{
		i=0;

		//receive characters until Enter is pressed
		while(1)
		{
			while(!(UCSR0A&(1<<RXC0))); //wait until receiving is complete

			data[i]=UDR0; //store received character

			if(data[i]=='\r')
			break;

			i++;
		}

		data[i]='\0'; //end of string

		//check whether command is ON
		if(strcmp(data,"ON")==0)
		{
			OCR0A=255; //100% duty cycle

			UART_send("LED is now ON\r\n");
		}

		//check whether command is OFF
		else if(strcmp(data,"OFF")==0)
		{
			OCR0A=0; //0% duty cycle

			UART_send("LED is now OFF\r\n");
		}

		//otherwise treat it as brightness value
		else
		{
			brightness=atoi(data);

			if(brightness<=100)
			{
				OCR0A=(brightness*255)/100; //convert percentage to PWM value

				UART_send("Brightness set to ");
				UART_send(data);
				UART_send("%\r\n");
			}
		}
	}
}