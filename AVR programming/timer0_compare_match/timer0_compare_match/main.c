#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>


volatile uint16_t count=0;
ISR(TIMER0_COMPA_vect){
	if(count>313){
		PORTB^=(1<<PB5);
		count=0;
	}
	else{
		count++;
	}
}


int main(void)
{
	DDRB|=(1<<DDB5);  //configure PB5  as output
	sei(); //enable global interrupt
	
	
    TCNT0=0; // load initial value
	OCR0A=199; //set outout compare register t0 199 (200 count)
	
	
	//set to CTC mode
	TCCR0A&=~(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	
	//set prescalar to 64
	TCCR0B&=~(1<<CS02);
	TCCR0B|=(1<<CS01)|(1<<CS00);
	
	TIMSK0|=(1<<OCIE0A); //timer overflow interrupt
	
    while (1) 
    {
    }
}

