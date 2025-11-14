/*
 * Blink.c
 *
 * Created: 11/13/2025 8:46:02 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD=0b0000100;  // set DDD2(PD2) as output
    while (1) 
    {
		PORTD=0b0000100;  //set PD2=1
		_delay_ms(1000);
		PORTD=0b0000000; //set PD2=0
		_delay_ms(1000);
		
		
    }
}

