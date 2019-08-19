/*
 * ATmega32A_timer0.h
 *
 * Created: 6/7/2019 11:02:20 AM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_TIMER0_H_
#define ATMEGA32A_TIMER0_H_

	#include "MACROSh.h"
	#include "ATmega32A_GPIO.h"
	#include "StandardTypes.h"
	#include "uc_Config.h"
	#include "Atmega32A_ExternalInterrupts.h"
	
#define TCCR0	(*(vuint8 *)0x53)
#define TCNT0	(*(vuint8 *)0x52)
#define OCR0	(*(vuint8 *)0x5C)
#define TIMSK	(*(vuint8 *)0x59)
#define TIFR	(*(vuint8 *)0x58)

#define FOC0	(7)
#define WGM00	(6)
#define WGM01	(3)
#define COM00	(4)
#define COM01	(5)
#define CS00	(0)
#define CS01	(1)
#define CS02	(2)


typedef enum
{
	T0_NORMALMODE=0x00,
	T0_CTCMODE=0x08,
	T0_PWMPHC=0x40,
	T0_PWMFAST=0x48,
}Timer0Modes;


typedef enum
{
	T0_OC0DISCONECT=0x00,
	T0_NONPWM_TOGGLEOC0=0x10,
	T0_NONPWM_CLEAROC0=0x20,
	T0_NONPWM_SETOC0=0x30,
	
	T0_PWMFAST_NONINVERT=0x20,
	T0_PWMFAST_INVERT=0x30,
	
	T0_PWMPHC_NONIVERT=0x30,
	T0_PWMPHC_INVERT = 0x20,
}Timer0_CompareModes;


typedef enum 
{
	TIMER0_DISABLE = 0x00,
	TIMER0_FCPU,
	TIMER0_FCPU_BY_8,
	TIMER0_FCPU_BY_64,
	TIMER0_FCPU_BY_256,
	TIMER0_FCPU_BY_1024,
	TIMER0_EXCLK_FALLING,
	TIMER0_EXCLK_RISING,
	}Timer0_CLKSource;

typedef enum 
{
	Timer0_Int_Disable=0x00,
	Timer0_OVF_ENABLE,
	Timer0_OCF_ENABLE,
	Timer0_OVF_OCF_ENABLE,
}Timer0_InterruptSettings;


void Timer0_init(
					Timer0_CLKSource Clk,
					Timer0Modes TimerMode,
					Timer0_CompareModes CmpMode,
					Timer0_InterruptSettings IntSetting);


void Timer0_WaveGeneration_CTC(double F_Timer,float F_outSignal);


void Timer0_PWMGeneration(float DutyCycle , Timer0_CompareModes Mode);
#endif /* ATMEGA32A_TIMER0_H_ */