/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_config.h
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
/** @file  SPI_SPI_config.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define SPI_1_USED      1
#define SPI_2_USED      2
#define ALL_SPI_USED    3

#define SPI_MODE_SLAVE  0
#define SPI_MODE_MASTER 1
/******************************************************************************
* Configuration Constants
*******************************************************************************/
/**
 * Choose the number of SPI
 * NUMBER_OF_SPI_USED = SPI_1_USED to use SPI 1
 * NUMBER_OF_SPI_USED = SPI_2_USED to use SPI 2
 * NUMBER_OF_SPI_USED = ALL_SPI_USED to use SPI 1 and SPI2
 * */
#define NUMBER_OF_SPI_USED       SPI_1_USED

/**
 * Choose The SPI Mode(MASTER OR SLAVE) 
 * SPI_1_MODE 
 * SPI_MODE_MASTER: MASTER
 * SPI_MODE_SLAVE: SLAVE
 * SPI_2_MODE 
 * SPI_MODE_MASTER: MASTER
 * SPI_MODE_SLAVE: SLAVE 
 */
#define SPI_1_MODE   SPI_MODE_MASTER
#define SPI_2_MODE   SPI_MODE_SLAVE

/**
 *  Set The number Of Slaves and The NSS Pins
 */
#define SPI_1_NUMBER_OF_SLAVES  1
#define SPI_2_NUMBER_OF_SLAVES  1

/*Any GPIO Pins*/
#define SPI_1_NSS_1_PIN         PINA2
#define SPI_2_NSS_1_PIN         PINA15
/*Add Slaves Pins*/
#if   NUMBER_OF_SPI_USED == SPI_1_USED
#if  SPI_1_MODE == SPI_MODE_MASTER
static u8 SPI1_SelectSlavePins[SPI_1_NUMBER_OF_SLAVES] = {SPI_1_NSS_1_PIN};
#endif
#elif NUMBER_OF_SPI_USED == SPI_2_USED
#if SPI_2_MODE == SPI_MODE_MASTER
static u8 SPI2_SelectSlavePins[SPI_2_NUMBER_OF_SLAVES];
#endif
#elif NUMBER_OF_SPI_USED == ALL_SPI_USED
#if  SPI_1_MODE == SPI_MODE_MASTER
static u8 SPI1_SelectSlavePins[SPI_1_NUMBER_OF_SLAVES] = {SPI_1_NSS_1_PIN};
#endif
#if SPI_2_MODE == SPI_MODE_MASTER
static u8 SPI2_SelectSlavePins[SPI_2_NUMBER_OF_SLAVES];
#endif
#endif

/*REG CR2 Configuration*/
/**
 * Choose your configuration
 * BIDIMODE: Bidirectional data mode enable
 * 0: 2-line unidirectional data mode selected
 * 1: 1-line bidirectional data mode selected
 * BIDIOE: Output enable in bidirectional mode
 * This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
 * 0: Output disabled (receive-only mode)
 * 1: Output enabled (transmit-only mode)
 * CRCEN: Hardware CRC calculation enable
 * 0: CRC calculation disabled
 * 1: CRC calculation enabled
 * CRCNEXT: CRC transfer next
 * 0: Data phase (no CRC phase)
 * 1: Next transfer is CRC (CRC phase)
 * DFF: Data frame format
 * 0: 8-bit data frame format is selected for transmission/reception
 * 1: 16-bit data frame format is selected for transmission/reception
 * RXONLY: Receive only
 * 0: Full duplex (Transmit and receive)
 * 1: Output disabled (Receive-only mode)
 * SSM: Software slave management
 * When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
 * 0: Software slave management disabled
 * 1: Software slave management enabled
 * SSI: Internal slave select
 * This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
 * NSS pin and the IO value of the NSS pin is ignored.
 * LSBFIRST: Frame format
 * 0: MSB transmitted first
 * 1: LSB transmitted first
 * SPE: SPI enable
 * 0: Peripheral disabled
 * 1: Peripheral enabled
 * BR: Baud rate control
 * 000: fPCLK/2
 * 001: fPCLK/4
 * 010: fPCLK/8
 * 011: fPCLK/16
 * 100: fPCLK/32
 * 101: fPCLK/64
 * 110: fPCLK/128
 * 111: fPCLK/256
 * MSTR: Master selection
 * 0: Slave configuration
 * 1: Master configuration
 * CPOL: Clock polarity
 * 0: CK to 0 when idle
 * 1: CK to 1 when idle
 * CPHA: Clock phase
 * 0: The first clock transition is the first data capture edge
 * 1: The second clock transition is the first data capture edge
 * */

