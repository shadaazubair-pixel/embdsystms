#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void red(){ // function declaration and definition for stop signal
	PORTD|=(1<<PD4);
	PORTD&=~(1<<PD6);
	PORTD&=~(1<<PD7);
	
}

void yellow(){  // function declaration and definition for get ready signal
	PORTD&=~(1<<PD4);
	PORTD|=(1<<PD6);
	PORTD&=~(1<<PD7);
	
}

void green(){ // function declaration and definition for go signal
	PORTD&=~(1<<PD4);
	PORTD&=~(1<<PD6);
	PORTD|=(1<<PD7);
	
}


int main(void)
{
	DDRD|=(1<<DDD4)|(1<<DDD6)|(1<<DDD7);

    while (1) 
    {
		red();
		_delay_ms(5000);
		yellow();
		_delay_ms(1000);
		green();
		_delay_ms(5000);
    }
}

