/****************************************************************************
* Title                 :   LEDMRX   
* Filename              :   LEDMRX_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   31/08/2020
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
*  31/8/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  LEDMRX_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef LEDMRX_INTERFACE_H_
#define LEDMRX_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define LEDMRX_ROWS_NUMBER 8
#define LEDMRX_COLS_NUMBER 8
/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define LEDMRX_COL_CONTROL       1
#define LEDMRX_ROW_CONTROL       2

#define LEDMRX_COL_ACTIVE_LOW    3
#define LEDMRX_COL_ACTIVE_HIGH   4

#define LEDMRX_ROW_ACTIVE_LOW    5
#define LEDMRX_ROW_ACTIVE_HIGH   6
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

void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplayFrame(u8 * Copy_u8Data);
void HLEDMRX_voidDisplayText(u8 * Copy_u8Data, u16 Copy_u16TextSize, u8 Copy_u8TimeDelay);
void HLEDMRX_voidPauseDisplayFrame(u8 * Copy_u8Data, u8 Copy_u8Time);


#endif /*File_H_*/

/*** End of File **************************************************************/
