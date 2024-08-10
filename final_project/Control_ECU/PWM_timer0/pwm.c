/*
 * pwm.c
 *
 *  Created on: Jul 29, 2024
 *      Author: DELL
 */


#include "../gpio/gpio.h"
#include"avr/io.h"

void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0 =0;
	OCR0 = duty_cycle;
//	DDRB  = DDRB | (1<<PB3);
	GPIO_setupPinDirection(PORTB_ID,PB3,1);
	TCCR0 |= (1<<WGM00) | (1<<WGM01) |  (1<<COM01) | (1<<CS01);

}
