#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(){
	
	TCNT0=0; //load initial value
	OCR0A=199; //compare value(total count=0)
	
	// set timer in CTC mode
	TCCR0A&=~(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	
	
	//set no prescaling
	TCCR0B&=~((1<<CS02)|(1<<CS01));
	TCCR0B|=(1<<CS00);
	
	for(long int i=0;i<80000;i++){    //repeat 80000 times to get 1s delay
		while(!(TIFR0&(1<<OCF0A)));  //reset OCF0A flag
		
		TIFR0|=(1<<OCF0A);
	}
}


int main(void)
{
	DDRB|=(1<<DDB5); //configure PB5 as output
    
    while (1) 
    {
		PORTB^=(1<<PB5);  //toggle output
		delay_1s();  //calling delay function
    }
}

