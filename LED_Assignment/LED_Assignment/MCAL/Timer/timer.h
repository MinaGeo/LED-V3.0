/*
 * timer.h
 *
 * Created: 9/5/2023 6:00:59 PM
 *  Author: HP
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../Utitlities/registers.h"

//timer0 modes
#define timer0_normal_mode 0
#define timer0_CTC_mode 1
#define timer0_PWM_mode 2
#define timer0_FastPWM_mode 3
//timer0 prescalar values
#define TIMER0_STOP 0
#define TIMER0_NO_PRESCALLING 1
#define TIMER0_SCALER_8 2
#define TIMER0_SCALER_64 3
#define TIMER0_SCALER_256 4
#define TIMER0_SCALER_1024 5
#define EXTERNAL_FALLING_EDGE 6
#define EXTERNAL_RISING_EDGE 7

#define NUMBER_OF_OVERFLOWS 2000

typedef enum EN_TimerError_t{
	TIMER_OK,TIMER_INVALID_MODE, TIMER_INVALID_PRESCALAR, TIMER_INVALID_DELAY
}EN_TimerError_t;


//Set timer0 mode (0 normal, 1 CTC, 2 PWM, 3 FastPWM)
EN_TimerError_t timer0_mode(uint8_t mode);

/*Timer0 prescalling
(TIMER0_STOP 0, TIMER0_NO_PRESCALLING 1, TIMER0_SCALER_8 2, TIMER0_SCALER_64 3,
TIMER0_SCALER_256 4, TIMER0_SCALER_1024 5, EXTERNAL_FALLING_EDGE 6, EXTERNAL_RISING_EDGE 7 */
EN_TimerError_t timer0_prescalar(uint8_t prescalar);


//this functions is used to set the delay for the timer
EN_TimerError_t timer_delay(uint16_t timeDelay);

//time stop
void timer_stop(void);

//overflow flag clear
void timer_clrOF_Flag(void);

// Timer0 set initial value
void timer0_set_initial(void);









#endif /* TIMER_H_ */