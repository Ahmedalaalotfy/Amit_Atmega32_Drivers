/*
 * EEPROM_interface.h
 *
 * Created: 10/10/2022 6:43:07 AM
 *  Author: ahmed
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#define EEPROM_FIXED_ADDRESS 0x50   // 0b01010000

void EEPROM_writeByte(u16 byteAddress,u8 data);
void EEPROM_readByte(u16 byteAddress,u8* returnedData);


#endif /* EEPROM_INTERFACE_H_ */