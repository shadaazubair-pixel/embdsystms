/*
 * Modular_timer.c
 *this code implements a delay function using timer 0 and modular concepts
 * Created: 12/4/2025 12:53:14 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include"delay.h" ///" "usually for user defined headers


int main(void)
{
    DDRB|=(1<<PB5); //configure PB5 as output
	timer0_init();  //user defined function for timer 0 configuration
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_ms(5000);  //user defined function for delay
    }
}

