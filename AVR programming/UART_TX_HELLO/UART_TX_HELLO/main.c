#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>





int main(void)
{
	
	char str[10]="HELLO\n";
	
	UBRR0H=0;
	UBRR0L=103;  //set the baud rate
	
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);  //
	UCSR0C&=~((1<<UPM00)|(1<<UPM01)|(1<<USBS0));  //0 parity and 1 stop bit
	UCSR0B|=(1<<TXEN0);  //enable transmission
	
    
    while (1) 
	
    {
		for(int i=0;str[i]!='\0';i++){
			UDR0=str[i];
		while(!(UCSR0A&(1<<UDRE0)));
		
			
		}
		
		
		_delay_ms(1000);
		
    }
}

