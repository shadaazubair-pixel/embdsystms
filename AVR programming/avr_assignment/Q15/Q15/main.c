#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>
#include "i2c.h"
#include "oled.h"
#include "bmp280.h"
#include "config.h"

char tempBuffer[20];
char pressBuffer[20];

int main(void)
{
	float temperature;
	float pressure;

	I2C_Init();
	OLED_Init();
	OLED_Clear();
	BMP280_Init();

	while(1)
	{
		temperature = BMP280_ReadTemperature();
		pressure = BMP280_ReadPressure();
		dtostrf(temperature,5,2,tempBuffer);
		dtostrf(pressure,6,2,pressBuffer);
		
		// Temperature
		OLED_SetCursor(2,4);
		OLED_String("Temperature:");
		OLED_SetCursor(3,4);
		OLED_String(tempBuffer);
		OLED_String(" C");
		
		// Pressure
		OLED_SetCursor(6,4);
		OLED_String("Pressure:");
		OLED_SetCursor(7,4);
		OLED_String(pressBuffer);
		OLED_String(" hPa");

		_delay_ms(2000);
	}
}
