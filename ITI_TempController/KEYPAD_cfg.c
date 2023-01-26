/**************************************/
/* Description : Keypad cfg .c file   */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 16 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"

#include "DIO.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"



tstrKeypadConfigSet  KEYPAD_astrConfigSet[KEYPAD_MAX_NUM]=
{
	/*Keypad 0 CFG*/
	{
		/* array inputs pins */
		{
			DIO_PIN_NUM_16 ,DIO_PIN_NUM_17,
			DIO_PIN_NUM_18 ,DIO_PIN_NUM_19
		}
		,
		/* array Outputs pins */
		{
			DIO_PIN_NUM_20 ,DIO_PIN_NUM_21,
			DIO_PIN_NUM_22 ,DIO_PIN_NUM_23
		}
		,
		/* Input pins number*/
		4
		,
		/* Output pins number*/
		4
		  
	}
#if 0
	,
	/*Keypad 1 CFG*/
  {
	/* array inputs pins */
		{
			DIO_PIN_NUM_8 ,DIO_PIN_NUM_9,
			DIO_PIN_NUM_10  
		}
		,
		/* array Outputs pins */
		{
			DIO_PIN_NUM_11 ,DIO_PIN_NUM_12,
			DIO_PIN_NUM_13 ,DIO_PIN_NUM_14,
			DIO_PIN_NUM_15
		}
		,
		/* Input pins number*/
		3
		,
		/* Output pins number*/
		5	
		
	}
#endif
};



uint8 KEYPAD_au8Mapping[KEYPAD_MAX_NUM][KEYPAD_MAX_OUTPUT_NUM][KEYPAD_MAX_INPUT_NUM]=
{
   /*Keypad 0 CFG*/
	{
		{'7' ,'8' ,'9' ,'/' },
		{'4' ,'5' ,'6' ,'X' },
		{'1' ,'2' ,'3' ,'-' },
		{'.' ,'0' ,'=' ,'+' }
		//Dummy dead code
		//{ 0  , 0  ,  0 ,0   }
	}
#if 0
	,
	/*Keypad 1 CFG*/
	{
		{ '7' ,'8' ,'9',0},
		{ '4' ,'5' ,'6',0},
		{ '1' ,'2' ,'3',0},
		{ '-' ,'0' ,'=',0},
		{ 'X' , '/','+',0}
	}
#endif
};





