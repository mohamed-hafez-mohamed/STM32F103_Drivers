/****************************************************************************
* Title                 :   LCD   
* Filename              :   LCD_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   22/09/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None
*
*****************************************************************************/
/****************************************************************************
* Doxygen C Template 
*
*****************************************************************************/
/*************** INTERFACE CHANGE LIST **************************************
*
*    Date    Version   Author          Description 
*  22/09/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  LCD_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define LCD_DECIMAL                   10
#define LCD_NUMBER_TYPE_AFTER_POINT   100
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void HLCD_voidInit(void);
void HLCD_voidCMD(u8 Copy_u8Command);
void HLCD_voidSetCursor(u8 Copy_u8Row, u8 Copy_u8Col);
void HLCD_void_ClearSreen(void);
void HLCD_voidTurnOffDisplay(void);
void HLCD_voidWriteChar(u8 Copy_u8Character);
void HLCD_voidWriteString(u8 * Copy_u8String);
void HLCD_voidWriteIntNum(u8 Copy_u8Number);
void HLCD_void_WriteFloatNum(float Copy_floatNumber);

#endif /*File_H_*/

/*** End of File **************************************************************/
