/**************************************/
/* Description : BIT MATH             */
/* Author      : Mohamed Beshir       */
/* Version     : 0.1v                 */
/* Date        : 25 Nov 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

#endif 
