#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void ADC_init(){
	ADMUX|=(1<<REFS0); //set reference voltage as 5 v
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);  //enable ADC and set pre-scalar as 64

	
}

uint16_t ADC_Read(uint8_t channel){
	channel&=0x07; //limit channel selection upto 7
	ADMUX=(ADMUX&0xF0)|channel;
	ADCSRA|=(1<<ADSC); //start ADC conversion
	while(ADCSRA&(1<<ADSC));
	
	
	return((ADCH<<8)|ADCL);
		
}

void PWM_init(void)
	{
		DDRD|=(1<<PD6); // OC0A (PD6) as output

		// Fast PWM, non-inverting mode
		TCCR0A=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);

		//Prescaler = 64
		TCCR0B=(1<<CS01)|(1<<CS00);

		OCR0A=0;             // Motor OFF initially
	}
	
	uint8_t motorspeed(float temp){
		
		if(temp<25.00){
			return 64; //duty cycle 25%
		}
		
		else
			return 192;  //duty cycle 75%
		
	}





int main(void){
	uint8_t system=0;
	DDRD&=~(1<<DDD2); //set PD2 as input
	PORTD|=(1<<PD2);  //enable internal pull up
	
	
	ADC_init();
	PWM_init();
	
	


    
    while(1)
    {
	    // Toggle ON/OFF
	    if(!(PIND&(1<<PD2)))
	    {
		    _delay_ms(20);

		    if(!(PIND&(1<<PD2)))
		    {
			    system^= 1;

			    while(!(PIND&(1<<PD2)));
		    }
	    }

	    if(system)
	    {
		    uint16_t ADC_value=ADC_Read(5);
		    float temp=ADC_value*0.488;

		    OCR0A=motorspeed(temp);
	    }
	    else
	    {
		    OCR0A = 0;
	    }

	    _delay_ms(200);
    }
    
}