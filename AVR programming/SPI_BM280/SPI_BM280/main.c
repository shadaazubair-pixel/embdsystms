#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"


int main(void)
{
	UART_Init();
	uint8_t chip_id,MSB,LSB,XLSB,T1_L,T1_U,T2_L,T2_U,T3_U,T3_L;
	uint16_t dig_T1,dig_T2;
	int dig_T3,T_new,T_int,T_frac;
	float var1,var2,t_fine,T;
	uint32_t temp;
    DDRB|=(1<<DDB3)|(1<<DDB5)|(1<<DDB2); //MOSI, SCK.CSB are configured as output
	DDRB&=~(1<<DDB4);  //config MISO as input
	
	SPCR|=((1<<SPE)|(1<<MSTR)|(1<<SPR0)); // Enable spi and select master
	SPCR&=~((1<<SPR1)|(1<<CPOL)|(1<<CPHA));       // set clock to 1mhz
	
	
    while (1) 
    {
		PORTB&=~(1<<PB2);  //selecting slave
		SPDR=(0XD0|0X80); //ensuring 1 on MSB(reading)
		while(!(SPSR&(1<<SPIF))); //wait till flag set
		(void)SPDR; //reading SPDR to reset flag(garbage value)
		
		SPDR=0X00; //sending dummy to read value from BMP280
		while(!(SPSR&(1<<SPIF)));   //wait till flag is set
		chip_id=SPDR; //reading chip_id
		UART_TxHex(chip_id);
		_delay_ms(1000);
		PORTB|=(1<<PB2);  //deselecting slave,
		
		
		//enabling measurement by writing 0X27 to 0XF4 register of BMP280
		PORTB&=~(1<<PB2); //selecting slave
		SPDR=(0XF4&0X7F); // Ensuring 0 on MSB for writing
		while(!(SPSR&(1<<SPIF))); //wait for flag to set
		(void)SPDR; //dummy reading
		
		SPDR=0X27;  //writing to F4 to BMP280
		while(!(SPSR&(1<<SPIF)));
		(void)SPDR;
		PORTB|=(1<<PB2); //deselcting slave
		
		
		
		PORTB&=~(1<<PB2); //selecting slave
		SPDR=(0XFA|0X80);  //ensuring 1 ON MSB for reading
		while(!(SPSR&(1<<SPIF))); //wait till flag set
		(void)SPDR;
		
		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		MSB=SPDR; //read MSB
		
		
		
		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		LSB=SPDR;
		
		

		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		XLSB=SPDR;
		
		temp=((uint32_t)MSB<<12|(uint32_t )LSB<<4|(uint32_t)XLSB>>4); 
		PORTB|=(1<<PB2);
		
		
		//Reading tempereture compensation values
		PORTB&=~(1<<PB2); //selecting slave
		SPDR=(0X88|0X80);  //ensuring 1 ON MSB for reading
		while(!(SPSR&(1<<SPIF))); //wait till flag set
		(void)SPDR;
		
		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		T1_L=SPDR; //read MSB
		
		
		
		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		T1_U=SPDR;
		
		

		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		T2_L=SPDR;
		
		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		T2_U=SPDR; //read MSB
		
		
		
		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		T3_L=SPDR;
		
		

		SPDR=0X00;
		while(!(SPSR&(1<<SPIF)));
		T3_U=SPDR;
		PORTB|=(1<<PB2);
		
		
		
		dig_T1=((uint16_t)T1_U<<8)|T1_L;
		dig_T2=((uint16_t)T2_U<<8)|T2_L;
		dig_T3=((uint16_t)T3_U<<8)|T3_L;
		
		var1=((temp/16384.0f))-((dig_T1/1024.0f))*dig_T2;
		var2=((temp/131072.0f))-((dig_T2/8192.0f))*dig_T3;
		
		
		t_fine=var1+var2;
		T=t_fine/5120.0f;
		
		T_new=T*100;
		T_int=T_new/100;
		T_frac=T_new%100;
		
		UART_TxNumber(T_int);
		UART_TxChar('.');
		
		if(T_frac<10){
			UART_TxChar('0');
		}
	UART_TxNumber(T_frac);
	UART_TxChar('\n');
		
		
		
		
		
		
		
		
		//UART_TxNumber(T);
		
		_delay_ms(1000);
		
	
		
		
		/*UART_TxNumber(dig_T2);
		UART_TxChar('\n');
		
		UART_TxNumber(dig_T3);
		UART_TxChar('\n');
		
		_delay_ms(1000);
		PORTB|=(1<<PB2);*/
		
		
		
		
    }
}

