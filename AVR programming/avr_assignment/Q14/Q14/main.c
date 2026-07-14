#define F_CPU 16000000UL
#include <avr/io.h>

//this function initialises ADC
void ADC_init()
{
	ADMUX|=(1<<REFS0); //set reference voltage as 5V
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1); //enable ADC and set prescaler as 64
}

//this function reads ADC value
uint16_t ADC_Read(uint8_t channel)
{
	channel&=0x07; //limit channel selection to ADC0-ADC7
	ADMUX=(ADMUX&0xF8)|channel;
	ADCSRA|=(1<<ADSC); //start ADC conversion
	while(ADCSRA&(1<<ADSC)); //wait until conversion is complete

	return ADC;
}

//this function initialises Timer0 in Fast PWM mode
void PWM_init()
{
	DDRD|=(1<<DDD6); //configure PD6(OC0A) as output
	TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00); //Fast PWM, non-inverting mode
	TCCR0B|=(1<<CS01)|(1<<CS00); //set prescaler as 64
	OCR0A=0; //motor OFF initially
}

//this function converts 10-bit ADC value into 8-bit PWM value
uint8_t motor_speed(uint16_t adc_value)
{
	return adc_value/4;
}

int main(void)
{
	uint16_t adc_value;
	uint8_t speed;

	ADC_init();
	PWM_init();

	while(1)
	{
		adc_value=ADC_Read(0); //read potentiometer connected to ADC0
		speed=motor_speed(adc_value); //convert ADC value to PWM value
		OCR0A=speed; //change motor speed
	}
}

