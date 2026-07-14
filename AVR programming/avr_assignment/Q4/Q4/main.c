#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void func(int count){
	PORTB=count;
}


int main(void)


{

	int count=0;
    DDRB|=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3); //set as output
	DDRD&=~(1<<DDD2); //switch config as input
	PORTD|=(1<<PD2); //enable internal pull up
	
	PORTB=0;
	while(1){
		
		while((PIND&(1<<PD2))); //wait for switch press
		count++;
		
		if(count>15){  //if count>15 reset to 0
			count=0;
			
		}
		func(count);
		_delay_ms(20);
		
		while(!(PIND&(1<<PD2)));  //wait for button release
		_delay_ms(20);
		
		
	}
	
	
	return 0;
}

