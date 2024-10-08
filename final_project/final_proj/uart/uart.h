/*
 * uart.h
 *
 *  Created on: Jul 26, 2024
 *      Author: DELL
 */

#ifndef UART_UART_H_
#define UART_UART_H_

#include "../std_types.h"
typedef uint32 UART_BaudRate;

typedef enum{
	FIVE = 0,
	SIX,
	SEVEN,
	EIGT,
	NINE = 7
}UART_BitData;
typedef enum{
	DISABLED = 0,
	EVEN =2,
	ODD = 3
}UART_Parity;
typedef enum{
	ONE_BIT,
	TWO_BITS

}UART_StopBit;

//typedef enum{
//	DISABLED,
//	EVEN,
//	ODD
//}UART_Parity;
typedef struct{
 UART_BitData bit_data;
 UART_Parity parity;
 UART_StopBit stop_bit;
 UART_BaudRate baud_rate;

}UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType * Config_Ptr);
//void UART_init(uint32 baud_rate);
/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_UART_H_ */