/*REG CR2 Configuration*/
/**
 * Choose your configuration
 * TXEIE: Tx buffer empty interrupt enable
 * 0: TXE interrupt masked
 * 1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
 * RXNEIE: RX buffer not empty interrupt enable
 * 0: RXNE interrupt masked
 * 1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
 * ERRIE: Error interrupt enable
 * This bit controls the generation of an interrupt when an error condition occurs (CRCERR,
 * OVR, MODF in SPI mode and UDR, OVR in I2S mode).
 * 0: Error interrupt is masked
 * 1: Error interrupt is enabled
 * SSOE: SS output enable
 * 0: SS output is disabled in master mode and the cell can work in multimaster configuration
 * 1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work in a multimaster environment.
 * TXDMAEN: Tx buffer DMA enable
 * When this bit is set, the DMA request is made whenever the TXE flag is set.
 * 0: Tx buffer DMA disabled
 * 1: Tx buffer DMA enabled
 * RXDMAEN: Rx buffer DMA enable
 * When this bit is set, the DMA request is made whenever the RXNE flag is set.
 * 0: Rx buffer DMA disabled
 * 1: Rx buffer DMA enabled
 * */

#ifdef NUMBER_OF_SPI_USED == SPI_1_USED
/*REG CR1 Configuration*/
#define SPI1_BIDIMODE         0
#define SPI1_BIDIOE           0
#define SPI1_CRCEN            0
#define SPI1_CRCNEXT          0
#define SPI1_FRAME_FORMAT     1
#define SPI1_RXONLY           0
#define SPI1_SSM              0
#define SPI1_SSI              0
#define SPI1_LSBFIRST         1
#define SPI1_SPE              1
#define SPI1_BR               000
#define SPI1_MSTR             1
#define SPI1_CPOL             0
#define SPI1_CPHA             1
/*REG CR2 Configuration*/
#define SPI1_TXEIE            0
#define SPI1_RXNEIE           0
#define SPI1_ERRIE            0
#define SPI1_SSOE             0
#define SPI1_TXDMAEN          0
#define SPI1_RXDMAEN          0

#elif NUMBER_OF_SPI_USED == SPI_2_USED
/*REG CR1 Configuration*/
#define SPI2_BIDIMODE         0
#define SPI2_BIDIOE           0
#define SPI2_CRCEN            0
#define SPI2_CRCNEXT          0
#define SPI2_FRAME_FORMAT     0
#define SPI2_RXONLY           0
#define SPI2_SSM              0
#define SPI2_SSI              0
#define SPI2_LSBFIRST         1
#define SPI2_SPE              1
#define SPI2_BR               000
#define SPI2_MSTR             1
#define SPI2_CPOL             0
#define SPI2_CPHA             1
/*REG CR2 Configuration*/
#define SPI2_TXEIE            1
#define SPI2_RXNEIE           1
#define SPI2_ERRIE            0
#define SPI2_SSOE             0
#define SPI2_TXDMAEN          0
#define SPI2_RXDMAEN          0
#elif NUMBER_OF_SPI_USED == ALL_SPI_USED
/*REG CR1 Configuration*/
#define SPI1_BIDIMODE         0
#define SPI1_BIDIOE           0
#define SPI1_CRCEN            0
#define SPI1_CRCNEXT          0
#define SPI1_FRAME_FORMAT     0
#define SPI1_RXONLY           0
#define SPI1_SSM              0
#define SPI1_SSI              0
#define SPI1_LSBFIRST         1
#define SPI1_SPE              1
#define SPI1_BR               000
#define SPI1_MSTR             1
#define SPI1_CPOL             0
#define SPI1_CPHA             1
/*REG CR2 Configuration*/
#define SPI1_TXEIE            1
#define SPI1_RXNEIE           1
#define SPI1_ERRIE            0
#define SPI1_SSOE             0
#define SPI1_TXDMAEN          0
#define SPI1_RXDMAEN          0

#elif NUMBER_OF_SPI_USED == SPI_2_USED
/*REG CR1 Configuration*/
#define SPI2_BIDIMODE         0
#define SPI2_BIDIOE           0
#define SPI2_CRCEN            0
#define SPI2_CRCNEXT          0
#define SPI2_FRAME_FORMAT     0
#define SPI2_RXONLY           0
#define SPI2_SSM              0
#define SPI2_SSI              0
#define SPI2_LSBFIRST         1
#define SPI2_SPE              1
#define SPI2_BR               000
#define SPI2_MSTR             1
#define SPI2_CPOL             0
#define SPI2_CPHA             1
/*REG CR2 Configuration*/
#define SPI2_TXEIE            1
#define SPI2_RXNEIE           1
#define SPI2_ERRIE            0
#define SPI2_SSOE             0
#define SPI2_TXDMAEN          0
#define SPI2_RXDMAEN          0
#endif




#endif /*File_H_*/

/*** End of File **************************************************************/
