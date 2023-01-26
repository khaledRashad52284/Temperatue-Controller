/**************************************/
/* Description : Keypad interface file*/
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 16 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef KEYPAD_H
#define KEYPAD_H

void KEYPAD_voidInit(void);

uint8 KEYPAD_u8GetPressedKey(uint8 u8KeyPadIdxCpy);


#endif
