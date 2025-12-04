#define  F_CPU 16000000UL
#include <avr/io.h>


void delay_ms(){
	TCNT0=0;  //loading initial value
	TCCR0A&=~(1<<WGM00)|(1<<WGM01);  // set to normal mode
	
	//set to prescaling by 64
	TCCR0B&=~(1<<CS02);
	TCCR0B|=(1<<CS01)|(1<<CS00);
	
	//repeating loop for 976 times
	for(int i=0;i<976;i++){
		while(!(TIFR0&(1<<TOV0)));  //waiting for timer flag to set
		TIFR0|=(1<<TOV0); //reset timer flag 
	}
}



int main(void)
{
	DDRB|=(1<<DDB5);
	while(1){
		PORTB^=(1<<PB5);  //toggle PB5
		delay_ms(); //calling function
	}
}

