#define  F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


volatile uint16_t flag=0;
ISR(INT0_vect){
	
	flag=1;

	
}


void cw(){  //function declaration and definition for stop signal
	PORTC|=(1<<PC5); 
	PORTC&=~((1<<PC4)|(1<<PC3));
	
}

void ccw(){  //function declaration and definition for get ready signal
	PORTC|=(1<<PC4);
	PORTC&=~((1<<PC5)|(1<<PC3));
	
}

void cccw(){  //function declaration and definition for go signal
	PORTC|=(1<<PC3);
	PORTC&=~((1<<PC5)|(1<<PC4));
	
	
}

void timer0init(){
	for( int i=0;i<235;i++){
		while(!(TIFR0 & (1<<OCF0A)));  //wait till flag set to 1
		TIFR0|=(1<<OCF0A);  //reset flag
	}
	
}

int main(void)
{
	DDRC|=(1<<DDC5)|(1<<DDC4)|(1<<DDC3); //config PC5, PC4, PC3 as output
	DDRB|=(1<<DDB5)|(1<<DDB2); //config PB5, PB2 as output
	DDRD&=~(1<<DDD2); //config PD2 as input
	PORTD|=(1<<PD2); //input pulled up condition
	
	//Timer0 config
	TCNT0=0;  //load initial value
	OCR0A=199;  //config output compare register to compare till 199(200count)
	
	//Set to CTC mode
	TCCR0A&=~(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	
	//set to prescalar 1024
	TCCR0B|=(1<<CS02)|(1<<CS00);
	TCCR0B&=~(1<<CS01);
	
	
	
	
	
    sei();
	EICRA&=~((1<<ISC01)|(1<<ISC00)); //Config external interrupt in low level
	EIMSK|=(1<<INT0); //enabling interrupt 1
	
	
	
	
	
	
    while (1) 
	
    {
		if(flag){
			cw();  //stop signal
			
			timer0init();
			
			PORTB|=(1<<PB5);  //Motor rotate clockwise
			PORTB&=~(1<<PB2);
			
			_delay_ms(5000);
			
			
			PORTB&=~(1<<PB5);  //Motor rotate anti clockwise
			PORTB|=(1<<PB2);
			_delay_ms(5000);
			
			PORTB&=~(1<<PB5);  // motor stops
			PORTB&=~(1<<PB2);
			
			
			flag=0;
			
			
		}
		
		else{
			cw();
			timer0init();
			ccw();
			timer0init();
			cccw();
			timer0init();
			
			
			
		}
		
		
	}

}