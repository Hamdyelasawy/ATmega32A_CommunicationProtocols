/*
 * Atmega32A_ExternalInterrupts.c
 *
 * Created: 5/10/2019 3:13:27 PM
 *  Author: Hamdy
 */ 


#include "Atmega32A_ExternalInterrupts.h"

	
	
	

	void ExternalInterrupt_Enable(externalIntControl Sel,externalINTmode Mode)
	{
		/* critical Section */
		GL_INTERRUPT_DISABLE();
		
			switch(Sel)
			{
				case EXTINT0:
										MCUCR = (MCUCR & 0xFC) | Mode;
										
										break;
				case EXTINT1:
										MCUCR = (MCUCR & 0xF3) | Mode;
										
										break;
				case EXTINT2:
										MCUCSR = (MCUCSR & 0xBF) | Mode;
										
										break;
				default:
										return;
										
			}
		GICR |= Sel;
		GL_INTERRUPT_ENABLE();
	}
	
	void ExternalInterrupt_Disable(externalIntControl Sel)
	{
		GICR &= ~ ( Sel);
	}