#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)


{
	DDRD|=(1<<DDD6); //configure PD6 as output sice we are using OCR0A
	
	
	//set in phase correct PWM
	TCCR0A|=(1<<WGM00);
	TCCR0A&=~(1<<WGM01);
	
	//configure in non inverting PWM
	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);
	
	//configure for prescalar 64 value
	TCCR0B&=~(1<<CS02);
	TCCR0B|=(1<<CS01)|(1<<CS00);
	
	OCR0A=77; //Duty cycle 30%
	
	while (1)
	{
		
	}
}

