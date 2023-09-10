/*
 * dio.c
 *
 * Created: 8/23/2023 9:48:04 PM
 *  Author: HP
 */ 
// include .h
// global variables 
// function definitions
#include "dio.h"


void CLEAR_BIT(uint8_t portNumber,uint8_t pinNumber){
	switch(portNumber){
		case PORT_A:{
			DDRA&=~(1<<pinNumber);
			break;
		}
		
		case PORT_B:{
			DDRB&=~(1<<pinNumber);
			break;
		}
		case PORT_C:{
			DDRC&=~(1<<pinNumber);
			break;
		}
		case PORT_D:{
			DDRD&=~(1<<pinNumber);
			break;
		}
	}
}
void SET_BIT(uint8_t portNumber,uint8_t pinNumber){
		switch(portNumber){
			case PORT_A:{
				DDRA|=(1<<pinNumber);
				break;
			}
			
			case PORT_B:{
				DDRB|=(1<<pinNumber);
				break;
			}
			case PORT_C:{
				DDRC|=(1<<pinNumber);
				break;
			}
			case PORT_D:{
				DDRD|=(1<<pinNumber);
				break;
			}
		}
	}

EN_dioError_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction)
{
		if(pinNumber>7||pinNumber<0)
		{
		return DIO_INVALID_PIN;
		}
		
	switch(portNumber){
		case PORT_A:
		{
			if(direction == IN){
				CLEAR_BIT(portNumber,pinNumber);
				return DIO_OK;
			}
			else if(direction == OUT){
				SET_BIT(portNumber,pinNumber);
				return DIO_OK;
			}
			else{
				return DIO_INVALID_INIT;
			}
			break;
		}
		
		case PORT_B:
		{
			if(direction==IN){
				CLEAR_BIT(portNumber,pinNumber);
				        return DIO_OK;
				        
			}
			else if(direction==OUT){
				SET_BIT(portNumber,pinNumber);
				        return DIO_OK;
				        
			}
			else{
				return DIO_INVALID_INIT;
			}
			break;
		}
		
		case PORT_C:
		{
			if(direction==IN){
				CLEAR_BIT(portNumber,pinNumber);
				        return DIO_OK;
				        
			}
			else if(direction==OUT){
				SET_BIT(portNumber,pinNumber);
				        return DIO_OK;
				        
			}
			else{
				return DIO_INVALID_INIT;
			}
			break;
		}
		
		case PORT_D:
		{
			if(direction==IN){
				CLEAR_BIT(portNumber,pinNumber);
				return DIO_OK;
			}
			else if(direction==OUT){
				SET_BIT(portNumber,pinNumber);
				        return DIO_OK;
			}
			else{
				return DIO_INVALID_INIT;
			}
			break;
		}
		default:{
			return DIO_INVALID_PORT;
		}	
	}
			return DIO_INVALID_PORT;
			
}

EN_dioError_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value){
	if(pinNumber>7||pinNumber<0)
	{
		return DIO_INVALID_PIN;

	}
	switch(portNumber)
	{
		case PORT_A:{
			if(value==LOW){
				PORTA&=~(1<<pinNumber); 
			 return DIO_OK;
			}
			else if(value==HIGH){
				PORTA|=(1<<pinNumber);
			 return DIO_OK;
			 
			}
			else{
				return DIO_INVALID_VALUE;
			}
			break;
		}
		
		case PORT_B:{
			if(value==LOW){
				PORTB&=~(1<<pinNumber);
			 return DIO_OK;
			 
			}
			else if(value==HIGH){
				PORTB|=(1<<pinNumber);
			 return DIO_OK;
			 
			}
			else{
				return DIO_INVALID_VALUE;

			}
			break;
		}
		
		case PORT_C:{
			if(value==LOW){
				PORTC&=~(1<<pinNumber);
			 return DIO_OK;
			 
			}
			else if(value==HIGH){
				PORTC|=(1<<pinNumber);
			 return DIO_OK;
			 
			}
			else{
				return DIO_INVALID_VALUE;

			}
			break;
		}
		
		case PORT_D:{
			if(value == LOW)
			{
				PORTD&=~(1<<pinNumber);
			 return DIO_OK;
			 
			}
			else if(value == HIGH)
			{
			PORTD|=(1<<pinNumber);
			return DIO_OK;
			}
			else{
				return DIO_INVALID_VALUE;
			}
			break;
		}
		default:{
			return DIO_INVALID_PORT;
		}
	}
}

EN_dioError_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t* value){

		if(pinNumber>7||pinNumber<0)
		{
			return DIO_INVALID_PIN;

		}
	switch(portNumber){
		case PORT_A:{
			*value= (PINA & (1<<pinNumber)) >> pinNumber;
			return DIO_OK;
		}
		case PORT_B:{
			*value= (PINB & (1<<pinNumber)) >> pinNumber;
			return DIO_OK;
			
		}
		case PORT_C:{
			*value= (PINC & (1<<pinNumber)) >> pinNumber;
			return DIO_OK;
			
		}
		case PORT_D:{
			*value= (PIND & (1<<pinNumber)) >> pinNumber;
			return DIO_OK;
			
		}
		default:{
			return DIO_INVALID_PORT;
		}
	}
}

void test_dio(void)
{
	/* test case 1.. returns DIO_INVALID_PIN */
	DIO_init(PORT_A, 10,OUT);
	
	/* test case 2.. returns DIO_INVALID_PORT */
	DIO_init('E', PIN1,OUT);
	
	/* test case 3.. returns DIO_INVALID_INIT*/
	DIO_init(PORT_A, PIN1,3); //not OUT or IN
	
	/* test case 4.. returns DIO_INVALID_VALUE*/
	DIO_init(PORT_A, PIN1, OUT);
	DIO_write(PORT_A, PIN1, 3); // Not HIGH or LOW
	
	/* test case 5.. returns DIO_OK [HAPPY CASE SCENARIO]*/
	DIO_init(PORT_A, PIN1, OUT);
	DIO_write(PORT_A, PIN1, HIGH);
	uint8_t value;
	DIO_read(PORT_A, PIN1, &value);

}

EN_dioError_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber){
	if(pinNumber>7||pinNumber<0)
	{
		return DIO_INVALID_PIN;

	}
	switch(portNumber){
		case PORT_A: {
			TOGGLE_BIT(PORTA, pinNumber);
			return DIO_OK;

		}
		case PORT_B: {
			TOGGLE_BIT(PORTB, pinNumber);
			return DIO_OK;
		}
		case PORT_C: {
			TOGGLE_BIT(PORTC, pinNumber);
			return DIO_OK;
		}
		case PORT_D: {
			TOGGLE_BIT(PORTD, pinNumber);
			return DIO_OK;

		}
		default:{
		return DIO_INVALID_PORT;


		}
	}
}





