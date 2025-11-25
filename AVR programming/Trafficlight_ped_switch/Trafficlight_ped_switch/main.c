#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

void cw(){ //function definition and declaration for stop signal
	PORTC|=(1<<PC5); 
	PORTC&=~(1<<PC4);
	PORTC&=~(1<<PC3);
	_delay_ms(5000);
	
}

void ccw(){ //function definition and declaration for get ready signal
	PORTC&=~(1<<PC5);
	PORTC|=(1<<PC4);
	PORTC&=~(1<<PC3);
	_delay_ms(3000);
	
}

void cccw(){ //function definition and declaration for go signal
	PORTC&=~(1<<PC5);
	PORTC&=~(1<<PC4);
	PORTC|=(1<<PC3);
	_delay_ms(5000);
	
}

void gw(){   //function definition and declaration for rotating the motor clockwise
	PORTB|=(1<<PB5);
	PORTB&=~(1<<PB2);
	_delay_ms(10000);
}
void ggw(){  //function definition and declaration for rotating the motor anticlockwise
	PORTB&=~(1<<PB5);
	PORTB|=(1<<PB2);
	_delay_ms(10000);
}
void gggw(){ //function definition and declaration for stationary motion of motor
	PORTB&=~(1<<PB5);
	PORTB&=~(1<<PB2);
	//_delay_ms(10000);
}





int main(void)
{
	DDRC|=(1<<DDC5)|(1<<DDC4)|(1<<DDC3); //initializing PC5, PC4, PC3 as output
	DDRB|=(1<<DDB5)|(1<<DDB2); //initializing PB5 and PB2 as output
	
	DDRD&=~(1<<DDD2); // initializing PD2 as input
	PORTD|=(1<<PD2); //input Pulled up condition
    while (1)
	    {
			
			if(!(PIND&(1<<PD2))){  //checking if input is 0
				cw();
				gw();
				ggw();
				gggw();
			}
			else{
				cw();
				ccw();
				cccw();
				
			}
			
			
			
    }
}


