/*
 * Blink_toggle.c
 *
 * Created: 11/19/2025 8:06:51 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
   DDRD|=(1<<DDD2);       //set DDD2(PD2) as output
   
    while (1) 
    {
		PORTD^=(1<<PD2); //set PD2=1
		_delay_ms(1000);
    }
}

