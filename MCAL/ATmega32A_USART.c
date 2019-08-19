/*
 * ATmega32A_USART.c
 *
 * Created: 6/14/2019 11:39:23 AM
 *  Author: Hamdy
 */ 
#include "ATmega32A_USART.h"
void	USART_Init(uint32 BaudRate)
{
	//UBRR((F_CPU / (8*BaudRate))-1);
	UBRRL = 12;
	UBRRH = 0;
	UCSRA = (1<<1);
	UCSRB = (1<<3) | (1<<4) ;
	UCSRC = (1<<7) | (1<<2);
}

void	USART_SendByte(uint8 Data)
{ 
	// Poll Buffer Empty  udre
	while( (UCSRA & (1<<5)) == 0){}
	UDR = Data;
	
	#if 0
		UDR = Data;
		while((UCSRA & (1<<6) )== 0 ){}
		UCSRA |= (1<<6);
	#endif
		
}

uint8	USART_RcvByte(void)
{
	while((UCSRA & (1<<7)) == 0){}
	return UDR;
}