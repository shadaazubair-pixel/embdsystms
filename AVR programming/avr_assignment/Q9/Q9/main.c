#define F_CPU 16000000UL
#include <avr/io.h>

void speed(int s)
{
	OCR0A=s;
}

int main(void)
{
	
	
	DDRD|=(1<<DDD6); //configure PD6 as output
	

	
	DDRB&=~(1<<DDB4); //configure PB4 as input
	PORTB|=(1<<PB4); //enable pull up resistor


	
	TCCR0A|=(1<<WGM00)|(1<<WGM01);  //fast PWM mode
	TCCR0B&=~(1<<WGM02);

	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);

	
	TCCR0B&=~(1<<CS02);  //prescaler 64
	TCCR0B|=(1<<CS01)|(1<<CS00);

	int a=0;

	// Start at 25%
	speed(64);

	while (1)
	{
		
		while(PINB&(1<<PB4)); //wait for button press
		while(!(PINB&(1<<PB4))); //wait for button release

		
		a++;

		if (a>3)
		a=0;

		switch(a)
		{
			case 0:
			speed(64);      // 25%
			break;

			case 1:
			speed(128);     // 50%
			break;

			case 2:
			speed(192);     // 75%
			break;

			case 3:
			speed(255);     // 100%
			break;
		}
	}

	return 0;
}