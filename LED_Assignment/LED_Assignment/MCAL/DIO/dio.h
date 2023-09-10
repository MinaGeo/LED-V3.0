/*
 * dio.h
 *
 * Created: 8/23/2023 9:48:13 PM
 *  Author: HP
 */ 


#ifndef DIO_H_
#define DIO_H_
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../MCAL/Interrupts/interrupts.h"
#include "../MCAL/Timer/timer.h"
#include "../Utitlities/registers.h"

//defining ports
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//defining pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



//Direction Macros
#define IN 0
#define OUT 1
//Value Macros
#define LOW 0
#define HIGH 1

// all internal driver typedefs
//all driver macros
// all driver function prototypes
typedef enum EN_dioError_t{
	DIO_OK, DIO_INVALID_PORT, DIO_INVALID_PIN, DIO_INVALID_INIT,DIO_INVALID_VALUE
}EN_dioError_t;



EN_dioError_t  DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // initilaize dio direction
EN_dioError_t  DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value); // write data to dio
EN_dioError_t  DIO_toggle(uint8_t portNumber,uint8_t pinNumber); // toggle dio
EN_dioError_t  DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t* value);// read dio


void test_dio(void);
#endif /* DIO_H_ */