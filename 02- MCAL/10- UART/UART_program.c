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
// Declare an array to store call back function addresses.
static CallBackRx CallBackArray[5];

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

/******************************************************************************
* Function : MUART_voidInit()
*//** 
* \b Description:
*
* This function is used to initialize the UART based on the configurations in UART_config. 
*
* PRE-CONDITION:  Configurations must be defined in UART_config.
*
* POST-CONDITION: None
*
* @param [in]     void
* 
* @return 		   void.
*
* \b Example Example:
* @code
* 	MUART_voidInit();
*
* @endcode
*
* @see MUART_voidInit
*
*******************************************************************************/
void MUART_voidInit(u8 Copy_u8UartNumber)
{
   UARTChannel[Copy_u8UartNumber]->CR1  = CLR_REGISTER;
   UARTChannel[Copy_u8UartNumber]->CR2  = CLR_REGISTER;
   UARTChannel[Copy_u8UartNumber]->CR3  = CLR_REGISTER;
   UARTChannel[Copy_u8UartNumber]->SR   = CLR_REGISTER;
   // The control register num 3 configuration.
   UARTChannel[Copy_u8UartNumber]->CR3 |= ((IRDA_MODE << IREN)       | (IRDA_LOW_POWER << IRLP)  | (HALF_DUPLEX  << HDSEL)
                                         | (SMARTCARD_NACK  << NACK) | (SMARTCARD_MODE << SCEN)  | (DMA_RECEIVER <<  DMAR)
                                         | (DMA_TRANSMITTER << DMAT) | (RTS_MODE       << RTSE)  | (CTS_MODE     <<  CTSE)
                                          );
// The control register num 2 configuration.
   UARTChannel[Copy_u8UartNumber]->CR2 |= ((NODE_ADDRESS << ADD)                | (LIN_BREAK_DETEC_LENGTH << LBDL)            
                                         | (LIN_BREAK_DETEC_INTERRUPT << LBDIE) | (LAST_BIT_CLOCK_PULSE << LBCL)            
                                         | (CLOCK_PHASE     << CPHA) | (CLOCK_POLARITY << CPOL) | (CLOCK_PIN_ENABLE << CLKEN)   
                                         | (STOP_BIT_NUMBER << STOP) | (LIN_MODE << LINEN)
													  ); 
// The control register num 1 configuration.
   UARTChannel[Copy_u8UartNumber]->CR1 |= ((SEND_BREAK      << SPK)  | (RECEIVER_WAKEUP    << RWU) | (PARITY_SELECTION << PS) 
	                                      | (RECEIVER_ENABLE << RE)   | (TRANSMITTER_ENABLE << TE)  | (PARITY_CONTROL   << PCE)                                     
                                         | (WAKEUP_METHOD   << WAKE) | (WORD_LENGTH        << M)
                                          );

   UARTChannel[Copy_u8UartNumber]->BRR  = UART_BAUDRATE;
   UARTChannel[Copy_u8UartNumber]->CR1 |= (ENABLE_UART << UE);
}

/******************************************************************************
* Function : MUART_voidTransmitSynch()
*//** 
* \b Description:
*
* This function is used to transmit an array by UART peripheral. 
*
* PRE-CONDITION:  MUART_voidInit function must be called to initialize UART peripheral.
*
* POST-CONDITION: None
*
* @param [in]     UART number.
* @param [in]     Array address tha contain data that will be sent.
* 
* @return 		   void.
*
* \b Example Example:
* @code
* 	MUART_voidTransmitSynch(UART_1, &Local_u8DataArray);
*
* @endcode
*
* @see MUART_voidTransmitSynch
*
*******************************************************************************/
void MUART_voidTransmitSynch(u8 Copy_u8UartNumber, u8 Copy_u8DataArray[])
{
   u8 Local_u8Counter = 0;
	while(Copy_u8DataArray[Local_u8Counter] != '\0')
	{
		// Put data in DR register to be transmitted.
	   UARTChannel[Copy_u8UartNumber]->DR = Copy_u8DataArray[Local_u8Counter];
		// Wait untill transmition finished.
		while(WAIT_TO_TRANSMIT);
		Local_u8Counter++;
	} 
}

/******************************************************************************
* Function : MUART_u8ReceiveByteSynch()
*//** 
* \b Description:
*
* This function is used to receive data from UART peripheral. 
*
* PRE-CONDITION:  MUART_voidInit function must be called to initialize UART peripheral.
*
* POST-CONDITION: None
*
* @param [in]     UART number.
* 
* @return 		   One byte tha received bu UART peripheral.
*
* \b Example Example:
* @code
* Local_u8ReceivedKey = MUART_u8ReceiveByteSynch(UART_1);
*
* @endcode
*
* @see MUART_u8ReceiveByteSynch
*
*******************************************************************************/
u8 MUART_u8ReceiveByteSynch(u8 Copy_u8UartNumber)
{
	u8 Local_u8Data;
	// Wait untill receiving finished.
	while(WAIT_TO_RECEIVE);
	// Getting the first byte of the register to be returned.
	Local_u8Data = ((ONE_BYTE) & (UARTChannel[Copy_u8UartNumber]->DR));
   return Local_u8Data;
}

