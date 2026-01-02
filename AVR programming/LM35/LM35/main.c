#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void ADC_init(){
	ADMUX|=(1<<REFS0);  //Set ADC reference voltage as 5v
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);  //Enable ADC and set prescalar to 128
}



uint16_t ADC_Read(uint8_t channel){
	channel&=0x07;//limiting channel to 7
	ADMUX&=0xF0;   //channel selection
	ADMUX|=channel;
	ADCSRA|=(1<<ADSC);  //start conversion
	while(ADCSRA&(1<<ADSC));
	return(ADCL|(ADCH<<8));
}

int main(void)
{
	uint16_t adc_value;
	lcd_init();  //lcd initializing
	ADC_init();  //ADC initializing
   
    while (1) 
    {
		adc_value=ADC_Read(0);
		float temp=adc_value*0.488; //convert ADC to temp
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Temperature:");
		lcd_set_cursor(1,0);
		lcd_print_float(temp);
		lcd_data(0xDF);
		lcd_print("C");
		_delay_ms(500);
    }
}

