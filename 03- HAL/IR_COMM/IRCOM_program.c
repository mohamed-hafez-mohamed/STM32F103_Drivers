/*******************************************************************************
* Title                 :   IRCOM 
* Filename              :   IRCOM_program.c
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
/** @file IRCOM_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdlib.h>
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "IRCOM_interface.h"
#include "IRCOM_config.h"
#include "IRCOM_private.h"

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
//volatile u8 flag;
//volatile u32 frameDta[50] {0};
//volatile i
//volatile data

static volatile u8   u8StartFlag          = 0;
static volatile u32  u32Frame[50]         = {0};
static volatile u8   u8FallingEdgeCounter = 0;
static volatile u8   u8Data               = 0;
static          u8   u8DataKey            = UNLOCKED;
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void IRCOM_voidInit(GPIO_PinId_t Copy_PinId)
{
    EXTI_Lines_t Local_LineId;
    AFIO_ExtiPin Local_PortPinId;
    EXTI_InterruptId_t Local_u8ExtiId;
    GPIO_voidSetPinMode(Copy_PinId, GPIO_INPUT_FLOATING);
    if(Copy_PinId >= GPIO_PORTA_ENTRY && Copy_PinId <= GPIO_PORTA_END)
    {
        Local_LineId    = Copy_PinId;
        Local_u8ExtiId  = Copy_PinId;
        Local_PortPinId = LINE_PIN_A;
    }
    else if(Copy_PinId >= GPIO_PORTB_ENTRY && Copy_PinId <= GPIO_PORTB_END)
    {
        Copy_PinId   -= GPIO_ADJUST_PORTB_PIN;
        Local_LineId    = Copy_PinId;
        Local_u8ExtiId  = Copy_PinId;
        Local_PortPinId = LINE_PIN_B;
    }
    else if(Copy_PinId >= GPIO_PORTC_ENTRY && Copy_PinId <= GPIO_PORTC_END)
    {
        Copy_PinId   -= GPIO_ADJUST_PORTC_PIN;
        Local_LineId    = Copy_PinId;
        Local_u8ExtiId  = Copy_PinId;
        Local_PortPinId = LINE_PIN_C;
    }

  EXTI_Lines_t lines[1] = {Local_LineId};
	AFIO_ExtiPin ports[1] = {Local_PortPinId};
	EXTI_InterruptId_t     InterruptsId[1]   = {Local_u8ExtiId};	
	EXTI_voidPtrToFunction InterruptsFunc[1] = {&IRCOM_voidGetFrame};
	void * InterruptsParm[1]                 = {NULL};
    AFIO_u8SetExtiConfiguration(1,lines,ports);
	EXTI_u8Init(1, lines, FALLING);
	EXTI_u8EnableEXTI(1, lines);
	NVIC_u8SetPriority(EXTI0, 0b00, 0b00);
	NVIC_u8EnableInt(EXTI0);
  EXTI_u8InitISRWithFunction(1, InterruptsId, InterruptsFunc, InterruptsParm);
}

static void IRCOM_voidGetFrame(void * Copy_Param)
{
    if (u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle_ms(500, IRCOM_voidParseFrame, NULL);
		u8StartFlag = 1;
	}

	else
	{
		u32Frame[u8FallingEdgeCounter++] = MSTK_u32GetElapsedTime_us();
		MSTK_voidSetIntervalSingle_ms(500, IRCOM_voidParseFrame, NULL);
		u8FallingEdgeCounter++;
	}
}

static void IRCOM_voidParseFrame(void * Copy_Param)
{
    u8 Local_u8Counter;

    if ( (u32Frame[IRCOM_START_BIT] >= IRCOM_START_BIT_START_RANGE) && (u32Frame[IRCOM_START_BIT] <= IRCOM_START_BIT_END_RANGE) )
	{
		for (Local_u8Counter = 0;Local_u8Counter < IRCOM_DATA_BIT_NUMBER;Local_u8Counter++)
		{
			if (  (u32Frame[IRCOM_DATA_START_BIT+Local_u8Counter] >= IRCOM_HIGH_BIT_START_RANGE) && (u32Frame[IRCOM_DATA_START_BIT+Local_u8Counter] <=IRCOM_HIGH_BIT_END_RANGE) )
			{
                if(u8DataKey == UNLOCKED)
                {
                    u8DataKey = LOCKED;
                    SET_BIT(u8Data,Local_u8Counter);
                }
                u8DataKey = UNLOCKED;
			}

			else
			{
				if(u8DataKey == UNLOCKED)
                {
                    u8DataKey = LOCKED;
                    CLR_BIT(u8Data,Local_u8Counter);
                }
                u8DataKey = UNLOCKED;
			}
		}
	}
	else
	{
		/* Invalid Frame */
	}

	u8StartFlag            = 0;
	u32Frame[0]            = 0;
	u8FallingEdgeCounter   = 0;
}

u8 IRCOM_U8ReturnData(void)
{
    u8 Local_u8Data;
    if(u8DataKey == UNLOCKED)
    {
        u8DataKey    = LOCKED;
        Local_u8Data = u8Data;
    }
    u8DataKey    = UNLOCKED;
    return Local_u8Data;
}
/*************** END OF FUNCTIONS ***************************************************************************/
