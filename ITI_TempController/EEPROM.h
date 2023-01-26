#ifndef EEPROM_H
#define EEPROM_H

void EEPROM_voidWriteByte(uint8 DataCpy,uint16 AddressCpy);
uint8 EEPROM_u8ReadByte(uint16 AddressCpy);
void EEPROM_voidEnableINT(void);





#endif
