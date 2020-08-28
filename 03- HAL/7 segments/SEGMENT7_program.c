/*******************************************************************************
* Title                 :   SEGMENT7 
* Filename              :   SEGMENT7_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   10/8/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  17/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file SEGMENT7_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SEGMENT7_interface.h"
#include "SEGMENT7_private.h"
#include "SEGMENT7_config.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

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

void SEGEMENT7_voidNormInit(u8 copy_u8PinsArray[], SEGEMENT7_Mode_t copy_Mode)
{
    for (u8 pin = 0 ;pin < SEGMENT7_SEG_PINS ;pin++)
    {
		GPIO_voidSetPinMode(copy_u8PinsArray[pin], SEGMENT7_PIN_MODE);
	  }
		switch(copy_Mode)
    {
        case COMMON_CATHODE :
					for (u8 pin = 0 ;pin < SEGMENT7_SEG_PINS ;pin++)
          {
		          GPIO_voidSetPinValue(copy_u8PinsArray[pin], LOW);
	        }
        break;
        case COMMON_ANODE :
					   for (u8 pin = 0 ;pin < SEGMENT7_SEG_PINS ;pin++)
          {
		          GPIO_voidSetPinValue(copy_u8PinsArray[pin], HIGH);
	        }
        break;				
		}
}

void SEGEMENT7_voidBcdInit(u8 copy_u8PinsArray[])
{
    for (u8 pin = 0 ;pin < SEGMENT7_BCD_PINS;pin++)
    {
		     GPIO_voidSetPinMode(copy_u8PinsArray[pin], SEGMENT7_PIN_MODE);
	  }
		for (u8 pin = 0 ;pin < SEGMENT7_BCD_PINS ;pin++)
    {
		     GPIO_voidSetPinValue(copy_u8PinsArray[pin], LOW);
	  }
  
}

void SEGEMENT7_voidNormDisplay(u8 copy_u8PinsArray[], SEGEMENT7_Mode_t copy_Mode, SEGEMENT7_Number_t copy_Number)
{
    u8 pinValue;
    for (u8 pin = 0 ;pin < SEGMENT7_SEG_PINS ;pin++)
    {
		GPIO_voidSetPinValue(copy_u8PinsArray[pin], LOW);
	  }
    switch(copy_Mode)
    {
        case COMMON_CATHODE :    
	       for (u8 pin = 0 ;pin < SEGMENT7_SEG_PINS ;pin++)
           {
               pinValue = GET_BIT(copy_Number, pin);
		           GPIO_voidSetPinValue(copy_u8PinsArray[pin], pinValue);
	         }
        break;				
        case COMMON_ANODE   :
			for (u8 pin = 0 ;pin < SEGMENT7_SEG_PINS ;pin++)
           {
               pinValue = GET_BIT(copy_Number, pin);
		           GPIO_voidSetPinValue(copy_u8PinsArray[pin], !pinValue);
	         }		 
        break;
        default :
        /*!<TODO: Error Codes*/
        break;
    }
}

void SEGEMENT7_voidBcdDisplay(u8 copy_u8PinsArray[], SEGEMENT7_NumberBcd_t copy_Number)
{
    u8 pinValue;
    for (u8 pin = 0 ;pin < SEGMENT7_BCD_PINS ;pin++)
    {
		    GPIO_voidSetPinValue(copy_u8PinsArray[pin], LOW);
	  }
		for (u8 pin = 0 ;pin < SEGMENT7_BCD_PINS ;pin++)
     {
         pinValue = GET_BIT(copy_Number, pin);
		     GPIO_voidSetPinValue(copy_u8PinsArray[pin], pinValue); 
     }
}


/*************** END OF FUNCTIONS ***************************************************************************/
