/*
 * delay.c
 *
 * Created: 12/4/2025 12:58:36 PM
 *  Author: user
 */ 

#include<avr/io.h>
#include"delay.h"

void timer0_init(){  //timer 0 initializaton function
	TCNT0=0;   //load initial value
	OCR0A=249;  //set output compare register to compare till 250 count
	
	
	//set in CTC mode
	TCCR0A|=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	
	
	//set in prescalar with 64
	TCCR0B|=(1<<CS01)|(1<<CS00);
	TCCR0B&=~(1<<CS02);
}


void delay_ms(uint16_t ms){  //delay function definition
	



while(ms--){
	

while(!(TIFR0&(1<<OCF0A)));  //1ms delay
TIFR0|=(1<<OCF0A);
}
}
