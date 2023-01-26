#include "STD_Types.h"
#include "BIT_Math.h"

#include "util/delay.h"

#include "EEPROM.h"
#include "EEPROM_priv.h"

void EEPROM_voidWriteByte(uint8 DataCpy,uint16 AddressCpy)
{
	while(GET_BIT(EECR,EECR_EEWE)==1);
	EEAR=AddressCpy&0x03FF;
	EEDR=DataCpy;
	EECR=0b00000100;
	EECR=0b00000010;
	//_delay_ms(10);
}
uint8 EEPROM_u8ReadByte(uint16 AddressCpy)
{
	while(GET_BIT(EECR,EECR_EEWE)==1);
	EEAR=AddressCpy&0x03FF;
	SET_BIT(EECR,EECR_EERE);
	return EEDR;
}
void EEPROM_voidEnableINT(void)
{
	SET_BIT(EECR,EECR_EERIE);
}
