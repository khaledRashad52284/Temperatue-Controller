#ifndef EEPROM_PRIV_H
#define EEPROM_PRIV_H

#define EEAR *((volatile uint16 *)0x3E)
#define EEDR *((volatile uint8 *)0x3D)

#define EECR *((volatile uint8 *)0x3C)
#define EECR_EERE          0
#define EECR_EEWE          1
#define EECR_EEMWE         2
#define EECR_EERIE         3



#endif