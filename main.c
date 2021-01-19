/*******************************************************************************
* Title                 :   main  
* Filename              :   main.c
* Author                :   Mohamed Hafez
* Origin Date           :   04/08/2020
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
/** @file main.c
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
#include "STK_interface.h"
#include "SWITCH_interface.h"
#include "SCHEDULER_interface.h"

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
u8 Global_u8SwitchState = 0;
extern Queue_t ReadyQueue;
static u8 Global_u8LedStatus1;
static u8 Global_u8LedStatus2;
static u8 Global_u8LedStatus3;
/******************************************************************************
* Function Definitions
*******************************************************************************/
void ledtog1(void * x)
{
	if(Global_u8LedStatus1 == 0)
	{
	   GPIO_voidSetPinValue(PINA0,HIGH);
		  Global_u8LedStatus1 = 1;
	}
	else

    {
	   GPIO_voidSetPinValue(PINA0,LOW);
		 Global_u8LedStatus1 = 0;
	}
		
}

void ledtog2(void * x)
{
	if(Global_u8LedStatus2 == 0)
	{
	   GPIO_voidSetPinValue(PINA1,HIGH);
		  Global_u8LedStatus2 = 1;
	}
	else

    {
	   GPIO_voidSetPinValue(PINA1,LOW);
		 Global_u8LedStatus2 = 0;
	  }
		if(Global_u8SwitchState)
		 {
			 Global_u8SwitchState = 0;
			 SCHEDULER_voidDeleteTask(2, &ReadyQueue);
		 }
		
}

void ledtog3(void * x)
{
	if(Global_u8LedStatus3 == 0)
	{
	   GPIO_voidSetPinValue(PINA2,HIGH);
		  Global_u8LedStatus3 = 1;
	}
	else

    {
	   GPIO_voidSetPinValue(PINA2,LOW);
		 Global_u8LedStatus3 = 0;
	}
		
}

int main()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , IOPA_PERIPHERAL);
	RCC_voidEnableClock(RCC_APB2 , IOPB_PERIPHERAL);
	
	GPIO_voidSetPinMode(PINA0,GPIO_OUTPUT_10M_PULL_UP_DN);
	GPIO_voidSetPinMode(PINA1,GPIO_OUTPUT_10M_PULL_UP_DN);
	GPIO_voidSetPinMode(PINA2,GPIO_OUTPUT_10M_PULL_UP_DN);
	SWITCH_voidInit(PINB0);
	
	SCHEDULER_voidInitScheduler(&ReadyQueue);
	
  SCHEDULER_u8CreateTask(0, 0  , 1000, &ledtog1, NULL);
	SCHEDULER_u8CreateTask(1, 200, 200 , &ledtog2, NULL);
	SCHEDULER_u8CreateTask(2, 600, 400 , &ledtog3, NULL);
	
  SCHEDULER_voidStartScheduler();
  
  while(1)
  {
	  SCHEDULER_voidDispatchTasks(&ReadyQueue);
		Global_u8SwitchState = SWITCH_u8ReadStatus(PINB0);
  }

}

/*************** END OF FUNCTIONS ***************************************************************************/
