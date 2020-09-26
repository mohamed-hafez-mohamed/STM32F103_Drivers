/****************************************************************************
* Title                 :   TFT   
* Filename              :   TFT_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   21/9/2020
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
*  21/9/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  TFT_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
// Color definitions
#define TFT_BLACK_COLOR     0x0000
#define TFT_BLUE_COLOR      0x001F
#define TFT_RED_COLOR       0xF800
#define TFT_GREEN_COLOR     0x07E0
#define TFT_CYAN_COLOR      0x07FF
#define TFT_MAGENTA_COLOR   0xF81F
#define TFT_YELLOW_COLOR    0xFFE0
#define TFT_WHITE_COLOR     0xFFFF
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

void HTFT_voidInit(void);

void HTFT_voidDisplayImage(const u16 * Copy_u16Image);

u8 HTFT_u8DrawPixel(u16 Copy_u16Width, u16 Copy_u16Height, u16  Copy_u16Color);
u8 HTFT_u8FillRectangle(u16 Copy_u16Width1, u16 Copy_u16Width2, u16 Copy_u16Height1, u16 Copy_u16Height2, u16  Copy_u16Color);
u8 HTFT_u8FillColour(u16  Copy_u16Color);
u8 HTFT_u8DrawFastVLine(u16 Copy_u16Width1, u16 Copy_u16Height1, u16 Copy_u16Height2, u16  Copy_u16Color);
u8 HTFT_u8DrawFastHLine(u16 Copy_u16Width1, u16 Copy_u16Width2,  u16 Copy_u16Height1, u16  Copy_u16Color);
u8 HTFT_u8DrawCircle(s16 Copy_s16Width, s16 Copy_s16Height, s16 Copy_s16Radius,u16 Copy_u16Color);
u8 HTFT_u8DrawRectangle(u16 Copy_u16Width1, u16 Copy_u16Width2, u16 Copy_u16Height1, u16 Copy_u16Height2, u16  Copy_u16Color);
u8 HTFT_u8FillRect(u16 Copy_u16Width1, u16 Copy_u16Width2, u16 Copy_u16Height1, u16 Copy_u16Height2, u16  Copy_u16Color);

u8 HTFT_u8DrawChar(u8 Copy_u8Width, u8 Copy_u8Height, u8 Copy_u8Char,u16 Copy_u16Color, u16 Copy_u16Bg, u16 Copy_u16Size);
u8 HTFT_u8DrawText(u8 Copy_u8Width, u8 Copy_u8Height, u8 * Copy_u8Text,u16 Copy_u16Color, u16 Copy_u16Bg, u16 Copy_u16Size);
#endif /*File_H_*/

/*** End of File **************************************************************/
