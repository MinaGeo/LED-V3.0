/*
 * application.h
 *
 * Created: 8/24/2023 1:51:41 AM
 *  Author: HP
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_



#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"

typedef enum EN_appError_t{
	APP_OK, APP_LED_ERROR, APP_BTN_ERROR,APP_INT_ERROR,APP_ERROR_EXIT
}EN_appError_t;

EN_appError_t APP_init(void);
EN_appError_t APP_start(void);

EN_appError_t BLINK_1(void); //(ON: 100ms, OFF: 900ms)
EN_appError_t BLINK_2(void); //ON: 200ms, OFF: 800ms
EN_appError_t BLINK_3(void); //ON: 300ms, OFF: 700ms
EN_appError_t BLINK_4(void);//ON: 500ms, OFF: 500ms
EN_appError_t BLINK_5(void);//ON: 800ms, OFF: 200ms

//this function is used to setup the lEDs so that it undergoes blinking (toggling)
EN_appError_t blinkSetup(void); 


void test_app(void);
#endif /* APPLICATION_H_ */