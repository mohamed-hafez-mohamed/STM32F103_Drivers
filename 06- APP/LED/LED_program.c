/*******************************************************************************
* Title                 :   LED 
* Filename              :   LED_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   17/8/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  17/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file LED_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/
extern "c"
{
    #include "STD_TYPES.h"
    #include "BIT_MATH.h"
    #include "RCC_interface.h"
}	
#include "Gpio.h"
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
int main()
{
   Gpio l_gpio;
   pin l_pinA0 = l_gpio.get_pin(PA0);
   pin l_pinA1 = l_gpio.get_pin(PA1);
   static u8 l_switchStatus = 0;
   extern "c"
   {
       RCC_voidInitSysClock();
       RCC_voidEnableClock(RCC_APB2 , IOPA_PERIPHERAL);
       RCC_voidEnableClock(RCC_APB2 , IOPB_PERIPHERAL);
   }
   l_pinA0.set_direction(Input);
   l_pinA1.set_direction(Output);
    while(1)
    {
        l_switchStatus = l_pinA0.get_pin_value();
		if(l_switchStatus != 0)
		{
		   l_switchStatus = 0;
		   l_pinA1.toggle_pin();
		}
    }
    return 0;
}

/*************** END OF FUNCTIONS ***************************************************************************/
