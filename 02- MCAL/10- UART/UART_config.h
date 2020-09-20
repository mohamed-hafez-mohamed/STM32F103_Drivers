/****************************************************************************
* Title                 :   UART   
* Filename              :   UART_config.h
* Author                :   Mohamed Hafez
* Origin Date           :   19/09/2020
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
*  19/09/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  UART_UART_config.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
//Different Modes
#define ENABLE                  1
#define DISABLE                 0
#define ENABLE_UART             1
#define DISABLE_UART            0
#define ENABLE_INTERRUPT        1
#define DISABLE_INTERRUPT       0
#define WORD_8_BITS             0
#define WORD_9_BITS             1
#define CLOCK_PHASE_CAP_FIRST   0
#define CLOCK_PHASE_CAP_SECOND  1
#define CLOCK_POLARITY_LOW      0
#define CLOCK_POLARITY_HIGH     1
#define Enable_CLOCK            1
#define DISABLE_CLOCK           0
#define STOB_1_BITS             0
#define STOB_2_BITS             10
#define STOB_5_BITS             01
#define STOB_1_5_BITS           11

//Baudrate Configuration

//Clock: 1 MHz 
#define UART_BAUDRATE_1200_CLK_1M       0X0341
#define UART_BAUDRATE_2400_CLK_1M       0X01A0
#define UART_BAUDRATE_4800_CLK_1M       0X00D0
#define UART_BAUDRATE_9600_CLK_1M       0X0068
#define UART_BAUDRATE_19200_CLK_1M      0X0034
//Clock: 8 MHz 
#define UART_BAUDRATE_1200_CLK_8M       0X1A0B
#define UART_BAUDRATE_2400_CLK_8M       0X0D05
#define UART_BAUDRATE_4800_CLK_8M       0X0683
#define UART_BAUDRATE_9600_CLK_8M       0X0341
#define UART_BAUDRATE_19200_CLK_8M      0X01A1

#define UART_BAUDRATE          UART_BAUDRATE_9600_CLK_1M
/******************************************************************************
* Configuration Constants
*******************************************************************************/

//UART Configuration

/**
 * CR1 Register Configuration
 * SBK: Send break
 * This bit set is used to send break characters. It can be set and cleared by software. It should
 * be set by software, and will be reset by hardware during the stop bit of break.
 * 0: No break character is transmitted
 * 1: Break character will be transmitted
 * RWU: Receiver wakeup
 * This bit determines if the USART is in mute mode or not. It is set and cleared by software and
 * can be cleared by hardware when a wakeup sequence is recognized.
 * 0: Receiver in active mode
 * 1: Receiver in mute mode
 * RE: Receiver enable
 * This bit enables the receiver. It is set and cleared by software.
 * 0: Receiver is disabled
 * 1: Receiver is enabled and begins searching for a start bit
 * TE: Transmitter enable
 * This bit enables the transmitter. It is set and cleared by software.
 * 0: Transmitter is disabled
 * 1: Transmitter is enabled
 * IDLEIE: IDLE interrupt enable
 * This bit is set and cleared by software.
 * 0: Interrupt is inhibited
 * 1: A USART interrupt is generated whenever IDLE=1 in the USART_SR register
 * RXNEIE: RXNE interrupt enable
 * This bit is set and cleared by software.
 * 0: Interrupt is inhibited
 * 1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register
 * TCIE: Transmission complete interrupt enable
 * This bit is set and cleared by software.
 * 0: Interrupt is inhibited
 * 1: A USART interrupt is generated whenever TC=1 in the USART_SR register
 * TXEIE: TXE interrupt enable
 * This bit is set and cleared by software.
 * 0: Interrupt is inhibited
 * 1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
 * PEIE: PE interrupt enable
 * This bit is set and cleared by software.
 * 0: Interrupt is inhibited
 * 1: A USART interrupt is generated whenever PE=1 in the USART_SR register
 * PS: Parity selection
 * This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
 * bit set). It is set and cleared by software. The parity will be selected after the current byte.
 * 0: Even parity
 * 1: Odd parity
 * PCE: Parity control enable
 * This bit selects the hardware parity control (generation and detection). When the parity
 * control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
 * if M=0) and parity is checked on the received data. This bit is set and cleared by software.
 * Once it is set, PCE is active after the current byte (in reception and in transmission).
 * 0: Parity control disabled
 * 1: Parity control enabled
 * WAKE: Wakeup method
 * This bit determines the USART wakeup method, it is set or cleared by software.
 * 0: Idle Line
 * 1: Address Mark
 * M: Word length
 * This bit determines the word length. It is set or cleared by software.
 * 0: 1 Start bit, 8 Data bits, n Stop bit
 * 1: 1 Start bit, 9 Data bits, n Stop bit
 * UE: USART enable
 * When this bit is cleared the USART prescalers and outputs are stopped and the end of the
 * current
 * byte transfer in order to reduce power consumption. This bit is set and cleared by software.
 * 0: USART prescaler and outputs disabled
 * 1: USART enabled
 * */

