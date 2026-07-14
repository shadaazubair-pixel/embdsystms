#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

// this function prints a 32-bit number
void lcd_print_uint32(uint32_t v)
{
	if(v>=10)
	{
		lcd_print_uint32(v/10); // print higher digits first
	}
	lcd_data('0'+(v%10)); // print last digit
}

// this function displays the counter on LCD
void lcd_display(uint32_t count)
{
	lcd_clear();

	lcd_set_cursor(0,0);
	lcd_print("Counter:");

	lcd_set_cursor(1,0);

	// print leading zeros to make it a 9-digit number
	if(count<100000000) lcd_data('0');
	if(count<10000000) lcd_data('0');
	if(count<1000000) lcd_data('0');
	if(count<100000) lcd_data('0');
	if(count<10000) lcd_data('0');
	if(count<1000) lcd_data('0');
	if(count<100) lcd_data('0');
	if(count<10) lcd_data('0');

	lcd_print_uint32(count);
}

// this function checks how long the button is pressed
uint8_t button_time()
{
	uint16_t time=0;

	while(!(PIND&(1<<PD2)))
	{
		_delay_ms(10);
		time+=10; // increase time by 10 ms
	}

	if(time>=2000)
	return 1; // long press

	else
	return 0; // short press
}

int main(void)
{
	uint32_t count=0;

	DDRD&=~(1<<DDD2); // set PD2 as input
	PORTD|=(1<<PD2);  // enable internal pull-up

	lcd_init(); // initialise LCD

	lcd_display(count); // display 000000000

	while(1)
	{
		// check if button is pressed
		if(!(PIND&(1<<PD2)))
		{
			_delay_ms(20); // debounce delay

			if(!(PIND&(1<<PD2)))
			{
				// check whether it is a short press or long press
				if(button_time())
				{
					count=0; // reset counter
				}
				else
				{
					if(count<999999999)
					{
						count++; // increment counter
					}
				}

				lcd_display(count); // update LCD

				// wait until button is released
				while(!(PIND&(1<<PD2)));
			}
		}
	}
}