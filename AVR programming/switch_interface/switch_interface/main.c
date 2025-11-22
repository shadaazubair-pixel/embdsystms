#define F_CPU 16000000UL
#include <avr/io.h>



int main(void)
{
    DDRB|=(1<<DDB5); //initializing PB5 as output
	DDRD&=~(1<<DDD2);  //initializing PD2 as input
	
    while (1)
	 
    {
		if(PIND&=(1<<PD2)){ 
			PORTB|=(1<<PB5); //LED on
    }
	else{
		PORTB&=~(1<<PB5);     //LED off
	}
}
}


