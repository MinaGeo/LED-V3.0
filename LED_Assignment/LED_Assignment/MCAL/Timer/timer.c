/*
 * timer.c
 *
 * Created: 9/5/2023 6:01:10 PM
 *  Author: HP
 */ 

#include "timer.h"

EN_TimerError_t timer0_mode(uint8_t mode)
{
	
	if(mode == 0) //Normal mode
	{
		 TCCR0 &= ~(1<<WGM00);
		 TCCR0 &= ~(1<<WGM01);
		 return TIMER_OK;
	}
	else if(mode ==1) //CTC mode
	{
		 TCCR0 &= ~(1<<WGM00);
		 TCCR0 |=(1<<WGM01);
		 return TIMER_OK;
		 
	}
	else if(mode ==2) //PWM mode
	{
		 TCCR0  |=(1<<WGM00);
		 TCCR0 &= ~(1<<WGM01);
		 return TIMER_OK;
		 
	}
	else if(mode ==3) //FAST PWM mode
	{
		TCCR0 |=(1<<WGM00);
		TCCR0 |=(1<<WGM01);
		 return TIMER_OK;
		 
	}
	else
	{
				 return TIMER_INVALID_MODE;

	}
	
	
}



void timer0_set_initial(void){
	
	  	TCNT0 = 0x00;
}


EN_TimerError_t timer0_prescalar(uint8_t prescalar)
{
	
	
		
		if(prescalar == 0) //Timer stop
		{
			TCCR0 &= ~(1 << CS00);  // Set bit CS00 to 0
			TCCR0 &= ~(1 << CS01); // Clear bit CS01 to 0
			TCCR0 &= ~(1 << CS02); // Clear bit CS02 to 0
		  return TIMER_OK;
		  

		}
		else if(prescalar ==1) // No prescalling
		{
			TCCR0 |= (1 << CS00);  // Set bit CS00 to 1
			TCCR0 &= ~(1 << CS01); // Clear bit CS01 to 0
			TCCR0 &= ~(1 << CS02); // Clear bit CS02 to 0
		  return TIMER_OK;
		  

		}
		else if(prescalar ==2) //Prescalar of 8 
		{
				TCCR0 &= ~(1 << CS00);  // Set bit CS00 to 0
				TCCR0 |= (1 << CS01); // Clear bit CS01 to 1
				TCCR0 &= ~(1 << CS02); // Clear bit CS02 to 0
		  return TIMER_OK;
		  

		}
		else if(prescalar ==3) //Prescalar of 64
		{
			TCCR0 |= (1 << CS00);  // Set bit CS00 to 1
			TCCR0 |= (1 << CS01); // Clear bit CS01 to 1
			TCCR0 &= ~(1 << CS02); // Clear bit CS02 to 0
		  return TIMER_OK;
		  

		}
		else if(prescalar ==4) //Prescalar of 256
		{
			TCCR0 &= ~(1 << CS00);  // Set bit CS00 to 0
			TCCR0 &= ~(1 << CS01); // Clear bit CS01 to 0
			TCCR0 |= (1 << CS02); // Clear bit CS02 to 1
		  return TIMER_OK;
		  
		}
		else if(prescalar ==5) //Prescalar of 1024
		{
			TCCR0 |= (1 << CS00);  // Set bit CS00 to 1
			TCCR0 &= ~(1 << CS01); // Clear bit CS01 to 0
			TCCR0 |= (1 << CS02); // Clear bit CS02 to 1
		  return TIMER_OK;
		  
		}
		else if(prescalar ==6) //External clock source on T0 pin. Clock on falling edge
		{
			TCCR0 &= ~(1 << CS00);  // Set bit CS00 to 0
			TCCR0 |= (1 << CS01); // Clear bit CS01 to 1
			TCCR0 |= (1 << CS02); // Clear bit CS02 to 1
		  return TIMER_OK;
		  
		}
		else if(prescalar ==7) //External clock source on T0 pin. Clock on rising edge.
		{
			TCCR0 |= (1 << CS00);  // Set bit CS00 to 0
			TCCR0 |= (1 << CS01); // Clear bit CS01 to 0
			TCCR0 |= (1 << CS02); // Clear bit CS02 to 0
		  return TIMER_OK;
		  
		}	
			
		else
		{
			//do nothing
			return TIMER_INVALID_PRESCALAR;
		}
	
	
}


EN_TimerError_t timer_delay(uint16_t timeDelay)
{
	uint16_t overFlowCounter = 0;
	uint16_t numberOfOverflows = 4*timeDelay;
	//Delay 
	//Timer start -> setting the clock source
	
	if(timer0_prescalar(TIMER0_NO_PRESCALLING) != TIMER_OK)
	{
		return TIMER_INVALID_DELAY;
		} // No Prescalar
	while(overFlowCounter < numberOfOverflows)
	{
		// wait until the overflow flag to be set 1
		while((TIFR & (1<<0)) == 0); //busy wait
		
		// clear the overflow flag
		timer_clrOF_Flag();
		overFlowCounter++;
	}
	overFlowCounter= 0;
	
	//Timer stop
	timer_stop();
	
	return TIMER_OK;
}
void timer_stop(void)
{
	TCCR0= 0x00;
	
	
}
void timer_clrOF_Flag(void)
{
		TIFR |= (1<<0);
}

