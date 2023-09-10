/*
 * led.h
 *
 * Created: 8/24/2023 12:40:58 AM
 *  Author: HP
 */ 


#ifndef LED_H_
#define LED_H_
#include "../MCAL/DIO/dio.h"
#define LED_1_PORT PORT_A
#define LED_2_PORT PORT_A
#define LED_3_PORT PORT_A
#define LED_4_PORT PORT_A

#define LED_1_PIN PIN0
#define LED_2_PIN PIN3
#define LED_3_PIN PIN5
#define LED_4_PIN PIN7


typedef enum EN_ledError_t{
	LED_OK,LED_INVALID_PORT, LED_INVALID_PIN, LED_INVALID_INIT,LED_INVALID_VALUE
}EN_ledError_t;


EN_ledError_t LED_init(uint8_t ledPort,uint8_t ledPin);//initialising a LED
EN_ledError_t LED_on(uint8_t ledPort,uint8_t ledPin);//turning a led on
EN_ledError_t LED_off(uint8_t ledPort,uint8_t ledPin);//turning off a led
EN_ledError_t LED_toggle(uint8_t ledPort,uint8_t ledPin);//switching an on led to off or vice versa
EN_ledError_t LED_read(uint8_t ledPort,uint8_t ledPin,uint8_t* value); //read LED Status
//void LED_blink(uint8_t ledPortCar,uint8_t ledPinCar,uint8_t ledPortPed,uint8_t ledPinPed);//blinking 2 leds for a second

#endif /* LED_H_ */