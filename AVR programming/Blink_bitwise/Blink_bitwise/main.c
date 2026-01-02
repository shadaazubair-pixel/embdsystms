
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
    DDRB|=(1<<DDB5);       //set DDD2(PD2) as output
	
    while (1) 
	
    {
		PORTB^=(1<<PB5);    // set PD2=1
		_delay_ms(1000);
		
}
}
