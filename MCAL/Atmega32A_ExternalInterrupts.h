/*
 * Atmega32A_ExternalInterrupts.h
 *
 * Created: 5/10/2019 3:13:36 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_EXTERNALINTERRUPTS_H_
#define ATMEGA32A_EXTERNALINTERRUPTS_H_

	#include "ATmega32A_GPIO.h"
	#include "StandardTypes.h"
	#include "uc_Config.h"
	#include "MACROSh.h"
	#include <avr/interrupt.h>
	
	#define MCUCR		(*(vuint8 *)(0x55))
	#define MCUCSR		(*(vuint8 *)(0x54))
	#define GIFR		(*(vuint8 *)(0x5A))
	#define GICR		(*(vuint8 *)(0x5B))
	#define SREG		(*(vuint8 *)(0x5F))
	
	#define GL_INTERRUPT_ENABLE()	(SETBIT(SREG,7))
	#define GL_INTERRUPT_DISABLE()	(CLEARBIT(SREG,7))
	
	typedef enum
	{
		EXTINT0_LOWLVL=0x00,
		EXTINT0_LOGCHANGE=0x01,
		EXTINT0_FALLING=0x02,
		EXTINT0_RISING=0x03,
		EXTINT1_LOWLVL=0x00,
		EXTINT1_LOGCHANGE=0x04,
		EXTINT1_FALLING=0x08,
		EXTINT1_RISING=0x0C,
		EXTINT2_FALLING=0x00,
		EXTINT2_RISING=0x40,
	}externalINTmode;
	
	
	typedef enum
	{
		EXTINT0=0x40,
		EXTINT1=0x80,
		EXTINT2=0x20,
	}externalIntControl;
	
	
	void ExternalInterrupt_Enable(
									externalIntControl Sel,
									externalINTmode Mode);
									
	void ExternalInterrupt_Disable(externalIntControl Sel);					
	
#endif /* ATMEGA32A_EXTERNALINTERRUPTS_H_ */