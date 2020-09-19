/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   16/09/2020
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
*  16/09/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  SPI_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define SPI_1_AFIO_MAPPING    0
/******************************************************************************
* Configuration Constants
*******************************************************************************/
//SPI1 PINS
#if SPI_1_AFIO_MAPPING == 0
#define SPI_1_MOSI_PIN        PINA7
#define SPI_1_MISO_PIN        PINA6
#define SPI_1_CLK_PIN         PINA5
#define SPI_1_NSS_PIN         PINA4
#endif
//SPI2 PINS
#define SPI_2_MOSI_PIN        PINB15
#define SPI_2_MISO_PIN        PINA14
#define SPI_2_CLK_PIN         PINB13
#define SPI_2_NSS_PIN         PINB12
//SPI Pins after Mapping
#if SPI_1_AFIO_MAPPING == 1
#define SPI_1_MOSI_PIN        PINB5
#define SPI_1_MISO_PIN        PINB4
#define SPI_1_CLK_PIN         PINB3
#define SPI_1_NSS_PIN         PINA15
#endif
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

void MSPI_voidInit(void);

u16  MSPI1_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit);
void MSPI1_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, void (*CallBack)(u8 Copy_u8DataToReceive));

u16  MSPI2_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit);
void MSPI2_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, void (*CallBack)(u8 Copy_u8DataToReceive));

#endif /*File_H_*/

/*** End of File **************************************************************/
