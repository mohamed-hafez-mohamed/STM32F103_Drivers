/*******************************************************************************
* Title                 :   UART 
* Filename              :   UART_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   19/09/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  19/09/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file UART_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/
#define WAIT_TO_TRANSMIT   (GET_BIT(UARTChannel[Copy_u8UartNumber]->SR, TC)   == 0)
#define WAIT_TO_RECEIVE    (GET_BIT(UARTChannel[Copy_u8UartNumber]->SR, RXNE) == 0)
/******************************************************************************
* Module Typedefs
*******************************************************************************/
typedef void (*CallBackRx)(u8);
/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
static u8 UARTTxPins[3] = {PINA9,  PINA2, PINB10};
static u8 UARTRxPins[3] = {PINA10, PINA3, PINB11};

static CallBackRx CallBackArray[5];

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void MUART_voidInit(u8 Copy_u8UartNumber)
{
   UARTChannel[Copy_u8UartNumber]->CR1  = CLR_REGISTER;
   UARTChannel[Copy_u8UartNumber]->CR2  = CLR_REGISTER;
   UARTChannel[Copy_u8UartNumber]->CR3  = CLR_REGISTER;
   UARTChannel[Copy_u8UartNumber]->SR   = CLR_REGISTER;
   
   UARTChannel[Copy_u8UartNumber]->CR3 |= ((ERROR_INTERRUPT << EIE) | (IRDA_MODE << IREN)       | (IRDA_LOW_POWER << IRLP)  |
                                           (HALF_DUPLEX   << HDSEL) | (SMARTCARD_NACK  << NACK) | (SMARTCARD_MODE << SCEN)  |
                                           (DMA_RECEIVER  <<  DMAR) | (DMA_TRANSMITTER << DMAT) | (RTS_MODE       << RTSE)  |
                                           (CTS_MODE      <<  CTSE) | (CTS_INTERRUPT   << CTSIE));

   UARTChannel[Copy_u8UartNumber]->CR2 |= ((NODE_ADDRESS << ADD)                | (LIN_BREAK_DETEC_LENGTH << LBDL)          |  
                                           (LIN_BREAK_DETEC_INTERRUPT << LBDIE) | (LAST_BIT_CLOCK_PULSE << LBCL)            |
                                           (CLOCK_PHASE << CPHA) | (CLOCK_POLARITY << CPOL) | (CLOCK_PIN_ENABLE << CLKEN)   |
                                           (STOP_BIT_NUMBER << STOP) | (LIN_MODE << LINEN)); 

   UARTChannel[Copy_u8UartNumber]->CR1 |= ((SEND_BREAK << SPK) | (RECEIVER_WAKEUP << RWU) | (RECEIVER_ENABLE << RE)         |
                                           (TRANSMITTER_ENABLE << TE) | (IDLE_INTERRUPT << IDLEIE)                          |
                                           (RECEIVER_COMPLETE_INTERRUPT << RXNEIE) |(TRANSMITTER_COMPLETE_INTERRUPT << TCIE)|                                        
                                           (TRANSMITTER_INTERRUPT << TXEIE) | (PARITY_INTERRUPT << PEIE)                    | 
                                           (PARITY_SELECTION << PS) | (PARITY_CONTROL << PCE) | (WAKEUP_METHOD << WAKE)     |
                                           (WORD_LENGTH << M));

   UARTChannel[Copy_u8UartNumber]->BRR  = UART_BAUDRATE;
   UARTChannel[Copy_u8UartNumber]->CR1 |= (UART_ENABLE << UE);
}

void MUART_voidTransmitSynch(u8 Copy_u8UartNumber, u8 Copy_u8DataArray[])
{
   u8 Local_u8Counter = 0;
	 while(Copy_u8DataArray[Local_u8Counter] != '\0')
	 {
	    UARTChannel[Copy_u8UartNumber]->DR = Copy_u8DataArray[Local_u8Counter];
		  while(WAIT_TO_TRANSMIT);
		  Local_u8Counter++;
	 } 

}

u8   MUART_u8ReceiveSynch(u8 Copy_u8UartNumber)
{
	 while(WAIT_TO_RECEIVE);
   return ((0XFF) & (UARTChannel[Copy_u8UartNumber]->DR));
}

void MUART_u8ReceiveASynch(u8 Copy_u8UartNumber, CallBackRx CallBackFuncRx)
{  
	  CallBackArray[Copy_u8UartNumber] = CallBackFuncRx;
}



void USART1_IRQHandler(void)
{
     if(GET_BIT(UARTChannel[UART_1]->SR, RXNE))
		 {
			  CLR_BIT(UARTChannel[UART_1]->SR, RXNE);
			  CallBackArray[UART_1](UARTChannel[UART_1]->DR & 0XFF);
		 }
}

void USART2_IRQHandler(void)
{
     if(GET_BIT(UARTChannel[UART_2]->SR, RXNE))
		 {
			  CLR_BIT(UARTChannel[UART_2]->SR, RXNE);
			  CallBackArray[UART_2](UARTChannel[UART_2]->DR & 0XFF);
		 }
}

void USART3_IRQHandler(void)
{
     if(GET_BIT(UARTChannel[UART_3]->SR, RXNE))
		 {
			  CLR_BIT(UARTChannel[UART_3]->SR, RXNE);
			  CallBackArray[UART_3](UARTChannel[UART_3]->DR & 0XFF);
		 }
}

void USART4_IRQHandler(void)
{
     if(GET_BIT(UARTChannel[UART_4]->SR, RXNE))
		 {
			  CLR_BIT(UARTChannel[UART_4]->SR, RXNE);
			  CallBackArray[UART_4](UARTChannel[UART_4]->DR & 0XFF);
		 }
}

void USART5_IRQHandler(void)
{
     if(GET_BIT(UARTChannel[UART_5]->SR, RXNE))
		 {
			  CLR_BIT(UARTChannel[UART_5]->SR, RXNE);
			  CallBackArray[UART_5](UARTChannel[UART_5]->DR & 0XFF);
		 }
}


/*************** END OF FUNCTIONS ***************************************************************************/
