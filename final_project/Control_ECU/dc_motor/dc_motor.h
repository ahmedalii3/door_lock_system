/*
 * dc_motor.h
 *
 *  Created on: Jul 29, 2024
 *      Author: DELL
 */

#ifndef DC_MOTOR_DC_MOTOR_H_
#define DC_MOTOR_DC_MOTOR_H_

typedef enum{
	CW,
	ACW,
	stop,
}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_DC_MOTOR_H_ */
