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
static EXTI_voidPtrToFunction  EXTI_PtrFunction [EXTI_NUMBER_OF_EXTI];
static EXTI_voidPtrToParameter EXTI_PtrParameter[EXTI_NUMBER_OF_EXTI];

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
            case EXTI0_ID :EXTI_PtrFunction [EXTI0_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI0_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI1_ID :EXTI_PtrFunction [EXTI1_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI1_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI2_ID :EXTI_PtrFunction [EXTI2_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI2_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI3_ID :EXTI_PtrFunction [EXTI3_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI3_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI4_ID :EXTI_PtrFunction [EXTI4_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI4_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI5_ID :EXTI_PtrFunction [EXTI5_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI5_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI6_ID :EXTI_PtrFunction [EXTI6_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI6_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI7_ID :EXTI_PtrFunction [EXTI7_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI7_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI8_ID :EXTI_PtrFunction [EXTI8_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI8_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI9_ID :EXTI_PtrFunction [EXTI9_ID]=Copy_PtrFunction[Local_u8Counter]; EXTI_PtrParameter[EXTI9_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI10_ID:EXTI_PtrFunction[EXTI10_ID]=Copy_PtrFunction[Local_u8Counter];EXTI_PtrParameter[EXTI10_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI11_ID:EXTI_PtrFunction[EXTI11_ID]=Copy_PtrFunction[Local_u8Counter];EXTI_PtrParameter[EXTI11_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI12_ID:EXTI_PtrFunction[EXTI12_ID]=Copy_PtrFunction[Local_u8Counter];EXTI_PtrParameter[EXTI12_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI13_ID:EXTI_PtrFunction[EXTI13_ID]=Copy_PtrFunction[Local_u8Counter];EXTI_PtrParameter[EXTI13_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI14_ID:EXTI_PtrFunction[EXTI14_ID]=Copy_PtrFunction[Local_u8Counter];EXTI_PtrParameter[EXTI14_ID]=Copy_Parameter[Local_u8Counter];break;
            case EXTI15_ID:EXTI_PtrFunction[EXTI15_ID]=Copy_PtrFunction[Local_u8Counter];EXTI_PtrParameter[EXTI15_ID]=Copy_Parameter[Local_u8Counter];break;
       }
    }
}
/*********************************************ISRs For EXTIs*****************************************************************/

void EXTI0_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI0_ID](EXTI_PtrParameter[EXTI0_ID]);
    //SET_BIT(EXTI->PR, EXTI0_ID);
}

void EXTI1_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI1_ID](EXTI_PtrParameter[EXTI1_ID]);
    //SET_BIT(EXTI->PR, EXTI1_ID);
}
void EXTI2_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI2_ID](EXTI_PtrParameter[EXTI2_ID]);
    SET_BIT(EXTI->PR, EXTI2_ID);
}
void EXTI3_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI3_ID](EXTI_PtrParameter[EXTI3_ID]);
    SET_BIT(EXTI->PR, EXTI3_ID);
}
void EXTI4_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI4_ID](EXTI_PtrParameter[EXTI4_ID]);
    SET_BIT(EXTI->PR, EXTI4_ID);
}
void EXTI5_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI5_ID](EXTI_PtrParameter[EXTI5_ID]);
    SET_BIT(EXTI->PR, EXTI5_ID);
}
void EXTI6_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI6_ID](EXTI_PtrParameter[EXTI6_ID]);
    SET_BIT(EXTI->PR, EXTI6_ID);
}
void EXTI7_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI7_ID](EXTI_PtrParameter[EXTI7_ID]);
    SET_BIT(EXTI->PR, EXTI7_ID);
}
void EXTI8_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI8_ID](EXTI_PtrParameter[EXTI8_ID]);
    SET_BIT(EXTI->PR, EXTI8_ID);
}
void EXTI9_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI9_ID](EXTI_PtrParameter[EXTI9_ID]);
    SET_BIT(EXTI->PR, EXTI9_ID);
}
void EXTI10_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI10_ID](EXTI_PtrParameter[EXTI11_ID]);
    SET_BIT(EXTI->PR, EXTI10_ID);
}
void EXTI11_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI11_ID](EXTI_PtrParameter[EXTI11_ID]);
    SET_BIT(EXTI->PR, EXTI11_ID);
}
void EXTI12_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI12_ID](EXTI_PtrParameter[EXTI12_ID]);
    SET_BIT(EXTI->PR, EXTI12_ID);
}
void EXTI13_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI13_ID](EXTI_PtrParameter[EXTI13_ID]);
    SET_BIT(EXTI->PR, EXTI13_ID);
}
void EXTI14_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI14_ID](EXTI_PtrParameter[EXTI14_ID]);
    SET_BIT(EXTI->PR, EXTI14_ID);
}
void EXTI15_IRQHandler(void)
{
    EXTI_PtrFunction[EXTI15_ID](EXTI_PtrParameter[EXTI15_ID]);
    SET_BIT(EXTI->PR, EXTI15_ID);
}

/*************** END OF FUNCTIONS ***************************************************************************/
