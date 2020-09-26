/****************************************************************************
* Title                 :   DAC   
* Filename              :   DAC_config.h
* Author                :   Mohamed Hafez
* Origin Date           :   10/08/2020
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
*  10/8/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  DAC_DAC_config.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef DAC_CONFIG_H_
#define DAC_CONFIG_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

#define DAC_8_BIT           8
#define DAC_ARRAY           ARRAY_NAME          //change the ARRAY_NAME to your array name     
#define DAC_ARRAY_LENGTH    35500               //the length of the array that contain samplws value
/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define DAC_BIT_0           PINA0
#define DAC_BIT_1           PINA1
#define DAC_BIT_2           PINA2
#define DAC_BIT_3           PINA3
#define DAC_BIT_4           PINA4
#define DAC_BIT_5           PINA5
#define DAC_BIT_6           PINA6
#define DAC_BIT_7           PINA7

#endif /*File_H_*/

/*** End of File **************************************************************/
