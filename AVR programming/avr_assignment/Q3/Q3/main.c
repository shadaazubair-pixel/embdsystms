
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    DDRB|=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4)|(1<<DDB5)|(1<<DDB6)|(1<<DDB7);
	
    while (1) 
    {
		for(int i=0;i<8;i++){
			PORTB=(1<<i);
			_delay_ms(1000);
		}
		
	
}

	return 0;
}