#define SEND_BREAK                          DISABLE
#define RECEIVER_WAKEUP                     DISABLE
#define RECEIVER_ENABLE                     ENABLE
#define TRANSMITTER_ENABLE                  ENABLE
#define IDLE_INTERRUPT                      DISABLE_INTERRUPT
#define RECEIVER_COMPLETE_INTERRUPT         DISABLE_INTERRUPT
#define TRANSMITTER_COMPLETE_INTERRUPT      DISABLE_INTERRUPT
#define TRANSMITTER_INTERRUPT               DISABLE_INTERRUPT
#define PARITY_INTERRUPT                    DISABLE_INTERRUPT
#define PARITY_SELECTION                    DISABLE
#define PARITY_CONTROL                      DISABLE
#define WAKEUP_METHOD                       DISABLE
#define WORD_LENGTH                         WORD_8_BITS
#define UART_ENABLE                         ENABLE_UART 

/**
 * CR2 Register Configuration
 * ADD[3:0]: Address of the USART node
 * This bit-field gives the address of the USART node.
 * This is used in multiprocessor communication during mute mode, for wake up with address
 * mark detection.
 * LBDL: lin break detection length
 * This bit is for selection between 11 bit or 10 bit break detection.
 * 0: 10 bit break detection
 * 1: 11 bit break detection
 * LBDIE: LIN break detection interrupt enable
 * Break interrupt mask (break detection using break delimiter).
 * 0: Interrupt is inhibited
 * 1: An interrupt is generated whenever LBD=1 in the USART_SR register
 * LBCL: Last bit clock pulse
 * This bit allows the user to select whether the clock pulse associated with the last data bit
 * transmitted (MSB) has to be output on the CK pin in synchronous mode.
 * 0: The clock pulse of the last data bit is not output to the CK pin
 * 1: The clock pulse of the last data bit is output to the CK pin
 * CPHA: Clock phase
 * This bit allows the user to select the phase of the clock output on the CK pin in synchronous
 * mode. It works in conjunction with the CPOL bit to produce the desired clock/data relationship
 * 0: The first clock transition is the first data capture edge.
 * 1: The second clock transition is the first data capture edge.
 * This bit is not available for UART4 & UART5.
 * CPOL: Clock polarity
 * This bit allows the user to select the polarity of the clock output on the CK pin in synchronous
 * mode. It works in conjunction with the CPHA bit to produce the desired clock/data relationship
 * 0: Steady low value on CK pin outside transmission window.
 * 1: Steady high value on CK pin outside transmission window.
 * This bit is not available for UART4 & UART5.
 * CLKEN: Clock enable
 * This bit allows the user to enable the CK pin.
 * 0: CK pin disabled
 * 1: CK pin enabled
 * This bit is not available for UART4 & UART5.
 * STOP: STOP bits
 * These bits are used for programming the stop bits.
 * 00: 1 Stop bit
 * 01: 0.5 Stop bit
 * 10: 2 Stop bits
 * 11: 1.5 Stop bit
 * The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
 * LINEN: LIN mode enable
 * This bit is set and cleared by software.
 * 0: LIN mode disabled
 * 1: LIN mode enabled
 * The LIN mode enables the capability to send LIN Synch Breaks (13 low bits) using the SBK
 * bit in the USART_CR1 register, and to detect LIN Sync breaks.
 * */

