/****************************************************************************
* Title                 :   SEGMENT7   
* Filename              :   SEGMENT7_config.h
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
/** @file  SEGMENT7_SEGMENT7_config.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef SEGMENT7_CONFIG_H_
#define SEGMENT7_CONFIG_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/
/*!<***************************Modes Definitions*******************************/
/*
   //GPIO Input 
AFIO_INPUT_ANALOG          
GPIO_INPUT_FLOATING        
GPIO_INPUT_PULL_UP_DN       
	//10M modes*******************************************
GPIO_OUTPUT_10M_PULL_UP_DN  
GPIO_OUTPUT_10M_OPEN_DRAIN  
AFIO_OUTPUT_10M_PULL_UP_DN  
AFIO_OUTPUT_10M_OPEN_DRAIN  
//2M modes************************************************
GPIO_OUTPUT_2M_PULL_UP_DN   
GPIO_OUTPUT_2M_OPEN_DRAIN   
AFIO_OUTPUT_2M_PULL_UP_DN  
AFIO_OUTPUT_2M_OPEN_DRAIN  
//<50M modes**********************************************
GPIO_OUTPUT_50M_PULL_UP_DN  
GPIO_OUTPUT_50M_OPEN_DRAIN  
AFIO_OUTPUT_50M_PULL_UP_DN  
AFIO_OUTPUT_50M_OPEN_DRAIN  
GPIO_PIN_MODE;*/

#define SEGMENT7_PIN_MODE GPIO_OUTPUT_10M_PULL_UP_DN
#endif /*File_H_*/

/*** End of File **************************************************************/
