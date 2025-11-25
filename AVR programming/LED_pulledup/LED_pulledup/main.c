#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRB|=(1<<DDB5); // initialized as PB5 output
	DDRD&=~(1<<DDD2); //initializing PD2 as input
	PORTD|=(1<<PD2); // input as pulled up condition internally
	
	
	
    
    while (1) 
	
    { if(!(PIND&(1<<PD2))){ //checking if input is 0
		PORTB|=(1<<PB5);  // LED blinks
    }
	
	else{
		PORTB&=~(1<<PB5); // LED do not blink
	}
}
}

