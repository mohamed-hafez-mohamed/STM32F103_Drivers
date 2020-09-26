/*******************************************************************************
* Title                 :   KEYPAD 
* Filename              :   KEYPAD_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   13/ 09/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  13/09/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file KEYPAD_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

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
static GPIO_PinId_t RowPins[ROWS_NUMBER] = 
{ROW_0_PIN, ROW_1_PIN, ROW_2_PIN, ROW_3_PIN};

static GPIO_PinId_t ColPins[COLUMS_NUMBER] = 
{COL_0_PIN, COL_1_PIN, COL_2_PIN, COL_3_PIN};
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void HKEYPAD_voidInit(void)
{
    u8 Local_u8Counter;
    for(Local_u8Counter = 0;Local_u8Counter < ROWS_NUMBER;Local_u8Counter++)
    {
        MGPIO_voidSetPinMode(RowPins[Local_u8Counter], GPIO_INPUT_PULL_UP_DN);
        MGPIO_u8ChoosePullMode(RowPins[Local_u8Counter], GPIO_PULL_DOWN);
    }
    for(Local_u8Counter = 0;Local_u8Counter < COLUMS_NUMBER;Local_u8Counter++)
    {
        MGPIO_voidSetPinMode(ColPins[Local_u8Counter], GPIO_OUTPUT_2M_PULL_UP_DN);
    }
    HKEYPAD_voidDisableCols();
}

static void HKEYPAD_voidDisableCols(void)
{
    u8 Local_u8Counter;
    for(Local_u8Counter = 0;Local_u8Counter < COLUMS_NUMBER;Local_u8Counter++)
    {
        MGPIO_voidSetPinValue(ColPins[Local_u8Counter], LOW);
    }
}

void HKEYPAD_voidGetKey(void * Copy_PKey)
{
    u8 * Local_PKey = (u8 *)(Copy_PKey);
    u8 Local_u8Counter;
    for(Local_u8Counter = 0;Local_u8Counter < COLUMS_NUMBER;Local_u8Counter++)
    {
        switch(Local_u8Counter)
        {
            case 0:
               HKEYPAD_voidDisableCols();
               MGPIO_voidSetPinValue(ColPins[0], HIGH);
               if     (MGPIO_u8GetPinValue(RowPins[0])) *Local_PKey = K_0_0;
               else if(MGPIO_u8GetPinValue(RowPins[1])) *Local_PKey = K_1_0;
               else if(MGPIO_u8GetPinValue(RowPins[2])) *Local_PKey = K_2_0;
               else if(MGPIO_u8GetPinValue(RowPins[3])) *Local_PKey = K_3_0;
            break;
            case 1:
               HKEYPAD_voidDisableCols();
               MGPIO_voidSetPinValue(ColPins[1], HIGH);
               if     (MGPIO_u8GetPinValue(RowPins[0])) *Local_PKey = K_0_1;
               else if(MGPIO_u8GetPinValue(RowPins[1])) *Local_PKey = K_1_1;
               else if(MGPIO_u8GetPinValue(RowPins[2])) *Local_PKey = K_2_1;
               else if(MGPIO_u8GetPinValue(RowPins[3])) *Local_PKey = K_3_1;
            break;
            case 2:
               HKEYPAD_voidDisableCols();
               MGPIO_voidSetPinValue(ColPins[2], HIGH);
               if     (MGPIO_u8GetPinValue(RowPins[0])) *Local_PKey = K_0_2;
               else if(MGPIO_u8GetPinValue(RowPins[1])) *Local_PKey = K_1_2;
               else if(MGPIO_u8GetPinValue(RowPins[2])) *Local_PKey = K_2_2;
               else if(MGPIO_u8GetPinValue(RowPins[3])) *Local_PKey = K_3_2;
            break;
            case 3:
               HKEYPAD_voidDisableCols();
               MGPIO_voidSetPinValue(ColPins[3], HIGH);
               if     (MGPIO_u8GetPinValue(RowPins[0])) *Local_PKey = K_0_3;
               else if(MGPIO_u8GetPinValue(RowPins[1])) *Local_PKey = K_1_3;
               else if(MGPIO_u8GetPinValue(RowPins[2])) *Local_PKey = K_2_3;
               else if(MGPIO_u8GetPinValue(RowPins[3])) *Local_PKey = K_3_3;
            break;
        }
    }
}

/*************** END OF FUNCTIONS ***************************************************************************/
