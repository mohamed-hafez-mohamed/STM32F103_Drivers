/****************************************************************************
* Title                 :   KEYPAD   
* Filename              :   KEYPAD_config.h
* Author                :   Mohamed Hafez
* Origin Date           :   13/09/2020
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
*  13/09/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  KEYPAD_KEYPAD_config.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define ROWS_NUMBER	    4
#define COLUMS_NUMBER	4

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/**
* user should change the numbers of rows and colmus
* confg the buttons in it's poisition
* min values for row and colum 2 * 2
* max values for row and colum 4 * 4
* it can be easily add more rows and colums
*/


// the dirctives use to change the .c code to adjust to selected key pad
// don't touch it
#if ROWS_NUMBER == 3
#define _ROW_3
//Row Pins
#define ROW_0_PIN
#define ROW_1_PIN
#define ROW_2_PIN
#endif

#if ROWS_NUMBER == 4
#define _ROW_4
//Row Pins
#define ROW_0_PIN   PINB0
#define ROW_1_PIN   PINB1
#define ROW_2_PIN   PINB2
#define ROW_3_PIN   PINB3
#endif

#if COLUMS_NUMBER == 3
#define _COLUM_3
//Col Pins
#define COL_0_PIN
#define COL_1_PIN
#define COL_2_PIN
#endif

#if COLUMS_NUMBER == 4
//Col Pins
#define _COLUM_4
#define COL_0_PIN  PINB4 
#define COL_1_PIN  PINB5
#define COL_2_PIN  PINB6
#define COL_3_PIN  PINB7
#endif

#ifdef _COLUM_4
//COL1
#define K_0_0          '7' //Raw 0
#define K_1_0          '4' //Raw 1
#define K_2_0          '1' //Raw 2
#define K_3_0          '*' //Raw 3
//COL2
#define K_0_1          '8' //Raw 0
#define K_1_1          '5' //Raw 1
#define K_2_1          '2' //Raw 2
#define K_3_1          '0' //Raw 3
//COL3
#define K_0_2          '9' //Raw 0
#define K_1_2          '6' //Raw 1
#define K_2_2          '3' //Raw 2
#define K_3_2          '=' //Raw 3
//COL4
#define K_0_3          '/' //Raw 0
#define K_1_3          '*' //Raw 1
#define K_2_3          '-' //Raw 2
#define K_3_3          '+' //Raw 3
#endif 

#ifdef _COLUM_3
//COL1
#define K_0_0          '1' //Raw 0
#define K_1_0          '4' //Raw 1
#define K_2_0          '7' //Raw 2
#define K_3_0          '*' //Raw 3
//COL2
#define K_0_1          '2' //Raw 0
#define K_1_1          '5' //Raw 1
#define K_2_1          '8' //Raw 2
#define K_3_1          '0' //Raw 3
//COL3
#define K_0_2          '3' //Raw 0
#define K_1_2          '6' //Raw 1
#define K_2_2          '9' //Raw 2
#define K_3_2          '#' //Raw 3
#endif

#endif /*File_H_*/

/*** End of File **************************************************************/
