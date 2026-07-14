#define F_CPU 16000000UL
#include <avr/io.h>


//green light
void green(void){
	PORTB|=(1<<PB2);
	PORTB&=~(1<<PB3);
	PORTB&=~(1<<PB4);
	
}


//orange light
void orange(void){
	PORTB&=~(1<<PB2);
	PORTB|=(1<<PB3);
	PORTB&=~(1<<PB4);
	
}


//red light
void red(void){
	PORTB&=~(1<<PB2);
	PORTB&=~(1<<PB3);
	PORTB|=(1<<PB4);
	
}

void delay(int sec){
	
	//load initial value to 0
	TCNT0=0;
	
	//set timer to CTC mode
	TCCR0A&=~(1<<WGM00); 
	TCCR0A|=(1<<WGM01);
	
	//set prescalar to 1024
	TCCR0B|=(1<<CS02)|(1<<CS00);
	TCCR0B&=~(1<<CS01);
	
	//load output compare register to 249 to get 250 counts
	OCR0A=249;
	
	
	for(int j=0;j<sec;j++){
		
		for(int i=0;i<63;i++){
			while(!(TIFR0&(1<<OCF0A))); //wait till OCF0A flag is set ie, TCNT0=OCR0A
			TIFR0|=(1<<OCF0A);  //reset
		}
		
		
	}
	
	
	
}


int main(void)
{
	
    DDRB|=(1<<DDB2)|(1<<DDB3)|(1<<DDB4);  //configure PB2, PB3, PB4 as output
	
	
	
	
	
    while (1) 
    {
		green();
		delay(10);
	
		
		
		
		orange();
		delay(3);
		
		red();
		delay(10);
    }
	
	return 0;
}

