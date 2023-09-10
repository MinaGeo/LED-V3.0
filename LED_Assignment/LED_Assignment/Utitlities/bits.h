/*
 * bits.h
 *
 * Created: 9/10/2023 8:47:54 PM
 *  Author: HP
 */ 


#ifndef BITS_H_
#define BITS_H_


#define NUMBER_OF_BLINKS 5
#define  NUMBER_OF_CASES 8

//define fail test
#define testFail 10

//define BLINK MODES
#define BLINK1_ON 100
#define BLINK1_OFF 900
#define BLINK2_ON 200
#define BLINK2_OFF 800
#define BLINK3_ON 300
#define BLINK3_OFF 700
#define BLINK4_ON 500
#define BLINK4_OFF 500
#define BLINK5_ON 800
#define BLINK5_OFF 200

//define bits
#define BIT_1 1
#define BIT_2 2
#define BIT_3 3
#define BIT_4 4
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7

//define cases
#define CASE0 0
#define CASE1 1
#define CASE2 2
#define CASE3 3
#define CASE4 4
#define CASE5 5
#define CASE6 6
#define CASE7 7
#define CASE8 8




#define SET_BIT_v(byte,nbit)   ((byte) |= (1<<(nbit)))
#define CLEAR_BIT_v(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define TOGGLE_BIT(byte,nbit)  ((byte) ^= (1<<(nbit)))
#define CHECK_BIT(byte,nbit) (((byte) & (1<<(nbit)))>>nbit)

#endif /* BITS_H_ */