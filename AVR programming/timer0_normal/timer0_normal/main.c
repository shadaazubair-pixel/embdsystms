#define  F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(){
	TCNT0=0; //load minimum value of counter
	TCCR0A&=~((1<<WGM00)|(1<<WGM01)); //set timer in  normal mode
	
	
	//set no prescaling
	TCCR0B&=~((1<<CS02)|(1<<CS01));
	TCCR0B|=(1<<CS00);
	
	
	
	//Repeat 62500 times for getting 1s dealy
	for(long int i=0;i<62500;i++){ 
		
		
		while(!(TIFR0&(1<<TOV0))); //checking TOV0 flag
		
		TIFR0|=(1<<TOV0); //Writing 1 to make TOV0 =0, Strange rule
	}
}


int main(void)
{
    DDRB|=(1<<DDB5);
    while (1) 
	
    {
		PORTB^=(1<<PB5);
		delay_1s();
    }
}

