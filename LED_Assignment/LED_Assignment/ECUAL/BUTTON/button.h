/*
 * button.h
 *
 * Created: 8/24/2023 2:49:36 AM
 *  Author: HP
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN2

#define BUTTON_2_PORT PORT_D
#define BUTTON_2_PIN PIN3

#include "../MCAL/DIO/dio.h"

typedef enum EN_btnError_t{
	BTN_OK,BTN_INVALID_PORT, BTN_INVALID_PIN, BTN_INVALID_INIT,BTN_INVALID_VALUE
}EN_btnError_t;

EN_btnError_t BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);//initializing a button
EN_btnError_t BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t* value);//reading the value of a button


#endif /* BUTTON_H_ */