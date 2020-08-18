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
*  04/01/15   1.0.0   Mohamed Hafez   Initial Release.
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

// TODO: UPDATE AND COPY THESE FOR EACH NON_TRIVIAL FUNCTION
/******************************************************************************
* Function : Dio_Init()
*//** 
* \b Description:
*
* This function is used to initialize the Dio based on the configuration table
*  defined in dio_cfg module.  
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the configuration
* table will be returned.
*
* @return 		A pointer to the configuration table.
*
* \b Example Example:
* @code
* 	const Dio_ConfigType *DioConfig = Dio_GetConfig();
*
* 	Dio_Init(DioConfig);
* @endcode
*
* @see Dio_Init
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
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
