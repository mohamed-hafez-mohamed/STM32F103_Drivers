/*******************************************************************************
* Title                 :   SPI 
* Filename              :   SPI_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   16/09/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  16/09/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file SPI_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/
typedef void (*CallBack)(u8 );

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
#if   NUMBER_OF_SPI_USED == SPI_1_USED
static CallBack SPI1CallBackFunction;
static u8 SPI1SlaveNumber;
#elif NUMBER_OF_SPI_USED == SPI_2_USED
static CallBack SPI2CallBackFunction;
static u8 SPI2SlaveNumber;
#elif NUMBER_OF_SPI_USED == ALL_SPI_USED
static CallBack SPI1CallBackFunction;
static u8 SPI1SlaveNumber;
static CallBack SPI2CallBackFunction;
static u8 SPI2SlaveNumber;
#endif

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void MSPI_voidInit(void)
{
    #if    NUMBER_OF_SPI_USED == SPI_1_USED
    #if  SPI_1_MODE == SPI_MODE_MASTER
    //MGPIO_voidSetPinMode(SPI_1_MOSI_PIN, GPIO_OUTPUT_10M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_1_MISO_PIN, GPIO_INPUT_FLOATING);
    //MGPIO_voidSetPinMode(SPI_1_CLK_PIN,  GPIO_OUTPUT_10M_PULL_UP_DN);
    for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_1_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinMode(SPI1_SelectSlavePins[Local_u8Counter], GPIO_OUTPUT_10M_PULL_UP_DN);
    }
		for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_1_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Local_u8Counter], HIGH);
    }
    #elif SPI_1_MODE == SPI_MODE_SLAVE
    MGPIO_voidSetPinMode(SPI_1_MOSI_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_1_MISO_PIN, GPIO_OUTPUT_50M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_1_CLK_PIN,  GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_1_NSS_PIN,  GPIO_INPUT_FLOATING);
    #endif
    /*Reg Configuratio*/
    SPI1->CR1 = CLR_REGISTER;
    SPI1->CR2 = CLR_REGISTER;

    SPI1->CR2 |= ((SPI1_TXEIE << TXEIE) | (SPI1_RXNEIE << RXNEIE) | (SPI1_ERRIE << ERRIE) | (SPI1_SSOE << SSOE) |
                  (SPI1_TXDMAEN << TXDMAEN) | (SPI1_RXDMAEN << RXDMAEN));

    SPI1->CR1 |= ((SPI1_BIDIMODE << BIDIMODE) | (SPI1_BIDIOE << BIDIOE) | (SPI1_CRCEN << CRCEN) | (SPI1_CRCNEXT << CRCNEXT) |
                  (SPI1_FRAME_FORMAT << DFF)  | (SPI1_RXONLY << RXONLY) | (SPI1_SSM << SSM)     | (SPI1_SSI  << SSI)        |
                  (SPI1_LSBFIRST << LSBFIRST) | (SPI1_BR < BR0)         | (SPI1_MSTR << MSTR)   | (SPI1_CPOL << CPOL)       |
                  (SPI1_CPHA << CPHA));
    SPI1->CR1 |=  (SPI1_SPE  << SPE);

    #elif  NUMBER_OF_SPI_USED == SPI_2_USED
    #if  SPI_2_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinMode(SPI_2_MOSI_PIN, GPIO_OUTPUT_50M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_2_MISO_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_2_CLK_PIN,  GPIO_OUTPUT_10M_PULL_UP_DN);
    for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_2_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinMode(SPI2_SelectSlavePins[Local_u8Counter], GPIO_OUTPUT_10M_PULL_UP_DN);
    }
		for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_2_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Local_u8Counter], HIGH);
    }
    #elif SPI_2_MODE == SPI_MODE_SLAVE
    MGPIO_voidSetPinMode(SPI_2_MOSI_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_2_MISO_PIN, GPIO_OUTPUT_50M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_2_CLK_PIN,  GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_2_NSS_PIN,  GPIO_INPUT_FLOATING);
    #endif
    /*Reg Configuratio*/
    SPI2->CR1 = CLR_REGISTER;
    SPI2->CR2 = CLR_REGISTER;

    SPI2->CR2 |= ((SPI2_TXEIE << TXEIE) | (SPI2_RXNEIE << RXNEIE) | (SPI2_ERRIE << ERRIE) | (SPI2_SSOE << SSOE)
                  (SPI2_TXDMAEN << TXDMAEN) | (SPI2_RXDMAEN << RXDMAEN));

    SPI2->CR1 |= ((SPI2_BIDIMODE << BIDIMODE) | (SPI2_BIDIOE << BIDIOE) | (SPI2_CRCEN << CRCEN) | (SPI2_CRCNEXT << CRCNEXT) |
                  (SPI2_FRAME_FORMAT << DFF)  | (SPI2_RXONLY << RXONLY) | (SPI2_SSM << SSM)     | (SPI2_SSI  << SSI)        |
                  (SPI2_LSBFIRST << LSBFIRST) | (SPI2_BR < BR0)         | (SPI2_MSTR << MSTR)   | (SPI2_CPOL << CPOL)       |
                  (SPI2_CPHA << CPHA));
    SPI2->CR1 |=  (SPI2_SPE  << SPE);

    #elif  NUMBER_OF_SPI_USED == ALL_SPI_USED
     #if  SPI_1_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinMode(SPI_1_MOSI_PIN, GPIO_OUTPUT_50M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_1_MISO_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_1_CLK_PIN,  GPIO_OUTPUT_10M_PULL_UP_DN);
    for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_1_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinMode(SPI1_SelectSlavePins[Local_u8Counter], GPIO_OUTPUT_2M_PULL_UP_DN);
    }
		for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_1_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Local_u8Counter], HIGH);
    }
    #elif SPI_1_MODE == SPI_MODE_SLAVE
    MGPIO_voidSetPinMode(SPI_1_MOSI_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_1_MISO_PIN, GPIO_OUTPUT_50M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_1_CLK_PIN,  GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_1_NSS_PIN,  GPIO_INPUT_FLOATING);
    #endif
    #if  SPI_2_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinMode(SPI_2_MOSI_PIN, GPIO_OUTPUT_50M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_2_MISO_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_2_CLK_PIN,  GPIO_OUTPUT_10M_PULL_UP_DN);
    for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_2_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinMode(SPI2_SelectSlavePins[Local_u8Counter], GPIO_OUTPUT_2M_PULL_UP_DN);
    }
		for(u8 Local_u8Counter = 0;Local_u8Counter < SPI_2_NUMBER_OF_SLAVES; Local_u8Counter++)
    {
        MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Local_u8Counter], HIGH);
    }
    #elif SPI_2_MODE == SPI_MODE_SLAVE
    MGPIO_voidSetPinMode(SPI_2_MOSI_PIN, GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_2_MISO_PIN, GPIO_OUTPUT_50M_PULL_UP_DN);
    MGPIO_voidSetPinMode(SPI_2_CLK_PIN,  GPIO_INPUT_FLOATING);
    MGPIO_voidSetPinMode(SPI_2_NSS_PIN,  GPIO_INPUT_FLOATING);
    #endif
    /*Reg Configuratio*/
    SPI1->CR1 = CLR_REGISTER;
    SPI1->CR2 = CLR_REGISTER;
    SPI2->CR1 = CLR_REGISTER;
    SPI2->CR2 = CLR_REGISTER;
    SPI1->CR2 |= ((SPI1_TXEIE << TXEIE) | (SPI1_RXNEIE << RXNEIE) | (SPI1_ERRIE << ERRIE) | (SPI1_SSOE << SSOE)
                  (SPI1_TXDMAEN << TXDMAEN) | (SPI1_RXDMAEN << RXDMAEN));

    SPI1->CR1 |= ((SPI1_BIDIMODE << BIDIMODE) | (SPI1_BIDIOE << BIDIOE) | (SPI1_CRCEN << CRCEN) | (SPI1_CRCNEXT << CRCNEXT) |
                  (SPI1_FRAME_FORMAT << DFF)  | (SPI1_RXONLY << RXONLY) | (SPI1_SSM << SSM)     | (SPI1_SSI  << SSI)        |
                  (SPI1_LSBFIRST << LSBFIRST) | (SPI1_BR < BR0)         | (SPI1_MSTR << MSTR)   | (SPI1_CPOL << CPOL)       |
                  (SPI1_CPHA << CPHA));
    SPI1->CR1 |=  (SPI1_SPE  << SPE);

    SPI2->CR2 |= ((SPI2_TXEIE << TXEIE) | (SPI2_RXNEIE << RXNEIE) | (SPI2_ERRIE << ERRIE) | (SPI2_SSOE << SSOE)
                  (SPI2_TXDMAEN << TXDMAEN) | (SPI2_RXDMAEN << RXDMAEN));

    SPI2->CR1 |= ((SPI2_BIDIMODE << BIDIMODE) | (SPI2_BIDIOE << BIDIOE) | (SPI2_CRCEN << CRCEN) | (SPI2_CRCNEXT << CRCNEXT) |
                  (SPI2_FRAME_FORMAT << DFF)  | (SPI2_RXONLY << RXONLY) | (SPI2_SSM << SSM)     | (SPI2_SSI  << SSI)        |
                  (SPI2_LSBFIRST << LSBFIRST) | (SPI2_BR < BR0)         | (SPI2_MSTR << MSTR)   | (SPI2_CPOL << CPOL)       |
                  (SPI2_CPHA << CPHA));
    SPI2->CR1 |=  (SPI2_SPE  << SPE);
    #endif
}

