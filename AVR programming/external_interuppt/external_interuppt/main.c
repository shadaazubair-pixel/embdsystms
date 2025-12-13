#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect){  //ISR for external interrupt 0;
	PORTB|=(1<<PB5);  //toggling LED
	_delay_ms(1000);
}

int main(void)
{
    sei();  //enabling global interrupt
	DDRB|=(1<<DDB5)|(1<<DDB4); //config PB5 as output
	DDRD&=~(1<<DDD2);  //CONFIG PD2 as input normally pull down condition
	
	EICRA|=(1<<ISC01)|(1<<ISC00); //configure external interrupt for rising edge
	EIMSK|=(1<<INT0);  // enabling external interrupt 0
	
	
    while (1) 
    {
		PORTB&=~(1<<PB5);
		PORTB^=(1<<PB4);
		_delay_ms(1000);
    }
}

