#define  F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRD|=(1<<DD5);
	
	while(1){
		PORTD|=(1<<PD5);
		_delay_ms(3000);
		
		PORTD&=~(1<<PD5);
		_delay_ms(5000);
	}
}