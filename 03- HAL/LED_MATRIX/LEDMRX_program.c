/*******************************************************************************
* Title                 :   LEDMRX 
* Filename              :   LEDMRX_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   31/08/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  31/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file LEDMRX_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdlib.h>
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"

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
static GPIO_PinId_t Static_Rows[8] = 
{
 LEDMRX_ROW_0, 
 LEDMRX_ROW_1,   
 LEDMRX_ROW_2,    
 LEDMRX_ROW_3,   
 LEDMRX_ROW_4,   
 LEDMRX_ROW_5,   
 LEDMRX_ROW_6,   
 LEDMRX_ROW_7   
};
static GPIO_PinId_t Static_Cols[8] = 
{
 LEDMRX_COL_0, 
 LEDMRX_COL_1, 
 LEDMRX_COL_2,  
 LEDMRX_COL_3,  
 LEDMRX_COL_4,  
 LEDMRX_COL_5,  
 LEDMRX_COL_6,  
 LEDMRX_COL_7
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void HLEDMRX_voidInit(void)
{
    u8 Local_u8Counter;
    for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_ROWS_NUMBER;Local_u8Counter++)
    {
        GPIO_voidSetPinMode(Static_Rows[Local_u8Counter], GPIO_OUTPUT_2M_PULL_UP_DN);
    }

    for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_COLS_NUMBER;Local_u8Counter++)
    {
        GPIO_voidSetPinMode(Static_Cols[Local_u8Counter], GPIO_OUTPUT_2M_PULL_UP_DN);
    }
}

void HLEDMRX_voidDisplayFrame(u8 * Copy_u8Data)
{
    u8 Local_u8Counter;
		#if LEDMRX_CONTROL == LEDMRX_COL_CONTROL
			#if LEDMRX_ACTIVE == LEDMRX_COL_ACTIVE_LOW
			    for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_COLS_NUMBER;Local_u8Counter++)
                {
                   HLEDMRX_voidDisable();
                   HLEDMRX_voidSetValues(Copy_u8Data[Local_u8Counter]);
                   GPIO_voidSetPinValue(Static_Cols[Local_u8Counter], LOW);
                   MSTK_voidSetBusyWait_us(2500);
                }
	       #elif LEDMRX_ACTIVE == LEDMRX_COL_ACTIVE_HIGH
		        for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_COLS_NUMBER;Local_u8Counter++)
                {
                   HLEDMRX_voidDisable();
                   HLEDMRX_voidSetValues(Copy_u8Data[Local_u8Counter]);
                   GPIO_voidSetPinValue(Static_Cols[Local_u8Counter], HIGH);
                   MSTK_voidSetBusyWait_us(2500);
                }
	       #else
		        #error "Wrong Configuration"
	       #endif
		#elif LEDMRX_CONTROL == LEDMRX_ROW_CONTROL
			#if LEDMRX_ACTIVE == LEDMRX_ROW_ACTIVE_LOW
			    for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_ROWS_NUMBER;Local_u8Counter++)
                {
                    HLEDMRX_voidDisable();
                    HLEDMRX_voidSetValues(Copy_u8Data[Local_u8Counter]);
                    GPIO_voidSetPinValue(Static_Rows[Local_u8Counter], LOW);
                    MSTK_voidSetBusyWait_us(2500);
                }
	       #elif LEDMRX_ACTIVE == LEDMRX_ROW_ACTIVE_HIGH
		        for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_ROWS_NUMBER;Local_u8Counter++)
                {
                   HLEDMRX_voidDisable();
                   HLEDMRX_voidSetValues(Copy_u8Data[Local_u8Counter]);
                   GPIO_voidSetPinValue(Static_Rows[Local_u8Counter], HIGH);
                   MSTK_voidSetBusyWait_us(2500);
                }
	       #else
		        #error "Wrong Configuration"
	       #endif		
						
		#else
			#error "Wrong Configuration"	
  		#endif				
}

static void HLEDMRX_voidDisable(void)
{
    u8 Local_u8Counter;
	#if LEDMRX_CONTROL == LEDMRX_COL_CONTROL
	  #if LEDMRX_ACTIVE == LEDMRX_COL_ACTIVE_LOW
      for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_COLS_NUMBER;Local_u8Counter++)
      {
         GPIO_voidSetPinValue(Static_Cols[Local_u8Counter], HIGH);
      }
	  #elif LEDMRX_ACTIVE == LEDMRX_COL_ACTIVE_HIGH
		   for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_COLS_NUMBER;Local_u8Counter++)
       {
           GPIO_voidSetPinValue(Static_Cols[Local_u8Counter], LOW);
       }
	  #else
		   #error "Wrong Configuration"
	  #endif
	#elif LEDMRX_CONTROL == LEDMRX_ROW_CONTROL
		#if LEDMRX_ACTIVE == LEDMRX_ROW_ACTIVE_LOW
			 for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_ROWS_NUMBER;Local_u8Counter++)
       {
          GPIO_voidSetPinValue(Static_Rows[Local_u8Counter], HIGH);
       }
		#elif LEDMRX_ACTIVE == LEDMRX_ROW_ACTIVE_HIGH
		   for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_ROWS_NUMBER;Local_u8Counter++)
       {
           GPIO_voidSetPinValue(Static_Rows[Local_u8Counter], LOW);
       }
	  #else
		   #error "Wrong Configuration"
		#endif
	#else
		#error "Wrong Configuration"	
	#endif
}

static void HLEDMRX_voidSetValues(u8 Copy_u8Value)
{
    u8 Local_u8BIT;
    u8 Local_u8Counter;
		#if LEDMRX_CONTROL == LEDMRX_COL_CONTROL
       for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_ROWS_NUMBER;Local_u8Counter++)
       {
           Local_u8BIT = GET_BIT(Copy_u8Value, Local_u8Counter);
           GPIO_voidSetPinValue(Static_Rows[Local_u8Counter], Local_u8BIT);
       }
	  #elif LEDMRX_CONTROL == LEDMRX_ROW_CONTROL
			 for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_COLS_NUMBER;Local_u8Counter++)
       {
           Local_u8BIT = GET_BIT(Copy_u8Value, Local_u8Counter);
           GPIO_voidSetPinValue(Static_Cols[Local_u8Counter], Local_u8BIT);
       }
	  #else
		   #error "Wrong Configuration"	
	  #endif
}


void HLEDMRX_voidDisplayText(u8  * Copy_u8Data, u16 Copy_u16TextSize, u8 Copy_u8TimeDelay)
{
	u8 Local_Counter = 0;
    while(Local_Counter < Copy_u16TextSize)
    {
        HLEDMRX_voidDisplayFrame(Copy_u8Data);
			  HLEDMRX_voidPauseDisplayFrame(Copy_u8Data, Copy_u8TimeDelay);
        Copy_u8Data++;
			  Local_Counter++;
    }
}

void HLEDMRX_voidPauseDisplayFrame(u8 * Copy_u8Data, u8 Copy_u8Time)
{
	u8 Local_u8Counter;
   while(Copy_u8Time--)
	{
		 for(Local_u8Counter = 0;Local_u8Counter < LEDMRX_COLS_NUMBER;Local_u8Counter++)
     {
          HLEDMRX_voidDisable();
          HLEDMRX_voidSetValues(Copy_u8Data[Local_u8Counter]);
          GPIO_voidSetPinValue(Static_Cols[Local_u8Counter], LOW);
          MSTK_voidSetBusyWait_us(2500);
     }
	}
}



/*************** END OF FUNCTIONS ***************************************************************************/
