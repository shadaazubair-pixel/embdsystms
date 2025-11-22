#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRB|=(1<<DDB5); // initialized as output
	DDRD&=~(1<<DDD2);
	PORTD|=(1<<PD2);
	
	
	
    
    while (1) 
	
    { if(!(PIND&(1<<PD2))){
		PORTB|=(1<<PB5);
    }
	
	else{
		PORTB&=~(1<<PB5);
	}
}
}

