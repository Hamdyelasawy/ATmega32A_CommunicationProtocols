/*
 * SPI.h
 *
 * Created: 6/14/2019 3:24:30 PM
 *  Author: Hamdy
 */ 


#ifndef SPI_H_
#define SPI_H_

	#include "uc_Config.h"
	#include "StandardTypes.h"
	#include "MACROSh.h"
	
	#define DUMMY_DATA	(0x00)
	#define SPSR		(*(vuint8*)0x2E)
	#define SPCR		(*(vuint8*)0x2D)
	#define SPDR		(*(vuint8*)0x2F)

	void SPI_Init(void);
	void SPI_Write(uint8 Data);
	uint8 SPI_ReadBuffer(void);
	uint8 SPI_ExData(uint8 Data);
#endif /* SPI_H_ */