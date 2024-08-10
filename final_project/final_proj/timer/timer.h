/*
 * timer.h
 *
 *  Created on: Jul 25, 2024
 *      Author: DELL
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_
#include "../std_types.h"


//typedef uint8 Timer1_Prescaler;
typedef enum{
	ONE = 1,
	EIGHT =2,
	SIX_FOUR=3,
	TWO_FIVE_SIX=4,
	ONE_ZERO_TWO_FOUR=5

}Timer1_Prescaler;

typedef enum{
	NORMAL,
	COMPARE
}Timer1_Mode;


typedef struct {
 uint16 initial_value;
 uint16 compare_value; // it will be used in compare mode only.
 Timer1_Prescaler prescaler;
 Timer1_Mode mode;
} Timer1_ConfigType;

void Timer1_init(const Timer1_ConfigType * Config_Ptr);
void Timer1_deInit(void);
void Timer1_setCallBack(void(*a_ptr)(void));

#endif /* TIMER_TIMER_H_ */
