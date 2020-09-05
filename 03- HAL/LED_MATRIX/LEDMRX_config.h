/****************************************************************************
* Title                 :   LEDMRX   
* Filename              :   LEDMRX_config.h
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
/** @file  LEDMRX_LEDMRX_config.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef LEDMRX_CONFIG_H_
#define LEDMRX_CONFIG_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define LEDMRX_CONFIG_FRAME_RATE    50
/******************************************************************************
* Configuration Constants
*******************************************************************************/

//ROW PINS
#define LEDMRX_COL_0  PINA0
#define LEDMRX_COL_1  PINA1
#define LEDMRX_COL_2  PINA2
#define LEDMRX_COL_3  PINA3
#define LEDMRX_COL_4  PINA4
#define LEDMRX_COL_5  PINA5
#define LEDMRX_COL_6  PINA6
#define LEDMRX_COL_7  PINA7

//COLUMNS PINS
#define LEDMRX_ROW_0   PINB0
#define LEDMRX_ROW_1   PINB1
#define LEDMRX_ROW_2   PINB2
#define LEDMRX_ROW_3   PINB3
#define LEDMRX_ROW_4   PINB4
#define LEDMRX_ROW_5   PINB5
#define LEDMRX_ROW_6   PINB6
#define LEDMRX_ROW_7   PINB7

/*
LEDMRX_COL_CONTROL    
LEDMRX_ROW_CONTROL

LEDMRX_COL_ACTIVE_LOW    
LEDMRX_COL_ACTIVE_HIGH

LEDMRX_ROW_ACTIVE_LOW    
LEDMRX_ROW_ACTIVE_HIGH
*/

#define LEDMRX_CONTROL      LEDMRX_COL_CONTROL 
#define LEDMRX_ACTIVE       LEDMRX_COL_ACTIVE_LOW

#endif /*File_H_*/

/*** End of File **************************************************************/
