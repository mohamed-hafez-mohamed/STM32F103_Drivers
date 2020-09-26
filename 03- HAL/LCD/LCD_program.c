/*******************************************************************************
* Title                 :   LCD 
* Filename              :   LCD_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   22/09/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  22/09/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file LCD_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include <stdlib.h>
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DataConversion_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
#if   LCD_MODE == LCD_4_BIT_MODE
   #define LCD_DATA_PINS          4
#elif LCD_MODE == LCD_8_BIT_MODE
   #define LCD_DATA_PINS          8
#endif

#if   LCD_DATA_PINS == 4
   static u8 Static_u8DataPins[LCD_DATA_PINS] = {LCD_D4,LCD_D5,LCD_D6,LCD_D7};
#elif LCD_DATA_PINS == 4
   static u8 Static_u8DataPins[LCD_DATA_PINS] = {LCD_D0,LCD_D1,LCD_D2,LCD_D3,LCD_D4,LCD_D5,LCD_D6,LCD_D7};
#endif

#define LCD_COL_16        16
#define LCD_COL_32        32
/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
static void HLCD_voidkick(u8 Copy_u8Character)
{
   /**
	* Assign Data on the pins of the confg
	* Make pulse to make lcd working
	**/
	for(u8 Local_u8Counter = 0;Local_u8Counter < LCD_DATA_PINS;Local_u8Counter++)
	{
		if(Copy_u8Character & (SET << Local_u8Counter))
		{
         MGPIO_voidSetPinValue(Static_u8DataPins[Local_u8Counter], HIGH);
		}
		else
		{
         MGPIO_voidSetPinValue(Static_u8DataPins[Local_u8Counter], LOW);
		}
	}
   MGPIO_voidSetPinValue(LCD_EN, HIGH);
   MSTK_voidSetBusyWait_ms(1);
   MGPIO_voidSetPinValue(LCD_EN, LOW);
}

void HLCD_voidInit(void)
{
   /**
	* Set dirction output for data and control pins
	* Config the lcd to start working
	**/
   MGPIO_voidSetPinMode(LCD_RS, GPIO_OUTPUT_2M_PULL_UP_DN);
   MGPIO_voidSetPinMode(LCD_EN, GPIO_OUTPUT_2M_PULL_UP_DN);
   for(u8 Local_u8Counter = 0;Local_u8Counter < LCD_DATA_PINS;Local_u8Counter++)
	{
		MGPIO_voidSetPinMode(Static_u8DataPins[Local_u8Counter], GPIO_OUTPUT_2M_PULL_UP_DN);
	}
   #if   LCD_MODE == LCD_4_BIT_MODE
   HLCD_voidCMD(LCD_4BIT_MODE_CMD);
   HLCD_voidCMD(LCD_4BIT_MODE_2_LINE_CMD);
   #elif LCD_MODE == LCD_8_BIT_MODE
   HLCD_voidCMD(LCD_8BIT_MODE_2_LINE_CMD);
   #endif 
   HLCD_voidSetCursor(0, 0);
   HLCD_voidCMD(LCD_ENTRY_MODE_CMD);
   HLCD_voidCMD(LCD_CURSOR_BLINK_CMD);
   HLCD_voidCMD(LCD_CLEAR_SCREEN_CMD);
}

void HLCD_voidCMD(u8 Copy_u8Command)
{
   /**
	* Select the register "command || data " in this case command
	* Sent the command
	**/
   MGPIO_voidSetPinValue(LCD_RS, LOW);
   #if   LCD_MODE == LCD_4_BIT_MODE
   HLCD_voidkick((Copy_u8Command) >> 4);
   HLCD_voidkick(Copy_u8Command);
   #elif LCD_MODE == LCD_8_BIT_MODE
   HLCD_voidkick(Copy_u8Command);
   #endif 
   MSTK_voidSetBusyWait_ms(2);
}

void HLCD_voidSetCursor(u8 Copy_u8Row, u8 Copy_u8Col)
{
   switch(Copy_u8Row)
   {
      case 0 :
         HLCD_voidCMD((unsigned)(LCD_BEGIN_AT_FIRST_RAW_CMD  | Copy_u8Col));
      break;
      case 1 :
         HLCD_voidCMD((unsigned)(LCD_BEGIN_AT_SECOND_RAW_CMD | Copy_u8Col));
      break;
      #if LCD_TYPE == LCD_16_4
      case 2 :
         HLCD_voidCMD((unsigned)(LCD_BEGIN_AT_THIRD_RAW_CMD  | Copy_u8Col));
      break;
      case 3 :
         HLCD_voidCMD((unsigned)(LCD_BEGIN_AT_FOURTH_RAW_CMD | Copy_u8Col));
      break;
      #endif
   }
}

void HLCD_void_ClearSreen(void)
{
   HLCD_voidCMD(LCD_CLEAR_SCREEN_CMD);
}

void HLCD_voidTurnOffDisplay(void)
{
   HLCD_voidCMD(LCD_DISPLAY_OFF_CMD);
}

void HLCD_voidWriteChar(u8 Copy_u8Character)
{
   MGPIO_voidSetPinValue(LCD_RS, HIGH);
   #if   LCD_MODE == LCD_4_BIT_MODE
   HLCD_voidkick((Copy_u8Character) >> 4);
   HLCD_voidkick(Copy_u8Character);
   #elif LCD_MODE == LCD_8_BIT_MODE
   HLCD_voidkick(Copy_u8Character);
   #endif 
   MSTK_voidSetBusyWait_ms(2);
}

void HLCD_voidWriteString(u8 * Copy_u8String)
{
   u8 Local_u8Counter = 0;
   while(Copy_u8String[Local_u8Counter] != '\0')
   {
      HLCD_voidWriteChar(Copy_u8String[Local_u8Counter]);
      Local_u8Counter++;
      if(Local_u8Counter == LCD_COL_16)
      {
         HLCD_voidSetCursor(1, 0);
      }
      else if(Local_u8Counter == LCD_COL_32)
      {
         HLCD_void_ClearSreen();
         HLCD_voidSetCursor(1, 0);
         Local_u8Counter = 0;
      }
   }
}

void HLCD_voidWriteIntNum(u8 Copy_u8Number)
{
   u8 * Local_u8Buffer[16];
   itoa(Copy_u8Number, Local_u8Buffer, LCD_DECIMAL);
   HLCD_voidWriteString(Local_u8Buffer);
}

void HLCD_void_WriteFloatNum(float Copy_floatNumber)
{
   u8 *  Local_u8Buffer[16];
   u8 *  Local_u8Sign     = (Copy_floatNumber < 0)? '-' : '+';                              //Get sign
   float Local_floatNum   = (Copy_floatNumber < 0)? -Copy_floatNumber : Copy_floatNumber;   //store the sent number
   u16   Local_u8IntPart  = Local_floatNum;                                                 //Get the first integer part before the point
   float Local_floatPart  = Local_floatNum - Local_u8IntPart;                               //Get fraction
   u8    Local_u8FracPart = Local_floatPart * LCD_NUMBER_TYPE_AFTER_POINT;                  //Turn into fraction into integer value
   // Print as parts
	 sprintf (Local_u8Buffer, "%s%d.%2d", Local_u8Sign, Local_u8IntPart, Local_u8FracPart);
   HLCD_voidWriteString(Local_u8Buffer);
}

/*************** END OF FUNCTIONS ***************************************************************************/
