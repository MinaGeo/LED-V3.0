/*
 * interrupts.c
 *
 * Created: 8/30/2023 2:38:13 PM
 *  Author: HP
 */ 
#include "interrupts.h"

static void (*INT0_CallBack_ptr) (void)=NULLPTR;
static void (*INT1_CallBack_ptr) (void)=NULLPTR;

void enable_external_interrupt0 (void)
{
  //GICR |= (1<<6);
  
  SET_BIT_v(GICR,6);
  
}
void enable_external_interrupt1 (void)
{
	SET_BIT_v(GICR,7);
}

void enable_external_interrupts(uint8_t interrupt)
{
	
	
	
	
	
}

void extInt0_rising(void)
{

  MCUCR |= (1<<0) | (1<<1);
		
}
void extInt1_rising(void)
{

	MCUCR |= (1 << ISC11);  
	MCUCR |= (1 << ISC10);
	
}

// Enable global interrupts
void enable_Global_interrupt(void)
{
	sei();
	
}
// Disable global interrupts
void disable_Global_interrupt(void)
{
	
	cli();
}

//Callback functions
void EXI0_SetCallBack(void(*LocalPtr)(void))
{
	INT0_CallBack_ptr=LocalPtr;
}

/************************************Call back functions*********************************************/
void EXI1_SetCallBack(void(*LocalPtr)(void))
{
	INT1_CallBack_ptr=LocalPtr;
}

//ISR functions for EXI0, and EXI1
ISR(EXT_INT_0)
{
	if (INT0_CallBack_ptr!=NULLPTR)
	{
		INT0_CallBack_ptr();
	}
}
ISR(EXT_INT_1)
{
	if (INT1_CallBack_ptr!=NULLPTR)
	{
		INT1_CallBack_ptr();
	}
}