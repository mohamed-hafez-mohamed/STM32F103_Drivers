/*******************************************************************************
* Title                 :   EXTI 
* Filename              :   EXTI_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   25/8/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  25/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file EXTI_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

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
static EXTI_voidPtrToFunction EXTI0_PtrFunction;
static EXTI_voidPtrToFunction EXTI1_PtrFunction;
static EXTI_voidPtrToFunction EXTI2_PtrFunction;
static EXTI_voidPtrToFunction EXTI3_PtrFunction;
static EXTI_voidPtrToFunction EXTI4_PtrFunction;
static EXTI_voidPtrToFunction EXTI5_PtrFunction;
static EXTI_voidPtrToFunction EXTI6_PtrFunction;
static EXTI_voidPtrToFunction EXTI7_PtrFunction;
static EXTI_voidPtrToFunction EXTI8_PtrFunction;
static EXTI_voidPtrToFunction EXTI9_PtrFunction;
static EXTI_voidPtrToFunction EXTI10_PtrFunction;
static EXTI_voidPtrToFunction EXTI11_PtrFunction;
static EXTI_voidPtrToFunction EXTI12_PtrFunction;
static EXTI_voidPtrToFunction EXTI13_PtrFunction;
static EXTI_voidPtrToFunction EXTI14_PtrFunction;
static EXTI_voidPtrToFunction EXTI15_PtrFunction;

void * EXTI0_Parameter;
void * EXTI1_Parameter;
void * EXTI2_Parameter;
void * EXTI3_Parameter;
void * EXTI4_Parameter;
void * EXTI5_Parameter;
void * EXTI6_Parameter;
void * EXTI7_Parameter;
void * EXTI8_Parameter;
void * EXTI9_Parameter;
void * EXTI10_Parameter;
void * EXTI11_Parameter;
void * EXTI12_Parameter;
void * EXTI13_Parameter;
void * EXTI14_Parameter;
void * EXTI15_Parameter;
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

u8 EXTI_u8Init(u8 copy_LineIndex, EXTI_Lines_t copy_Line[], EXTI_IntSignalSensitive_t copy_Mode)
{
    u8 Local_u8lines;
    switch(copy_Mode)
    {
        case RISING    :
            for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
            {
                 SET_BIT(EXTI->RTSR,copy_Line[Local_u8lines]);
            }
        break;
        case FALLING   :
           for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
           {
                 SET_BIT(EXTI->FTSR,copy_Line[Local_u8lines]);
           }
        break;
        case ON_CHANGE :
           for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
           {
                 SET_BIT(EXTI->RTSR,copy_Line[Local_u8lines]);
                 SET_BIT(EXTI->FTSR,copy_Line[Local_u8lines]);
           }
        break;
        default        :
            /*!<TODO: Error Code */
        break;
    }
}

u8 EXTI_u8EnableEXTI(u8 copy_LineIndex, EXTI_Lines_t copy_Line[])
{
    u8 Local_u8lines;
    for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
    {
        SET_BIT(EXTI->IMR,copy_Line[Local_u8lines]);
    }   
}

u8 EXTI_u8DisableEXTI(u8 copy_LineIndex, EXTI_Lines_t copy_Line[])
{
    u8 Local_u8lines;
    for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
    {
        CLR_BIT(EXTI->IMR,copy_Line[Local_u8lines]);
    }   
}

u8 EXTI_u8SwTrigger(u8 copy_LineIndex, EXTI_Lines_t copy_Line[])
{
    u8 Local_u8lines;
    for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
    {
        SET_BIT(EXTI->SWIER,copy_Line[Local_u8lines]);
    } 
}

u8 EXTI_u8SetSignalLatch(u8 copy_LineIndex, EXTI_Lines_t copy_Line[], EXTI_IntSignalSensitive_t copy_Mode)
{
    u8 Local_u8lines;
    switch(copy_Mode)
    {
        case RISING    :
            for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
            {
                 SET_BIT(EXTI->RTSR,copy_Line[Local_u8lines]);
            }
        break;
        case FALLING   :
           for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
           {
                 SET_BIT(EXTI->FTSR,copy_Line[Local_u8lines]);
           }
        break;
        case ON_CHANGE :
           for(Local_u8lines = 0;Local_u8lines < copy_LineIndex;Local_u8lines++)
           {
                 SET_BIT(EXTI->RTSR,copy_Line[Local_u8lines]);
                 SET_BIT(EXTI->FTSR,copy_Line[Local_u8lines]);
           }
        break;
        default        :
            /*!<TODO: Error Code */
        break;
    }
}

