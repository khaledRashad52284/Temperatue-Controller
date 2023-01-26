/*
 * main.c
 *
 *  Created on: Jan 17, 2023
 *      Author: nadin
 */
#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"
#include "ADC.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"

#include <util/delay.h>

uint8 u8ControllerState=1;
int main(void) {
	uint8 u8PressedLoc = 0xFF;
	DIO_voidInit();
	ADC_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();
	ADC_voidEnable();
	uint8 Calc_flag = 0,GetOut_flag=0;
	uint16 Loc_s16_ADCDigitalValue = 0,i;
	uint8 Local_s8AnalogValue = 0, hundreds=0, tens=0, ones=0, InputTemp=0;
	u8ControllerState=EEPROM_u8ReadByte(0);
	while (1) {
		Calc_flag = 0;
		LCD_voidWriteCmd(0, 0x01);
		LCD_voidDisplayString(0, "Temperature=");
		while (1) {

			u8PressedLoc = KEYPAD_u8GetPressedKey(0);

			if (u8PressedLoc != 0xFF) {
				LCD_voidDisplayChar(0, u8PressedLoc);
				hundreds = u8PressedLoc - 48;
				u8PressedLoc = 0xFF;
				_delay_ms(100);
				break;
			}
		}
		while (1) {
			u8PressedLoc = KEYPAD_u8GetPressedKey(0);

			if (u8PressedLoc != 0xFF) {
				LCD_voidDisplayChar(0, u8PressedLoc);
				tens = u8PressedLoc - 48;
				u8PressedLoc = 0xFF;
				_delay_ms(100);
				break;
			}
		}
		while (1) {
			u8PressedLoc = KEYPAD_u8GetPressedKey(0);

			if (u8PressedLoc != 0xFF) {
				LCD_voidDisplayChar(0, u8PressedLoc);
				ones = u8PressedLoc - 48;
				u8PressedLoc = 0xFF;
				_delay_ms(100);
				break;
			}

		}
		if ((ones == 0) && (tens == 0) && (hundreds == 0)) {
			LCD_voidWriteCmd(0, 0x01);
			LCD_voidDisplayString(0, "1: for Heating");
			LCD_voidWriteCmd(0, 0xC0);
			LCD_voidDisplayString(0, "2: for Cooling");

			while (1) {
				u8PressedLoc = KEYPAD_u8GetPressedKey(0);

				if (u8PressedLoc != 0xFF) {
					if (u8PressedLoc == '1') {
						u8ControllerState = 1;
						EEPROM_voidWriteByte(1, 0);
						break;

					} else if (u8PressedLoc == '2') {
						u8ControllerState = 2;
						EEPROM_voidWriteByte(2, 0);
						break;

					} else {
						LCD_voidWriteCmd(0, 0x01);
						LCD_voidDisplayString(0, "Wrong choice");
					}
				}
			}

		} else {

			while (1) {
				Loc_s16_ADCDigitalValue = ADC_u16ReadSync(ADC_CHANNEL_DIFF_0_1);
				Local_s8AnalogValue = (((float32) (0.4889)* Loc_s16_ADCDigitalValue));

				if ((hundreds <= 1) && (Calc_flag == 0)) {
					InputTemp = (hundreds * 100) + (tens * 10) + (ones * 1);
					Calc_flag = 1;
					LCD_voidWriteCmd(0, 0x01);

				} else if ((hundreds > 1) && (Calc_flag == 0)) {
					LCD_voidWriteCmd(0, 0x01);
					LCD_voidDisplayString(0, "Invalid Value");
					_delay_ms(2000);
					break;
				}

				if (EEPROM_u8ReadByte(0) == 1) {
					if (InputTemp > Local_s8AnalogValue) {
						LCD_voidWriteCmd(0, 0x01);
						DIO_enuWritePin(DIO_PIN_NUM_8, DIO_HIGH);
						LCD_voidDisplayString(0, "Heater ON");
					} else {
						LCD_voidWriteCmd(0, 0x01);
						DIO_enuWritePin(DIO_PIN_NUM_8, DIO_LOW);
						LCD_voidDisplayString(0, "Heater OFF");

					}
				} else if (EEPROM_u8ReadByte(0) == 2) {
					if (InputTemp < Local_s8AnalogValue) {
						LCD_voidWriteCmd(0, 0x01);
						DIO_enuWritePin(DIO_PIN_NUM_8, DIO_HIGH);
						LCD_voidDisplayString(0, "Cooler ON");
					} else {
						LCD_voidWriteCmd(0, 0x01);
						DIO_enuWritePin(DIO_PIN_NUM_8, DIO_LOW);
						LCD_voidDisplayString(0, "Cooler OFF");

					}
				}
				else {
					if (InputTemp > Local_s8AnalogValue) {
						LCD_voidWriteCmd(0, 0x01);
						DIO_enuWritePin(DIO_PIN_NUM_8, DIO_HIGH);
						LCD_voidDisplayString(0, "Heater ON");
					} else {
						LCD_voidWriteCmd(0, 0x01);
						DIO_enuWritePin(DIO_PIN_NUM_8, DIO_LOW);
						LCD_voidDisplayString(0, "Heater OFF");

					}

				}
				//_delay_ms(500);

				for(i=0;i<10;i++)
				{
					u8PressedLoc = KEYPAD_u8GetPressedKey(0);
					if(u8PressedLoc!=0xFF)
					{
						GetOut_flag=1;
						break;
					}
				}
				if (GetOut_flag == 1) {
					GetOut_flag = 0;
					break;
				}


			}
			_delay_ms(500);

		}
	}
}



