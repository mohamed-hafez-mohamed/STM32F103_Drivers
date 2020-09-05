/****************************************************************************
* Title                 :   LEDMRX   
* Filename              :   LEDMRX_private.h
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
*  31/08/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  LEDMRX_private.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef LEDMRX_PRIVATE_H_
#define LEDMRX_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define BUS_FREQUENCY 1000000
#define LEDMRX_SHIFT_DELAY ((LEDMRX_COLS_NUMBER) * (((BUS_FREQUENCY / (LEDMRX_CONFIG_FRAME_RATE * LEDMRX_ROWS_NUMBER)) / 1000)))
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
static void HLEDMRX_voidDisable(void);
static void HLEDMRX_voidSetValues(u8 Copy_u8Value);

#endif
/*** End of File **************************************************************/