#if    NUMBER_OF_SPI_USED == SPI_1_USED

u16 MSPI1_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit)
{
    #if   SPI_1_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI1->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Copy_u8SlaveNumber], HIGH);
    return (SPI1->DR);
    #elif SPI_1_MODE == SPI_MODE_SLAVE
    SPI1->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    return SPI1->DR;
    #endif
}

void MSPI1_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, CallBack Ptr_UserFunction)
{
    #if   SPI_1_MODE == SPI_MODE_MASTER
    SPI1CallBackFunction = Ptr_UserFunction;
    SPI1SlaveNumber      = Copy_u8SlaveNumber;
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI1->DR = Copy_u16DataToTransimit;
    #elif SPI_1_MODE == SPI_MODE_SLAVE
    SPI1CallBackFunction = Ptr_UserFunction;
    SPI1SlaveNumber      = Copy_u8SlaveNumber;
    SPI1->DR = Copy_u16DataToTransimit;
    #endif
}

void SPI1_IRQHandler(void)
{
    #if   SPI_1_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[SPI1SlaveNumber], HIGH);
    SPI1CallBackFunction(SPI1->DR);
    #elif SPI_1_MODE == SPI_MODE_MASTER
    SPI1CallBackFunction(SPI1->DR);
    #endif
}
#elif  NUMBER_OF_SPI_USED == SPI_2_USED
u16 MSPI2_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit)
{
    #if   SPI_2_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI2->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Copy_u8SlaveNumber], HIGH);
    return SPI2->DR;
    #elif SPI_2_MODE == SPI_MODE_SLAVE
    SPI2->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    return SPI2->DR;
    #endif
}

