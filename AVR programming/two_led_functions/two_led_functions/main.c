
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void cw(){  // function declaration and definition to turn one LED on and other off
	
	PORTB|=(1<<PB3);
	PORTB&=~(1<<PB5);
	_delay_ms(5000);
	
}

void stp(){ // function declaration and definition to turn both off
	PORTB&=~(1<<PB3);
	PORTB&=~(1<<PB5);
	_delay_ms(3000);
	
}

void ccw(){  // function declaration and definition to turn first LED off and second on
	
	PORTB&=~(1<<PB3);
	PORTB|=(1<<PB5);
	_delay_ms(5000);
}


int main(void)
{
	DDRB|=(1<<DDB3)|(1<<DDB5);  //Initializing pin3 and pin5 as output
	
   
    while (1)
	 
    {
		cw();       
		stp();
		ccw();     
		stp();     
		
		
    }
}