u8 EXTI_u8InitISRWithFunction(u8 Copy_Index, EXTI_InterruptId_t Copy_ExtiId[], EXTI_voidPtrToFunction Copy_PtrFunction[], void * Copy_Parameter[])
{
    u8 Local_u8Counter;
    for(Local_u8Counter = 0;Local_u8Counter < Copy_Index;Local_u8Counter++)
    {
       switch(Copy_ExtiId[Local_u8Counter])
       {
            case EXTI0_ID:  EXTI0_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI0_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI1_ID:  EXTI1_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI1_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI2_ID:  EXTI2_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI2_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI3_ID:  EXTI3_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI3_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI4_ID:  EXTI4_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI4_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI5_ID:  EXTI5_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI5_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI6_ID:  EXTI6_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI6_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI7_ID:  EXTI7_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI7_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI8_ID:  EXTI8_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI8_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI9_ID:  EXTI9_PtrFunction  = Copy_PtrFunction[Local_u8Counter]; EXTI9_Parameter  = Copy_Parameter[Local_u8Counter];break;
            case EXTI10_ID: EXTI10_PtrFunction = Copy_PtrFunction[Local_u8Counter]; EXTI10_Parameter = Copy_Parameter[Local_u8Counter];break;
            case EXTI11_ID: EXTI11_PtrFunction = Copy_PtrFunction[Local_u8Counter]; EXTI11_Parameter = Copy_Parameter[Local_u8Counter];break;
            case EXTI12_ID: EXTI12_PtrFunction = Copy_PtrFunction[Local_u8Counter]; EXTI12_Parameter = Copy_Parameter[Local_u8Counter];break;
            case EXTI13_ID: EXTI13_PtrFunction = Copy_PtrFunction[Local_u8Counter]; EXTI13_Parameter = Copy_Parameter[Local_u8Counter];break;
            case EXTI14_ID: EXTI14_PtrFunction = Copy_PtrFunction[Local_u8Counter]; EXTI14_Parameter = Copy_Parameter[Local_u8Counter];break;
            case EXTI15_ID: EXTI15_PtrFunction = Copy_PtrFunction[Local_u8Counter]; EXTI15_Parameter = Copy_Parameter[Local_u8Counter];break;
       }
    }
}
/*********************************************ISRs For EXTIs*****************************************************************/

void EXTI0_IRQHandler(void)
{
    EXTI0_PtrFunction(EXTI0_Parameter);
}

void EXTI1_IRQHandler(void)
{
    EXTI1_PtrFunction(EXTI1_Parameter);
}
void EXTI2_IRQHandler(void)
{
    EXTI2_PtrFunction(EXTI2_Parameter);
}
void EXTI3_IRQHandler(void)
{
    EXTI3_PtrFunction(EXTI3_Parameter);
}
void EXTI4_IRQHandler(void)
{
    EXTI4_PtrFunction(EXTI4_Parameter);
}
void EXTI5_IRQHandler(void)
{
    EXTI5_PtrFunction(EXTI5_Parameter);
}
void EXTI6_IRQHandler(void)
{
    EXTI6_PtrFunction(EXTI6_Parameter);
}
void EXTI7_IRQHandler(void)
{
    EXTI7_PtrFunction(EXTI7_Parameter);
}
void EXTI8_IRQHandler(void)
{
    EXTI8_PtrFunction(EXTI8_Parameter);
}
void EXTI9_IRQHandler(void)
{
    EXTI9_PtrFunction(EXTI9_Parameter);
}
void EXTI10_IRQHandler(void)
{
    EXTI10_PtrFunction(EXTI10_Parameter);
}
void EXTI11_IRQHandler(void)
{
    EXTI11_PtrFunction(EXTI12_Parameter);
}
void EXTI12_IRQHandler(void)
{
    EXTI12_PtrFunction(EXTI12_Parameter);
}
void EXTI13_IRQHandler(void)
{
    EXTI13_PtrFunction(EXTI13_Parameter);
}
void EXTI14_IRQHandler(void)
{
    EXTI14_PtrFunction(EXTI14_Parameter);
}
void EXTI15_IRQHandler(void)
{
    EXTI15_PtrFunction(EXTI15_Parameter);
}

/*************** END OF FUNCTIONS ***************************************************************************/