/******************************************************************************
* Function : MUART_u8ReceiveSynch()
*//** 
* \b Description:
*
* This function is used to receive data from UART peripheral. 
*
* PRE-CONDITION:  MUART_voidInit function must be called to initialize UART peripheral.
*
* POST-CONDITION: None
*
* @param [in]     UART number.
* @param [in_out] The address of variable that store the received value.
* @return 		   The status of uart received value or not.
*
* \b Example Example:
* @code
* Local_u8RecordStatus = MUART_u8ReceiveSynch(UART_1, &ReceivedValue);
*
* @endcode
*
* @see MUART_u8ReceiveSynch
*
*******************************************************************************/
u8 MUART_u8ReceiveSynch(u8 Copy_u8UartNumber, u8 * Copy_u8Data)
{
	u8 Local_u8State = 1;
	// Chek is there data received.
	if(GET_BIT(UARTChannel[Copy_u8UartNumber]->SR, RXNE) == 1)
	{
		// Get the least significant byte.
		*Copy_u8Data = ((ONE_BYTE) & (UARTChannel[Copy_u8UartNumber]->DR));
	}
	else
	{
		u8 Local_u8State = 0;
	}
	return Local_u8State;
}

/******************************************************************************
* Function : MUART_voidReceiveASynch()
*//** 
* \b Description:
*
* This function is used to transmit an array. 
*
* PRE-CONDITION:  MUART_voidInit function must be called to initialize UART peripheral.
*
* POST-CONDITION: None
*
* @param [in]     UART number.
* @param [in]     A pointer to function that will be executed when UART peripheral received data.
* 
* @return 		   void.
*
* \b Example Example:
* @code
* 	MUART_voidReceiveASynch(UART_1, &APP_voidFunction);
*
* @endcode
*
* @see MUART_voidReceiveASynch
*
*******************************************************************************/
void MUART_voidReceiveASynch(u8 Copy_u8UartNumber, CallBackRx CallBackFuncRx)
{  
   // Store the call back function address in an array.
	// and take it's index based on the UART channel number.
	CallBackArray[Copy_u8UartNumber] = CallBackFuncRx;
	// Enable receiver interrupt.
	SET_BIT(UARTChannel[Copy_u8UartNumber]->CR1, RXNEIE);
}

/*Interrupt Service Routines*/

void USART1_IRQHandler(void)
{
	// Determine what cause interrupt.
   if(GET_BIT(UARTChannel[UART_1]->SR, RXNE))
	{
		// Clear Flag.
		CLR_BIT(UARTChannel[UART_1]->SR, RXNE);
		// Execute the call back function.
		// The call back function stored in an array.
		// and it's index in that array mapped to UART channel number.
		// and takes the data register as a parameter.
		CallBackArray[UART_1](UARTChannel[UART_1]->DR & ONE_BYTE);
	}
}

void USART2_IRQHandler(void)
{
	// Determine what cause interrupt.
   if(GET_BIT(UARTChannel[UART_2]->SR, RXNE))
	{
		// Clear the flag.
		CLR_BIT(UARTChannel[UART_2]->SR, RXNE);
		// Execute the call back function.
		// The call back function stored in an array.
		// and it's index in that array mapped to UART channel number.
		// and takes the data register as a parameter.
		CallBackArray[UART_2](UARTChannel[UART_2]->DR & ONE_BYTE);
	}
}

void USART3_IRQHandler(void)
{
	// Determine what cause interrupt.
   if(GET_BIT(UARTChannel[UART_3]->SR, RXNE))
   {
		// Clear the flag.
		CLR_BIT(UARTChannel[UART_3]->SR, RXNE);
		// Execute the call back function.
		// The call back function stored in an array.
		// and it's index in that array mapped to UART channel number.
		// and takes the data register as a parameter.
		CallBackArray[UART_3](UARTChannel[UART_3]->DR & ONE_BYTE);
	}
}

void USART4_IRQHandler(void)
{
	// Determine what cause interrupt.
   if(GET_BIT(UARTChannel[UART_4]->SR, RXNE))
	{
		// Clear the flag.
		CLR_BIT(UARTChannel[UART_4]->SR, RXNE);
		// Execute the call back function.
		// The call back function stored in an array.
		// and it's index in that array mapped to UART channel number.
		// and takes the data register as a parameter.
		CallBackArray[UART_4](UARTChannel[UART_4]->DR & ONE_BYTE);
	}
}

void USART5_IRQHandler(void)
{
	// Determine what cause interrupt.
   if(GET_BIT(UARTChannel[UART_5]->SR, RXNE))
	{
		// Clear the flag.
		CLR_BIT(UARTChannel[UART_5]->SR, RXNE);
		// Execute the call back function.
		// The call back function stored in an array.
		// and it's index in that array mapped to UART channel number.
		// and takes the data register as a parameter.
		CallBackArray[UART_5](UARTChannel[UART_5]->DR & ONE_BYTE);
	}
}


/*************** END OF FUNCTIONS ***************************************************************************/
