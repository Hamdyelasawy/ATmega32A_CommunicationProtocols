/*
 * SPI.c
 *
 * Created: 6/14/2019 3:24:16 PM
 *  Author: Hamdy
 */ 
#include "SPI.h"
#include "ATmega32A_GPIO.h"
	void SPI_Init(void)
	{
		GPIO_DirectionSet(GPIOB,PIN5,OUTPUT);
		GPIO_DirectionSet(GPIOB,PIN7,OUTPUT);
		SPCR = (1<<6)| (1<<5) |(1<<4)|(1<<0);
	}
	void SPI_Write(uint8 Data)
	{
		SPDR = Data;
		/* Wait for transmission complete */
		while(!(SPSR & (1<<7)));
	}
	uint8 SPI_ReadBuffer(void)
	{
		while ((SPSR & (1<<7)) == 0){}
		return SPDR;
	}
	
	uint8 SPI_ExData(uint8 Data)
	{
		SPI_Write(Data);
		return SPI_ReadBuffer();
	}