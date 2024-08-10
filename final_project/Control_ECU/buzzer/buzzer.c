/*
 * buzzer.c
 *
 *  Created on: Jul 29, 2024
 *      Author: DELL
 */
#include "../gpio/gpio.h"
#include"buzzer.h"
void Buzzer_init(){
	GPIO_setupPinDirection(PORTA_ID,PIN0_ID ,PIN_OUTPUT);
	GPIO_writePin(PORTA_ID,PIN0_ID,0);
}
void Buzzer_on(void){
	GPIO_writePin(PORTA_ID,PIN0_ID,1);
}
void Buzzer_off(void){
	GPIO_writePin(PORTA_ID,PIN0_ID,0);
}
