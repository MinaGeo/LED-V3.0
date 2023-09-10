/*
 * application.c
 *
 * Created: 8/24/2023 1:51:49 AM
 *  Author: HP
 */
#include "application.h"

int currentLed = 0;
int currentBlink = CASE1;


uint8_t buttonState = LOW;
uint8_t ledState = LOW;

uint8_t led_pin_tst = LED_1_PIN;
uint8_t btn_pin_tst = BUTTON_1_PIN;
uint8_t timer_mode_tst = timer0_normal_mode;
static void callback_exti0 (void);
static void callback_exti1 (void);
//
EN_appError_t APP_init(void) {
  if (LED_init(LED_1_PORT, led_pin_tst) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_2_PORT, LED_2_PIN) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_3_PORT, LED_3_PIN) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_4_PORT, LED_4_PIN) != LED_OK) {
    return APP_LED_ERROR;
  } else if (BUTTON_init(BUTTON_1_PORT, btn_pin_tst) != BTN_OK) {
    return APP_BTN_ERROR;
  } else if (BUTTON_init(BUTTON_2_PORT, BUTTON_2_PIN) != BTN_OK) {
    return APP_BTN_ERROR;
  } else {

    /* Enabling global interrupts */
    enable_Global_interrupt();
    /* Choose the external interrupt 0 sense - sense on rising edge */
    extInt0_rising();
	/* Choose the external interrupt 1 sense - sense on rising edge */
	extInt1_rising();
    /*enable external interrupt 0- INT0 */
    enable_external_interrupt0();
    /*enable external interrupt 1- INT1 */
	enable_external_interrupt1();

	
    //2. Choose timer mode (Normal mode)
   if(timer0_mode(timer_mode_tst) != TIMER_OK){
   return APP_ERROR_EXIT;
   }
    // Timer set initial value
    timer0_set_initial();
EXI1_SetCallBack(&callback_exti1);
EXI0_SetCallBack(&callback_exti0);
    return APP_OK;
  }

}

EN_appError_t APP_start(void) {

  while (1) {
    switch (currentBlink) {
    case CASE1:
     if(BLINK_1()!=APP_OK){
	 return APP_ERROR_EXIT;
	 }
	 break;
	case CASE2:
	if(BLINK_2()!=APP_OK){
		return APP_ERROR_EXIT;
	}
	 break;
	 case CASE3:
	if(BLINK_3()!=APP_OK){
		return APP_ERROR_EXIT;
	}
	 break;
	 case CASE4:
	if(BLINK_4()!=APP_OK){
		return APP_ERROR_EXIT;
	}
	 break;
	 case CASE5:
	if(BLINK_5()!=APP_OK){
		return APP_ERROR_EXIT;
	}
	 break;
    default:
      // Do nothing
      break;

    }
    //}
  }

}


EN_appError_t BLINK_1(void) {
if(blinkSetup()!= APP_OK)
{
	return APP_ERROR_EXIT;
}
			if(timer_delay(BLINK1_ON) != TIMER_OK)
			{
				return APP_ERROR_EXIT;
			}
				if(LED_off(LED_1_PORT, LED_1_PIN)!= LED_OK){
					return APP_LED_ERROR;
					
				}
				if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
					return APP_LED_ERROR;
					
				}
			if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
				return APP_LED_ERROR;
			}
			if(timer_delay(BLINK1_OFF) != TIMER_OK)
			{
				return APP_ERROR_EXIT;
			}
return APP_OK;
}

EN_appError_t BLINK_2(void) {
if(blinkSetup()!= APP_OK)
{
	return APP_ERROR_EXIT;
}
	if(timer_delay(BLINK2_ON) != TIMER_OK)
	{
		return APP_ERROR_EXIT;
	}
			if(LED_off(LED_1_PORT, LED_1_PIN)!= LED_OK){
					return APP_LED_ERROR;
					
				}
				if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
					return APP_LED_ERROR;
					
				}
			if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
				return APP_LED_ERROR;
			}
	if(timer_delay(BLINK2_OFF) != TIMER_OK)
	{
		return APP_ERROR_EXIT;
	}
return APP_OK;

}
EN_appError_t BLINK_3(void) {
	if(blinkSetup()!= APP_OK)
	{
		return APP_ERROR_EXIT;
	}
if(timer_delay(BLINK3_ON) != TIMER_OK)
{
	return APP_ERROR_EXIT;
}
		if(LED_off(LED_1_PORT, LED_1_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
		}
		if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
		}
		if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
		}
		if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
			return APP_LED_ERROR;
		}
	if(timer_delay(BLINK3_OFF) != TIMER_OK)
	{
		return APP_ERROR_EXIT;
	}
return APP_OK;

}