void MSPI2_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, CallBack Ptr_UserFunction)
{
    #if   SPI_2_MODE == SPI_MODE_MASTER
    SPI2CallBackFunction = Ptr_UserFunction;
    SPI2SlaveNumber      = Copy_u8SlaveNumber;
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI2->DR = Copy_u16DataToTransimit;
    #elif SPI_2_MODE == SPI_MODE_SLAVE
    SPI2CallBackFunction = Ptr_UserFunction;
    SPI2SlaveNumber      = Copy_u8SlaveNumber;
    SPI2->DR = Copy_u16DataToTransimit;
    #endif
}

void SPI2_IRQHandler(void)
{
    #if   SPI_2_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[SPI2SlaveNumber], HIGH);
    SPI1CallBackFunction(SPI2->DR);
    #elif SPI_2_MODE == SPI_MODE_MASTER
    SPI1CallBackFunction(SPI2->DR);
    #endif
}
#elif  NUMBER_OF_SPI_USED == ALL_SPI_USED
u16 MSPI1_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit)
{
    #if   SPI_1_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI1->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Copy_u8SlaveNumber], HIGH);
    return SPI1->DR;
    #elif SPI_1_MODE == SPI_MODE_SLAVE
    SPI1->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    return SPI1->DR;
    #endif
}

void MSPI1_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, CallBack Ptr_UserFunction)
{
    #if   SPI_1_MODE == SPI_MODE_MASTER
    SPI1CallBackFunction = Ptr_UserFunction;
    SPI1SlaveNumber      = Copy_u8SlaveNumber;
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI1->DR = Copy_u16DataToTransimit;
    #elif SPI_1_MODE == SPI_MODE_SLAVE
    SPI1CallBackFunction = Ptr_UserFunction;
    SPI1SlaveNumber      = Copy_u8SlaveNumber;
    SPI1->DR = Copy_u16DataToTransimit;
    #endif
}

void SPI1_IRQHandler(void)
{
    #if   SPI_1_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI1_SelectSlavePins[SPI1SlaveNumber], HIGH);
    SPI1CallBackFunction(SPI1->DR);
    #elif SPI_1_MODE == SPI_MODE_MASTER
    SPI1CallBackFunction(SPI1->DR);
    #endif
}

u16 MSPI2_voidSendReceiveSync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit)
{
    #if   SPI_2_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI2->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Copy_u8SlaveNumber], HIGH);
    return SPI2->DR;
    #elif SPI_2_MODE == SPI_MODE_SLAVE
    SPI2->DR = Copy_u16DataToTransimit;
    while(GET_BIT(SPI1->SR, BSY) == 1);
    return SPI2->DR;
    #endif
}

void MSPI2_voidSendReceiveAsync(u8 Copy_u8SlaveNumber, u16 Copy_u16DataToTransimit, CallBack Ptr_UserFunction)
{
    #if   SPI_2_MODE == SPI_MODE_MASTER
    SPI2CallBackFunction = Ptr_UserFunction;
    SPI2SlaveNumber      = Copy_u8SlaveNumber;
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[Copy_u8SlaveNumber], LOW);
    SPI2->DR = Copy_u16DataToTransimit;
    #elif SPI_2_MODE == SPI_MODE_SLAVE
    SPI2CallBackFunction = Ptr_UserFunction;
    SPI2SlaveNumber      = Copy_u8SlaveNumber;
    SPI2->DR = Copy_u16DataToTransimit;
    #endif
}

void SPI2_IRQHandler(void)
{
    #if   SPI_2_MODE == SPI_MODE_MASTER
    MGPIO_voidSetPinValue(SPI2_SelectSlavePins[SPI2SlaveNumber], HIGH);
    SPI1CallBackFunction(SPI2->DR);
    #elif SPI_2_MODE == SPI_MODE_MASTER
    SPI1CallBackFunction(SPI2->DR);
    #endif
}
#endif

/*************** END OF FUNCTIONS ***************************************************************************/
