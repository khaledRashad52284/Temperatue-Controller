/**************************************/
/* Description : Keypad private file  */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 16 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef KEYPAD_PRIV_H
#define KEYPAD_PRIV_H



typedef struct 
{
	uint8 au8InputPins [KEYPAD_MAX_INPUT_NUM];
	uint8 au8OutputPins[KEYPAD_MAX_OUTPUT_NUM];
	uint8 u8InputPinsNum ;
	uint8 u8OutputPinsNum ;
	
}tstrKeypadConfigSet ;


extern tstrKeypadConfigSet  KEYPAD_astrConfigSet[KEYPAD_MAX_NUM] ;
extern uint8 KEYPAD_au8Mapping[KEYPAD_MAX_NUM][KEYPAD_MAX_OUTPUT_NUM][KEYPAD_MAX_INPUT_NUM];

static void   voidWriteSeq  (uint8 u8KeyPadIdxCpy , uint8 u8SeqIdxCpy     );
static uint16 u16ReadInputs (uint8 u8KeyPadIdxCpy                         );
static uint8 u8CheckReading(uint8 u8KeyPadIdxCpy , uint8 u8SeqIdxCpy, uint16 u16InputReadingCpy );

#endif