#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	char data;
	DDRB|=(1<<DDB3); //config PB3 as output
	
	UBRR0H=0;
	UBRR0L=103;   //set baud rate
	UCSR0B|=(1<<RXEN0); //enable recieving
	UCSR0C&=~(1<<UPM01)|(1<<UPM00)|(1<<USBS0);  //set parity and 1 stop bit
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);  //set character bit
	
    while (1) 
	
    {
		
		while(!(UCSR0A & (1<<RXC0))); //wait till recieving complete
		data=UDR0;
		
		
		if(data=='1'){
			
			PORTB|=(1<<PB3);  //LED ON
			_delay_ms(500);
		
			PORTB&=~(1<<PB3); //LED OFF
			_delay_ms(500);
		
	
    }
}
}