EN_appError_t BLINK_4(void) {
	if(blinkSetup()!= APP_OK)
	{
		return APP_ERROR_EXIT;
	}
	if(timer_delay(BLINK4_ON) != TIMER_OK)
	{
		return APP_ERROR_EXIT;
	}
			if(LED_off(LED_1_PORT, LED_1_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
				return APP_LED_ERROR;
			}
	if(timer_delay(BLINK4_OFF) != TIMER_OK)
	{
		return APP_ERROR_EXIT;
	}
return APP_OK;

}

EN_appError_t BLINK_5(void) {
	
	if(blinkSetup()!= APP_OK)
	{
		return APP_ERROR_EXIT;
	}
	
	if(timer_delay(BLINK5_ON) != TIMER_OK)
	{
		return APP_ERROR_EXIT;
	}
			if(LED_off(LED_1_PORT, LED_1_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
				return APP_LED_ERROR;
				
			}
			if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
				return APP_LED_ERROR;
			}
	if(timer_delay(BLINK5_OFF) != TIMER_OK)
	{
		return APP_ERROR_EXIT;
	}
return APP_OK;

}




void callback_exti0 (void)
{
	
	if (currentLed < NUMBER_OF_CASES) {
		currentLed++;
		} else {
		currentLed = CASE1;
	}
}
void callback_exti1 (void)
{
	
	if (currentBlink < NUMBER_OF_BLINKS) {
		currentBlink++;
		} else {
		currentBlink = CASE1;
	}
}


void test_app(void) {

	/* initializing test cases */
	/* test case 1.. returns APP_LED_ERROR */
	led_pin_tst = testFail;
	APP_init();

	/* test case 2.. returns APP_BTN_ERROR */
	led_pin_tst = LED_1_PIN;
	btn_pin_tst = testFail;
	APP_init();
	btn_pin_tst = BUTTON_1_PIN;
	
		/* test case 3.. returns APP_ERROR_EXIT */
		led_pin_tst = LED_1_PIN;
		btn_pin_tst = BUTTON_1_PIN;
		timer_mode_tst = testFail;
		APP_init();
		timer_mode_tst = timer0_normal_mode;

	/* APP_start test cases   */
	/* test case 4.. returns APP_ERROR_EXIT*/
	APP_init();
	led_pin_tst = testFail;
	APP_start();
	led_pin_tst = LED_1_PIN;
	
	
	/*test case 5 [HAPPY Case scenario]*/
		timer_mode_tst = timer0_normal_mode;
	
	led_pin_tst = LED_1_PIN;
	btn_pin_tst = BUTTON_1_PIN;
	APP_init();
	APP_start();

}

EN_appError_t blinkSetup(void)
{
	switch (currentLed)
	{
		case CASE0:
		if(LED_off(LED_1_PORT, led_pin_tst)!=LED_OK){
			return APP_LED_ERROR;
		}
		else if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
		}
		else if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
			}else if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
			return APP_LED_ERROR;
		}
		
		
		break;
		case CASE1:
		if(LED_on(LED_1_PORT, LED_1_PIN)!= LED_OK)
		{
			return APP_LED_ERROR;
		}
		break;
		
		case CASE2:
		if(LED_on(LED_1_PORT, LED_1_PIN)!= LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_2_PORT, LED_2_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		break;
		
		case CASE3:
		if(LED_on(LED_1_PORT, LED_1_PIN)!= LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_2_PORT, LED_2_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_3_PORT, LED_3_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		break;
		
		case CASE4:
		if(LED_on(LED_1_PORT, LED_1_PIN)!= LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_2_PORT, LED_2_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_3_PORT, LED_3_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_4_PORT, LED_4_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		break;
		case CASE5:
		if(LED_off(LED_1_PORT, LED_1_PIN)!=LED_OK){
			return APP_LED_ERROR;
		}
		if(LED_on(LED_2_PORT, LED_2_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_3_PORT, LED_3_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_4_PORT, LED_4_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		break;
		case CASE6:
		
		if(LED_on(LED_3_PORT, LED_3_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_on(LED_4_PORT, LED_4_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_off(LED_2_PORT, LED_2_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
		}
		break;
		case CASE7:
		
		if(LED_on(LED_4_PORT, LED_4_PIN) != LED_OK)
		{
			return APP_LED_ERROR;
		}
		if(LED_off(LED_3_PORT, LED_3_PIN)!= LED_OK){
			return APP_LED_ERROR;
			
		}
		break;
		
		case CASE8:
		if(LED_off(LED_4_PORT, LED_4_PIN)!= LED_OK){
			return APP_LED_ERROR;
		}
		break;
		default:
		return APP_OK;
		// Do nothing
		break;
		
	}
		return APP_OK;
		
	
}