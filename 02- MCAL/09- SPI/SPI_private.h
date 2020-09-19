/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_private.h
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
/** @file  SPI_private.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct 
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

//Register Definition
//SPI1
#define SPI_1_BASE_ADDRESS   0X40013000
#define SPI1                ((volatile SPI_t * const)(SPI_1_BASE_ADDRESS))
//SPI2
/*#define SPI_2_BASE_ADDRESS   0X40005800
#define SPI2                ((volatile SPI_t * const)(SPI_2_BASE_ADDRESS))*/

#define CLR_REGISTER        0X00000000
/******************************************************************************
* Configuration Constants
*******************************************************************************/
//Bits Definition
//CR1 REG
#define CPHA       0
#define CPOL       1
#define MSTR       2
#define BR0        3
#define SPE        6
#define LSBFIRST   7
#define SSI        8
#define SSM        9
#define RXONLY     10
#define DFF        11
#define CRCNEXT    12
#define CRCEN      13
#define BIDIOE     14
#define BIDIMODE   15
//CR2 REG
#define RXDMAEN    0
#define TXDMAEN    1
#define SSOE       2
#define ERRIE      5
#define RXNEIE     6
#define TXEIE      7
//SR REG
#define RXNE       0
#define TXE        1
#define CHSIDE     2
#define UDR        3
#define CRCERR     4
#define MODF       5
#define OVR        6
#define BSY        7
/******************************************************************************
* Function Prototypes
*******************************************************************************/

#endif
/*** End of File **************************************************************/
