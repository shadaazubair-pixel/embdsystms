#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int count = 0;

ISR(TIMER1_COMPA_vect)
{
	PORTB^=(1<<PB1); //toggle PB1
}



ISR(TIMER2_COMPA_vect)
{
	count++;

	if(count>=31)  //toggle 0.5s
	{
		PORTB^=(1<<PB2);
		count=0;
	}
}

int main(void)
{
    DDRB|=(1<<DDB1)|(1<<DDB2); //set PB1 PB2 as output
	
	// Set Timer1 prescaler to 1024
	TCCR1B |=(1<<CS12)|(1<<CS10);
	TCCR1B&=~(1<<CS11);
	
	//compare value for 2 seconds
	OCR1A=31249;
	
	//set Timer1 to CTC mode
	TCCR1B|=(1<<WGM12);
	
	// Enable Timer1 compare interrupt
	TIMSK1|=(1<<OCIE1A);
	
	
	TCNT2=0;
	OCR2A=249;
	
	//set timer2 prescalar 1024 mode
	TCCR2B|=(1<<CS22)|(1<<CS20);
	TCCR2B&=~(1<<CS21);
	
	//set timer2 ctc mode
	TCCR2A|=(1<<WGM21);
	TCCR2A&=~(1<<WGM20);
	
	
	// enable timer2 compare match interrupt
	TIMSK2|=(1<<OCIE2A);
	
	//enable global interrupt
	sei();
	
	
	
	
	
	
    while (1) 
    {
    }
	
	return 0;
}

