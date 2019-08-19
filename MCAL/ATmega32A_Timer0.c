/*
 * ATmega32A_Timer0.c
 *
 * Created: 6/7/2019 11:02:06 AM
 *  Author: Hamdy
 */ 

#include "ATmega32A_timer0.h"

void Timer0_init(
					Timer0_CLKSource Clk,
					Timer0Modes TimerMode,
					Timer0_CompareModes CmpMode,
					Timer0_InterruptSettings IntSetting)
{
	TIMSK &=0xFC;
	TIMSK |= IntSetting;
	TCCR0 = Clk | CmpMode | TimerMode;
}


void Timer0_WaveGeneration_CTC(double F_Timer,float F_outSignal)
{
	GPIO_DirectionSet(GPIOB,PIN3,OUTPUT);
	
	OCR0 = (uint8)(F_Timer / (2 * F_outSignal)) - 0.5;
}



void Timer0_PWMGeneration(float DutyCycle, Timer0_CompareModes Mode)
{
	switch(Mode)
	{
		case T0_PWMFAST_NONINVERT :
									OCR0 = (uint8) (DutyCycle/100.0) * 255 + 0.5;
									break;
		case T0_PWMFAST_INVERT :
									OCR0 = (uint8)( ((100 - DutyCycle)/100.0) * 255 +0.5);
									break;
		default:
					break;
	}
}