/*
 * Blinkhw.c
 *
 * Created: 11/13/2025 9:42:45 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB=0b00100000;  // set DDD2(PB5) as output
    while (1) 
    {
		PORTB=0b00100000;
		_delay_ms(3000);  //set PB5=1
		_delay_ms(1000);
		PORTB=0b00000000;
		_delay_ms(3000); //set PB5=0
		
		
		
    }
}

