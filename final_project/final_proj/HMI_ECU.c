/*
 * HMI_ECU.c
 *
 *  Created on: Jul 24, 2024
 *      Author: DELL
 */

#include"lcd/lcd.h"
#include"keypad/keypad.h"
#include"uart/uart.h"
#include "timer/timer.h"
#include <util/delay.h> /* For the delay functions */
#include <avr/io.h> /* To use the SREG register */




void pass_creation(uint8 * key_one,uint8 * key_two );
uint8 pass_check(uint8 * key_check);
typedef enum{
	yes,
	no
}stay;

uint8 ProgramFinish = 0;
uint8 count = 1;
void door_unlock(){
	if(count == 6){
		LCD_clearScreen();
		LCD_displayString("Door is locking");

	}else if(count == 11){
		LCD_clearScreen();
	}
	count++;
}
int main(void)
{

	SREG |= (1<<7);

	UART_ConfigType  conf;
	conf.baud_rate = 9600;
	conf.bit_data  = EIGT;
	conf.parity    = EVEN;
	conf.stop_bit  = ONE_BIT;

	Timer1_ConfigType time_conf;
	time_conf.initial_value = 0;
	time_conf.mode = COMPARE;
	time_conf.prescaler = ONE_ZERO_TWO_FOUR;
	//compare each 3 seconds
	time_conf.compare_value = 23437;


	UART_init(&conf);
	LCD_init();
	stay StayInPlusMinus = yes;
	uint8 cou = 0;
	uint8 auth;
	uint8 match_cond;
	uint8 twoKey;

	uint8 enter_key;
	uint8 key_one[5];
	uint8 key_two[5];
	uint8 key_check[5];


	while(1){

		StayInPlusMinus = yes;
		if(ProgramFinish == 0){
			ProgramFinish = 1;

		LCD_clearScreen();
		pass_creation( &key_one, &key_two);

		enter_key = KEYPAD_getPressedKey();
		_delay_ms(400);

		if (enter_key == '*' ){

			enter_key = 0;
			for(int l = 0 ; l < 5 ; l++){

				UART_sendByte(key_one[l]);
				_delay_ms(50);
			}
			for(int i = 0 ; i < 5 ; i++){
				UART_sendByte(key_two[i]);
				_delay_ms(50);

			}
			match_cond = UART_recieveByte();
			_delay_ms(50);
			if (match_cond == 0){
				while(StayInPlusMinus == yes ){
					StayInPlusMinus = no;
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,0,"+ : Open Door");
				LCD_displayStringRowColumn(1,0,"- : Change Pass");
				twoKey = KEYPAD_getPressedKey();
				_delay_ms(500);
				UART_sendByte(twoKey);
				_delay_ms(50);
				if(twoKey == '+'){
					auth = pass_check(key_check);
					cou = 0;
					LCD_clearScreen();
					//not match
					while(auth == 1 && cou < 2){
								LCD_clearScreen();

								_delay_ms(50);
								auth = pass_check(key_check);
								cou++;
							}
					if(cou >= 2){
								LCD_clearScreen();
								LCD_displayString("ERROR!!");
								for (int i = 0 ; i<10 ; i++){
								_delay_ms(6000);
								}
								StayInPlusMinus = yes;
							}
							//match
					if(auth == 0){
								LCD_clearScreen();
								LCD_displayString("Door is unlocking!!");
								Timer1_setCallBack(door_unlock);
								Timer1_init(&time_conf);
							}

				}else if(twoKey == '-'){
						cou =0;
						auth = pass_check(key_check);
						//not match
						while(auth == 1 && cou < 2){
							LCD_clearScreen();

							_delay_ms(50);
							auth = pass_check(key_check);
							cou++;
						}
						if(cou >= 2){
							LCD_clearScreen();
							LCD_displayString("ERROR!!");
							for (int i = 0 ; i<10 ; i++){
							_delay_ms(6000);
							}
							StayInPlusMinus = yes;
						}
						//match
						if(auth == 0){
							LCD_clearScreen();
							ProgramFinish = 0;

						}
				}

			}
			}else{
				LCD_clearScreen();
				ProgramFinish = 0;
			}

		}


	}
}
}




void pass_creation(uint8 * key_one,uint8 * key_two ){
			uint8 key;
			uint8 i = 0;
			uint8 j = 0;
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"Plz enter pass:");
	    	LCD_moveCursor(1,0);
			while(i<5){
				key = KEYPAD_getPressedKey();
				_delay_ms(500); /* Press time */
				if((key <= 9) && (key >= 0))
						{
							LCD_displayString("*");
							key_one[i]=key;
						}

						i++;
			}
			LCD_clearScreen();
			LCD_displayString("Plz re-enter the");
			LCD_displayStringRowColumn(1,0,"same pass:");
			while(j<5){
					key = KEYPAD_getPressedKey();
					_delay_ms(400); /* Press time */
					if((key <= 9) && (key >= 0))
							{
								LCD_displayString("*");
								key_two[j] = key;
							}

							j++;
			}
}



uint8 pass_check(uint8 * key_check){
	uint8 key;
	uint8 enter_key;
	uint8 i = 0;
	uint8 match_cond = 0;
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Plz enter pass:");
	LCD_moveCursor(1,0);
	while(i<5){
		key = KEYPAD_getPressedKey();
		_delay_ms(500); /* Press time */
		if((key <= 9) && (key >= 0))
				{
					LCD_displayString("*");
					key_check[i]=key;
				}

				i++;
	}
	enter_key = KEYPAD_getPressedKey();
	_delay_ms(500);
	if (enter_key == '*' ){
	for(int l = 0 ; l < 5 ; l++){

			UART_sendByte(key_check[l]);
			_delay_ms(50);
	}
	match_cond = UART_recieveByte();
	_delay_ms(50);
	}

	return match_cond;
}
