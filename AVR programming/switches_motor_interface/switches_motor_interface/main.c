#define F_CPU 16000000UL
#include <avr/io.h>

void cw(){          //function declaration and definition for rotating DC motor clockwise
	PORTB|=(1<<PB5);
	PORTB&=~(1<<PB3);
	
}

void ccw(){    //function declaration and definition for rotating DC motor anticlockwise
	
	PORTB&=~(1<<PB5);
	PORTB|=(1<<PB3);
	
	
}
void stp(){  //function definition and declaration for stationary
	PORTB&=~(1<<PB5);
	PORTB&=~(1<<PB3);
	
}


int main(void)
{
	DDRB|=(1<<DDB5)|(1<<DDB3);  //initializing PB5 and PB3  as output
	DDRD&=~((1<<DDD2)|(1<<DDD4));  //initializing PD2 and PD4 as input
	
	
	while (1)
	
	{
		if((PIND&(1<<PD2))&&!(PIND&(1<<PD4))){    // if PD2 high and PD4 low
			ccw();
		}
		
		else if((PIND&(1<<PD4))&&!(PIND&(1<<PD2))){  //if PD4 high and PD2 low
			cw();
			
			
			
		}
		
		else{  //if both pins are low
			stp();
		}
		
		
		
		
		
		
	}
}
