/*
 * stm32f401xx_spi_driver.h
 *
 *  Created on: Mar 2, 2026
 *      Author: user
 */

#ifndef INC_STM32F401XX_SPI_DRIVER_H_
#define INC_STM32F401XX_SPI_DRIVER_H_

#include "stm32f401xx.h"

/* configuration structure for SPIx peripheral*/


typedef struct{
	//complete structure
	// device mode
	// SPI BUS CONFIG
	//SCLK SPEED
	//DFT
	//CFOL
	//CPHA
	//SSM

}SPI_Config_t;

typedef struct{
	SPI_RegDef_t *pSPIx;   //pointer to spi base address
	SPI_Config_t SPI_PinConfig; //pin configuration settings

};


#endif /* INC_STM32F401XX_SPI_DRIVER_H_ */
