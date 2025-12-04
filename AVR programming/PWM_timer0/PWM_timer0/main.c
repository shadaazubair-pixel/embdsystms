#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)


{
	DDRD|=(1<<DDD6); //configure PD6 as output
	
	
	//set in phase correct PWM
   TCCR0A|=(1<<WGM00);
   TCCR0A&=~(1<<WGM01);
   
   //configure in non inverting PWM
   TCCR0A|=(1<<COM0A1);
   TCCR0A&=~(1<<COM0A0);
   
   //configure for prescalar 8value
   TCCR0B&=~(1<<CS02);
   TCCR0B|=(1<<CS01)|(1<<CS00);
   
  // OCR0A=128; //Duty cycle 50%
   
    while (1) 
    {
		for(int i=0;i<=255;i++){
			OCR0A=i;
			_delay_ms(5);
			
    }
	
	for(int i=255;i>0;i--){
		OCR0A=i;
		_delay_ms(5);
		
	}
}
}

