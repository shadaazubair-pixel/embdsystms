#define F_CPU 16000000UL
#include <avr/io.h>



void speed(int s){
	OCR0A=s;
}

int main(void)


{
	DDRD|=(1<<DDD6);  //configure PD6 as output siNce we are using OCR0A
	DDRB&=~(1<<DDB4); //set PB4 as input
	PORTB|=(1<<PB4); //enable internal pull up
	
	
	//set in fast PWM
	TCCR0A|=(1<<WGM00)|(1<<WGM01);
	
	//configure in non inverting PWM
	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);
	
	//configure for prescalar 64 value
	TCCR0B&=~(1<<CS02);
	TCCR0B|=(1<<CS01)|(1<<CS00);
	

	
	while (1)
	
	{
		speed(64);  //25% duty cycle
		while(PINB&(1<<PB4));   //wait for button press
		while(!(PINB&(1<<PB4)));  //wait for button release
		
		
		speed(128); //50% duty cycle
		
		
		
		while(PINB&(1<<PB4)); //wait for button press
		while(!(PINB&(1<<PB4))); //wait for button release
		
		speed(192);  // 75% duty cycle
		
		while(PINB&(1<<PB4)); //wait for button press
		while(!(PINB&(1<<PB4))); //wait for button release
		

		
		
		speed(255);             //100% duty cycle
		while(PINB&(1<<PB4)); //wait for button press
		while(!(PINB&(1<<PB4))); //wait for button release
		
		speed(0);              //off
		while(PINB&(1<<PB4)); //wait for button press
		while(!(PINB&(1<<PB4))); //wait for button release
		
		
		
	}
	return 0;
}
