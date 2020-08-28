/****************************************************************************
* Title                 :   SEGMENT7   
* Filename              :   SEGMENT7_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   17/08/2020
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
*  17/8/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  SEGMENT7_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef SEGMENT7_INTERFACE_H_
#define SEGMENT7_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

#define SEGMENT7_SEG_PINS     7
#define SEGMENT7_BCD_PINS     4
/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/


	
/******************************************************************************
* Typedefs
*******************************************************************************/

typedef enum
{
    COMMON_CATHODE = 0,
    COMMON_ANODE
}SEGEMENT7_Mode_t;

typedef enum
{
    ZERO_SEG     = 0b0111111,
    ONE_SEG      = 0b0000110,
    TWO_SEG      = 0b1011011,
    THREE_SEG    = 0b1001111,
    FOUR_SEG     = 0b1100110,
    FIVE_SEG     = 0b1101101,
    SIX_SEG      = 0b1111101,
    SEVEN_SEG    = 0b0000111,
    EIGHT_SEG    = 0b1111111,
    NINE_SEG     = 0b1101111,
    POINT_SEG    = 10
}SEGEMENT7_Number_t;

typedef enum
{
    ZERO_BCD    = 0b0000,
    ONE_BCD     = 0b0001,
    TWO_BCD     = 0b0010,
    THREE_BCD   = 0b0011,
    FOUR_BCD    = 0b0100,
    FIVE_BCD    = 0b0101,
    SIX_BCD     = 0b0110,
    SEVEN_BCD   = 0b0111,
    EIGHT_BCD   = 0b1000,
    NINE_BCD    = 0b1001,
}SEGEMENT7_NumberBcd_t;

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void SEGEMENT7_voidNormInit(u8 copy_u8PinsArray[], SEGEMENT7_Mode_t copy_Mode);

void SEGEMENT7_voidBcdInit(u8 copy_u8PinsArray[]);

void SEGEMENT7_voidNormDisplay(u8 copy_u8PinsArray[], SEGEMENT7_Mode_t copy_Mode, SEGEMENT7_Number_t copy_Number);

void SEGEMENT7_voidBcdDisplay(u8 copy_u8PinsArray[], SEGEMENT7_NumberBcd_t copy_Number);

#endif /*File_H_*/

/*** End of File **************************************************************/
