/****************************************************************************
* Title                 :   IRCOM   
* Filename              :   IRCOM_private.h
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
*  04/08/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  IRCOM_private.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef IRCOM_PRIVATE_H_
#define IRCOM_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define UNLOCKED                    0
#define LOCKED                      1
#define IRCOM_START_BIT             0
#define IRCOM_DATA_BIT_NUMBER       8
#define IRCOM_DATA_START_BIT        17
#define IRCOM_START_BIT_START_RANGE 10000
#define IRCOM_START_BIT_END_RANGE   14000
#define IRCOM_HIGH_BIT_START_RANGE  2000
#define IRCOM_HIGH_BIT_END_RANGE    2300
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

static void IRCOM_voidGetFrame(void * Copy_Param);

static void IRCOM_voidParseFrame(void * Copy_Param);
#endif
/*** End of File **************************************************************/
