
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void cw(){
	
	PORTB|=(1<<PB3);
	PORTB&=~(1<<PB5);
	
}

void stp(){
	PORTB&=~(1<<PB3);
	PORTB&=~(1<<PB5);
	
}

void ccw(){
	
	PORTB&=~(1<<PB3);
	PORTB|=(1<<PB5);
}


int main(void)
{
	DDRB|=(1<<DDB3)|(1<<DDB5);
	
   
    while (1)
	 
    {
		cw();
		_delay_ms(5000);
		stp();
		_delay_ms(3000);
		ccw();
		_delay_ms(5000);
		stp();
		_delay_ms(3000);
		
    }
}

