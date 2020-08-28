/*******************************************************************************
* Title                 :   AFIO 
* Filename              :   AFIO_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   20/8/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  20/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file AFIO_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"
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
u8 AFIO_u8SetExtiConfiguration(u8 copy_u8Index, u8 copy_u8Line[], AFIO_ExtiPin copy_u8PortMap[])
{
    u8 Local_RegIndex = 0;
    u8 Local_Counter;
    for(Local_Counter = 0;Local_Counter < copy_u8Index;Local_Counter++)
    {
        Local_RegIndex = copy_u8Line[Local_Counter] / EXTI_LINE_4BIT;
        copy_u8Line[Local_Counter]  = copy_u8Line[Local_Counter] % EXTI_LINE_4BIT;
        AFIO->EXTICR[Local_RegIndex] &= ~ ((EXTI_CLR_LINE)                 << (copy_u8Line[Local_Counter] * EXTI_SHIFT_BIT));
        AFIO->EXTICR[Local_RegIndex] |=   ((copy_u8PortMap[Local_Counter]) << (copy_u8Line[Local_Counter] * EXTI_SHIFT_BIT));
    }
}


/*************** END OF FUNCTIONS ***************************************************************************/
