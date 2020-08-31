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
extern Queue_t ReadyQueue;
static u8 Global_u8LedStatus;
/******************************************************************************
* Function Definitions
*******************************************************************************/
void ledtog(void * x)
{
	if(Global_u8LedStatus == 0)
	{
	   GPIO_voidSetPinValue(PINA0,HIGH);
		  Global_u8LedStatus = 1;
	}
	else

    {
	   GPIO_voidSetPinValue(PINA0,LOW);
		 Global_u8LedStatus = 0;
	}
		
}

int main()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , IOPA_PERIPHERAL);
	
	GPIO_voidSetPinMode(PINA0,GPIO_OUTPUT_10M_PULL_UP_DN);
	GPIO_voidSetPinMode(PINA1,GPIO_OUTPUT_10M_PULL_UP_DN);
	GPIO_voidSetPinMode(PINA2,GPIO_OUTPUT_10M_PULL_UP_DN);
	
	SCHEDULER_voidInitScheduler(&ReadyQueue);
  SCHEDULER_u16CreateTask(&ledtog,0,500,0,NULL);
  SCHEDULER_voidStartScheduler();
  
  while(1)
  {
	   SCHEDULER_voidDispatchTasks(&ReadyQueue);
  }

}

/*************** END OF FUNCTIONS ***************************************************************************/
