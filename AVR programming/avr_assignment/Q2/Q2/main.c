
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB&=~(1<<DDB2);  //configure PB2 as input
	DDRD|=(1<<DDD3)|(1<<DDD4); //configure PD3 and PD4 as output
	PORTB|=(1<<PB2);  //enable internal pull up
	
	
	//red led on and green led off
	PORTD|=(1<<PD3);   //
	PORTD&=~(1<<PD4);

	
	int state=0;
	
	
    while (1) {
		
		if(PINB&(1<<PB2)){ //when button pressed
			if(state==0){
				//green led on red led off
				PORTD&=~(1<<PD3);  
				PORTD|=(1<<PD4);
				state=1;
			}
			
			else{
				//red on green off
				PORTD|=(1<<PD3);
				PORTD&=~(1<<PD4);
				state=0;
			}
			
			_delay_ms(20);
		}
		
		while(!(PINB&(1<<PB2))); //wait till button pressed
			_delay_ms(20);
		
		
		
	}

	
	return 0;
}


