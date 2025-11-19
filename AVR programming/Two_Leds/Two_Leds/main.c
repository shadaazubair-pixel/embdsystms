
#define  F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
    DDRB|=(1<<DDB5)|(1<<DDB3); //initializing pin D5 and D3 as output
	
    while (1) 
	
    {
		//pin 1 on 2 off
		PORTB|=(1<<PB5);
		PORTB&=~(1<<PB3);
		_delay_ms(5000);
		
		
		//pin 1 and 2 off
		PORTB&=~(1<<PB5);
		PORTB&=~(1<<PB3);
		_delay_ms(3000);
		
		//pin 1 off 2 on
		//PORTB&=(1<<PB5);
		PORTB|=(1<<PB3);
		_delay_ms(5000);
		
		//pin 1 and 2 off
		PORTB&=~(1<<PB5);
		PORTB&=~(1<<PB3);
		_delay_ms(3000);
		
		
		
    }
}

