/*******************************************************************************
* Title                 :   SWITCH 
* Filename              :   SWITCH_program.c
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
*  04/01/15   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file SWITCH_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SWITCH_interface.h"
#include "SWITCH_config.h"
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
/******************************************************************************
* Function : Dio_Init()
*//** 
* \b Description:
*
* This function is used to initialize the Dio based on the configuration table
*  defined in dio_cfg module.  
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the configuration
* table will be returned.
*
* @return 		A pointer to the configuration table.
*
* \b Example Example:
* @code
* 	const Dio_ConfigType *DioConfig = Dio_GetConfig();
*
* 	Dio_Init(DioConfig);
* @endcode
*
* @see Dio_Init
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/

void SWITCH_voidInit(GPIO_PinId_t copy_u8PinId)
{
    GPIO_voidSetPinMode(copy_u8PinId, SWITCH_PIN_MODE);
}

u8 SWITCH_u8ReadStatus(GPIO_PinId_t copy_u8PinId)
{
    return GPIO_u8GetPinValue(copy_u8PinId);
}

/*************** END OF FUNCTIONS ***************************************************************************/
