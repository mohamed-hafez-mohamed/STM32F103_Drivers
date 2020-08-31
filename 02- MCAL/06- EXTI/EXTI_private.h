/****************************************************************************
* Title                 :   EXTI   
* Filename              :   EXTI_private.h
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
*  04/01/15   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  EXTI_private.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/


/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct 
{
     volatile u32 IMR;
     volatile u32 EMR;
     volatile u32 RTSR;
     volatile u32 FTSR;
     volatile u32 SWIER;
     volatile u32 PR;
}EXTI_t;


/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define  EXTI  ((volatile EXTI_t *)0x40010400)

#endif
/*** End of File **************************************************************/
