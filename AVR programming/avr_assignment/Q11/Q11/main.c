#define F_CPU 16000000UL
#include <avr/io.h>

void ADC_init()
{
	ADMUX=(1<<REFS0);      // AVCC reference, ADC0
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1); //Enable ADC and set  Prescaler = 64
}

uint16_t ADC_read(uint8_t channel)
{
	channel&=0x07; //limit channel to 7

	ADMUX=(ADMUX&0xF8)|channel;
	ADCSRA|=(1<<ADSC); //start conversion
	while(ADCSRA&(1<<ADSC));
	return ADC;
}

void Servo_init()
{
	DDRB|=(1<<PB1);          // set PB1 as output
	ICR1=20000;              //(20 ms period=50 Hz)

	//Phase Correct PWM, TOP = ICR1, Non-inverting
	TCCR1B=(1<<COM1A1)|(1<<WGM11);
	TCCR1B=(1<<WGM13)|(1<<CS11);   // Prescaler  8
}

uint16_t Servo_Position(uint16_t adc)
{
	// Map ADC (0-1023) to pulse width (1000-2000 us)
	return 1000 + ((uint32_t)adc * 1000) / 1023;
}

int main(void)
{
	ADC_init();
	Servo_init();

	while(1)
	{
		uint16_t adc_value=ADC_read(0);

		OCR1A= Servo_Position(adc_value);
	}
}