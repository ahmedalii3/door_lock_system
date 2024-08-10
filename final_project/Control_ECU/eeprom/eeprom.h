/*
 * eeprom.h
 *
 *  Created on: Jul 29, 2024
 *      Author: DELL
 */

#ifndef EEPROM_EEPROM_H_
#define EEPROM_EEPROM_H_
#include "../std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);


#endif /* EEPROM_EEPROM_H_ */
