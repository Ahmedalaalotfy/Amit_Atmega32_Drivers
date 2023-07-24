/*
 * EEPROM_program.c
 *
 * Created: 10/10/2022 6:42:19 AM
 *  Author: ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "TWI_interface.h"

/* HAL */ 
#include "EEPROM_interface.h"

void EEPROM_writeByte(u16 byteAddress,u8 data)
{
	u8 address = (u8) ( EEPROM_FIXED_ADDRESS | (u8)(byteAddress >> 8)) ; // 0b01010000
	
	// Send Start Condition 
	TWI_sendStartCondition(); 
	
	// Send Slave Address With Write Operation
	TWI_sendSlaveAddWithWrite(address);
	
	// Send Byte Address 
	TWI_sendMasterDataByte((u8)byteAddress);
	
	// Send Byte Data
	TWI_sendMasterDataByte(data);
	
	// Send Stop Condition 
	TWI_sendStopCondition();
	
	_delay_ms(5);
}

void EEPROM_readByte(u16 byteAddress,u8* returnedData)
{
	u8 address = (u8) ( EEPROM_FIXED_ADDRESS | (u8)(byteAddress >> 8)) ; // 0b01010000
	
	// Send Start Condition 
	TWI_sendStartCondition(); 
	
	// Send Slave Address With Write Operation
	TWI_sendSlaveAddWithWrite(address);
	
	// Send Byte Address
	TWI_sendMasterDataByte((u8)byteAddress);
	
	// Send Repeated Start
	TWI_sendRepStartCondition(); 
	
	// Send Slave Address With Read Operation
	TWI_sendSlaveAddWithRead(address);
	
	// Read Byte Data
	TWI_readMasterDataByte(returnedData);
	
	// Send Stop Condition 
	TWI_sendStopCondition();
	
	_delay_ms(5);
	
}