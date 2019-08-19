/*
 * ATmega32A_USART.h
 *
 * Created: 6/14/2019 11:39:32 AM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_USART_H_
#define ATMEGA32A_USART_H_

	#include "StandardTypes.h"
	#include "uc_Config.h"
	#include "MACROSh.h"
	
	#define UDR			(*(vuint8*)0x2c)
	#define UBRRH		(*(vuint8*)0x40)
	#define UBRRL		(*(vuint8*)0x29)		
	#define UCSRA		(*(vuint8*)0x2b)
	#define UCSRB		(*(vuint8*)0x2a)
	#define UCSRC		(*(vuint8*)0x40)

	#define UBRR(DATA)	do {\
							UBRRL = (uint8)(DATA);\
							UBRRH = ((DATA) >> 8) & 0x03;\
						    }while (0);
						

void	USART_Init(uint32 BaudRate);
void	USART_SendByte(uint8 Data);
uint8	USART_RcvByte(void);

#endif /* ATMEGA32A_USART_H_ */