#define NODE_ADDRESS                 DISABLE
#define LIN_BREAK_DETEC_LENGTH       DISABLE
#define LIN_BREAK_DETEC_INTERRUPT    DISABLE_INTERRUPT
#define LAST_BIT_CLOCK_PULSE         DISABLE
#define CLOCK_PHASE                  CLOCK_PHASE_CAP_SECOND
#define CLOCK_POLARITY               CLOCK_POLARITY_LOW 
#define CLOCK_PIN_ENABLE             DISABLE
#define STOP_BIT_NUMBER              STOB_1_BITS
#define LIN_MODE                     DISABLE

/**
 * CR3 Register Configuration
 * EIE: Error interrupt enable
 * Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing
 * error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in
 * case of Multi Buffer Communication (DMAR=1 in the USART_CR3 register).
 * 0: Interrupt is inhibited
 * 1: An interrupt is generated whenever DMAR=1 in the USART_CR3 register and FE=1 or
 * ORE=1 or NE=1 in the USART_SR register.
 * IREN: IrDA mode enable
 * This bit is set and cleared by software.
 * 0: IrDA disabled
 * 1: IrDA enabled
 * IRLP: IrDA low-power
 * This bit is used for selecting between normal and low-power IrDA modes
 * 0: Normal mode
 * 1: Low-power mode
 * HDSEL: Half-duplex selection
 * Selection of Single-wire Half-duplex mode
 * 0: Half duplex mode is not selected
 * 1: Half duplex mode is selected
 * NACK: Smartcard NACK enable
 * 0: NACK transmission in case of parity error is disabled
 * 1: NACK transmission during parity error is enabled
 * This bit is not available for UART4 & UART5.
 * SCEN: Smartcard mode enable
 * This bit is used for enabling Smartcard mode.
 * 0: Smartcard Mode disabled
 * 1: Smartcard Mode enabled
 * This bit is not available for UART4 & UART5.
 * DMAR: DMA enable receiver
 * This bit is set/reset by software
 * 1: DMA mode is enabled for reception
 * 0: DMA mode is disabled for reception
 * This bit is not available for UART5.
 * DMAT: DMA enable transmitter
 * This bit is set/reset by software
 * 1: DMA mode is enabled for transmission
 * 0: DMA mode is disabled for transmission
 * This bit is not available for UART5.
 * RTSE: RTS enable
 * 0: RTS hardware flow control disabled
 * 1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
 * The transmission of data is expected to cease after the current character has been
 * transmitted. The RTS output is asserted (tied to 0) when a data can be received.
 * This bit is not available for UART4 & UART5.
 * CTSE: CTS enable
 * 0: CTS hardware flow control disabled
 * 1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
 * the CTS input is deasserted while a data is being transmitted, then the transmission is
 * completed before stopping. If a data is written into the data register while CTS is deasserted,
 * the transmission is postponed until CTS is asserted.
 * This bit is not available for UART4 & UART5.
 * CTSIE: CTS interrupt enable
 * 0: Interrupt is inhibited
 * 1: An interrupt is generated whenever CTS=1 in the USART_SR register
 * This bit is not available for UART4 & UART5.
 * */

#define ERROR_INTERRUPT           DISABLE_INTERRUPT
#define IRDA_MODE                 DISABLE
#define IRDA_LOW_POWER            DISABLE
#define HALF_DUPLEX               DISABLE
#define SMARTCARD_NACK            DISABLE
#define SMARTCARD_MODE            DISABLE
#define DMA_RECEIVER              DISABLE
#define DMA_TRANSMITTER           DISABLE
#define RTS_MODE                  DISABLE
#define CTS_MODE                  DISABLE
#define CTS_INTERRUPT             DISABLE

#endif /*File_H_*/

/*** End of File **************************************************************/
