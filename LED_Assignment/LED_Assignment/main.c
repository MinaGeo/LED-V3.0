/*
 * My first project.c
 * write high on pin 0 on port A
 * Created: 8/23/2023 5:57:40 PM
 * Author : HP
 */ 


#include "./Application/application.h"


//int main(void)
//{
	//
	//unsigned int overFlowCounter = 0;
	////1. LED Init
	//LED_init(LED_1_PORT,LED_1_PIN);
	////2. Choose timer mode
	//TCCR0 = 0x00;//Normal mode
	//// Timer set initial value
	//TCNT0 = 0x00;
//
	//
	//while(1)
	//{
		////2. LED toggle
		//LED_toggle(LED_1_PORT,LED_1_PIN);	// call and return -> time therefore 315 ms
		////3. Delay 512ms
		//
			////Timer start -> setting the clock source
			//TCCR0 |= (1<<0); // No Prescalar
			//while(overFlowCounter < NUMBER_OF_OVERFLOWS)
			//{
				////will be repeated 2000
				////stop after one overflow -> 256 ms
				//// wait until the overflow flag to be set 1
				//while((TIFR & (1<<0)) == 0); //busy wait
				//
				//// clear the overflow flag
				//TIFR |= (1<<0);
				//
				//overFlowCounter++;
			//}
				//overFlowCounter= 0;
				//
			//
			//
			//
			////Timer stop
			//TCCR0 = 0x00;
			//
			//
	//}
		//
//}




int main(void)
{
	
	//test_dio();
	//test_app();
	
	
	APP_init();
	
	APP_start();
	
}


