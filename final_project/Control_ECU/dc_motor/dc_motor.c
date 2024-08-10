/*
 * dc_motor.c
 *
 *  Created on: Jul 29, 2024
 *      Author: DELL
 */


#include"../gpio/gpio.h"
#include "../PWM_timer0/pwm.h"
#include "dc_motor.h"
void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	GPIO_writePin(PORTB_ID,PIN0_ID,0);
	GPIO_writePin(PORTB_ID,PIN1_ID,0);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	uint8 dutyCycle;
	dutyCycle = (speed*0.01)*255;
	PWM_Timer0_Start(dutyCycle);
	switch(state){
		case CW:
			GPIO_writePin(PORTB_ID,PIN1_ID,1);
			GPIO_writePin(PORTB_ID,PIN0_ID,0);
			break;
		case ACW:
			GPIO_writePin(PORTB_ID,PIN1_ID,0);
			GPIO_writePin(PORTB_ID,PIN0_ID,1);
			break;
		case stop:
			GPIO_writePin(PORTB_ID,PIN1_ID,0);
			GPIO_writePin(PORTB_ID,PIN0_ID,0);
			break;
	}


}
