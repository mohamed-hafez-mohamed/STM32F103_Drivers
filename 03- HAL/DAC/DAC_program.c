/*******************************************************************************
* Title                 :   DAC 
* Filename              :   DAC_program.c
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
*  04/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file DAC_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DAC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"

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
static GPIO_PinId_t Global_Dac[8] = 
{
 DAC_BIT_0, 
 DAC_BIT_1, 
 DAC_BIT_2,  
 DAC_BIT_3,  
 DAC_BIT_4,  
 DAC_BIT_5,  
 DAC_BIT_6,  
 DAC_BIT_7
};
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void HDAC_voidInitDacParallel(void)
{
    u8 Local_u8Counter;
    for(Local_u8Counter = 0;Local_u8Counter < DAC_8_BIT;Local_u8Counter++)
    {
        MGPIO_voidSetPinMode(Global_Dac[Local_u8Counter], GPIO_OUTPUT_2M_PULL_UP_DN);
    }
}

void HDAC_voidWriteVlueParallel(void)
{
    u8        Local_u8BIT;
    static u8 Local_u8Counter1 = 0;
    u8        Local_u8Counter2;
    
    for(Local_u8Counter2 = 0;Local_u8Counter2 < DAC_8_BIT;Local_u8Counter2++)
    {
        Local_u8BIT = GET_BIT(DAC_ARRAY[Local_u8Counter1], Local_u8Counter2);
        MGPIO_voidSetPinValue(Global_Dac[Local_u8Counter2], Local_u8BIT);
    }
    Local_u8Counter1++;
    if(Local_u8Counter1 == DAC_ARRAY_LENGTH)
    {
        Local_u8Counter1 = 0;
    }
}

/************************************************************************************************************/

void HDAC_voidInitDacSerial(GPIO_PinId_t Copy_DataPin, GPIO_PinId_t Copy_ShRegClkPin, GPIO_PinId_t Copy_StorageClkPin)
{
    MGPIO_voidSetPinMode(Copy_DataPin,       GPIO_OUTPUT_2M_PULL_UP_DN);
    MGPIO_voidSetPinMode(Copy_ShRegClkPin,   GPIO_OUTPUT_2M_PULL_UP_DN);
    MGPIO_voidSetPinMode(Copy_StorageClkPin, GPIO_OUTPUT_2M_PULL_UP_DN);
}

void HDAC_voidWriteVlueSerial(GPIO_PinId_t Copy_DataPin, GPIO_PinId_t Copy_ShRegClkPin, GPIO_PinId_t Copy_StorageClkPin)
{
    u8        Local_u8BIT;
    static u8 Local_u8Counter1 = 0;
    u8        Local_u8Counter2;
    
    for(Local_u8Counter2 = 0;Local_u8Counter2 < DAC_8_BIT;Local_u8Counter2++)
    {
        Local_u8BIT = GET_BIT(DAC_ARRAY[Local_u8Counter1], Local_u8Counter2);
        MGPIO_voidSetPinValue(Copy_DataPin, Local_u8BIT);
        MGPIO_voidSetPinValue(Copy_ShRegClkPin, HIGH);
        MGPIO_voidSetPinValue(Copy_ShRegClkPin, LOW);
    }
    MGPIO_voidSetPinValue(Copy_StorageClkPin, HIGH);
    MGPIO_voidSetPinValue(Copy_StorageClkPin, LOW);
    Local_u8Counter1++;
    if(Local_u8Counter1 == DAC_ARRAY_LENGTH)
    {
        Local_u8Counter1 = 0;
    }
}
/*************** END OF FUNCTIONS ***************************************************************************/
