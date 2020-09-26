/*******************************************************************************
* Title                 :   STP 
* Filename              :   STP_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   15/09/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  15/09/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file STP_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"

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

void HSTP_voidInit(void)
{
    MGPIO_voidSetPinMode(STP_SERIAL_DATA, GPIO_OUTPUT_10M_PULL_UP_DN);
    MGPIO_voidSetPinMode(STP_SHIFT_CLOCK, GPIO_OUTPUT_10M_PULL_UP_DN);
    MGPIO_voidSetPinMode(STP_STORE_CLOCK, GPIO_OUTPUT_10M_PULL_UP_DN);
}

void HSTP_voidSendSynchronusSH8Bit(u8 Copy_u8DataToSend)
{
    s8 Local_s8Counter;
    u8 Local_u8DataBit;
    for(Local_s8Counter = 7;Local_s8Counter >= 0;Local_s8Counter--)
    {
        Local_u8DataBit = GET_BIT(Copy_u8DataToSend, Local_s8Counter);
        MGPIO_voidSetPinValue(STP_SERIAL_DATA, Local_u8DataBit);
        MGPIO_voidSetPinValue(STP_SHIFT_CLOCK, HIGH);
        MSTK_voidSetBusyWait_us(1);
        MGPIO_voidSetPinValue(STP_SHIFT_CLOCK, LOW);
        MSTK_voidSetBusyWait_us(1);
    }
    MGPIO_voidSetPinValue(STP_STORE_CLOCK, HIGH);
    MSTK_voidSetBusyWait_us(1);
    MGPIO_voidSetPinValue(STP_STORE_CLOCK, LOW);
    MSTK_voidSetBusyWait_us(1);
}

void HSTP_voidSendSynchronusSH16Bit(u16 Copy_u16DataToSend)
{
    s8 Local_s8Counter;
    u8 Local_u8DataBit;
    for(Local_s8Counter = 15;Local_s8Counter >= 0;Local_s8Counter--)
    {
        Local_u8DataBit = GET_BIT(Copy_u16DataToSend, Local_s8Counter);
        MGPIO_voidSetPinValue(STP_SERIAL_DATA, Local_u8DataBit);
        MGPIO_voidSetPinValue(STP_SHIFT_CLOCK, HIGH);
        MSTK_voidSetBusyWait_us(1);
        MGPIO_voidSetPinValue(STP_SHIFT_CLOCK, LOW);
        MSTK_voidSetBusyWait_us(1);
    }
    MGPIO_voidSetPinValue(STP_STORE_CLOCK, HIGH);
    MSTK_voidSetBusyWait_us(1);
    MGPIO_voidSetPinValue(STP_STORE_CLOCK, LOW);
    MSTK_voidSetBusyWait_us(1);
}


/*************** END OF FUNCTIONS ***************************************************************************/
