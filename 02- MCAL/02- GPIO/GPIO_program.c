/*******************************************************************************
* Title                 :   GPIO 
* Filename              :   GPIO_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   10/8/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  04/01/15   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file GPIO_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

// TODO: UPDATE AND COPY THESE FOR EACH NON_TRIVIAL FUNCTION
/******************************************************************************
* Function : Dio_Init()
*//** 
* \b Description:
*
* This function is used to initialize the Dio based on the configuration table
*  defined in dio_cfg module.  
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the configuration
* table will be returned.
*
* @return 		A pointer to the configuration table.
*
* \b Example Example:
* @code
* 	const Dio_ConfigType *DioConfig = Dio_GetConfig();
*
* 	Dio_Init(DioConfig);
* @endcode
*
* @see Dio_Init
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/

void GPIO_voidSetPinMode (GPIO_PinId_t copy_u8PinId , GPIO_PIN_MODE copy_u8Mode)
{
    GPIO_PortId_t copy_u8PortId;
    if(copy_u8PinId >= GPIO_PORTA_ENTRY && copy_u8PinId <= GPIO_PORTA_END)
    {
        copy_u8PortId = PORTA;
    }
    else if(copy_u8PinId >= GPIO_PORTB_ENTRY && copy_u8PinId <= GPIO_PORTB_END)
    {
        copy_u8PortId = PORTB;
        copy_u8PinId -= GPIO_ADJUST_PORTB_PIN;
    }
    else if(copy_u8PinId >= GPIO_PORTC_ENTRY && copy_u8PinId <= GPIO_PORTC_END)
    {
        copy_u8PortId = PORTC;
        copy_u8PinId -= GPIO_ADJUST_PORTC_PIN;
    }
    else
    {
        /*!<TODO: Error Codes*/
    }
    
    switch (copy_u8PortId)
    {
        case PORTA :
           if(copy_u8PinId <= GPIO_PORT_MIDDLE)
           {
               GPIOA_CRL &= ~ ((GPIO_CLR_MODE) << (GPIO_SHIFT_BIT * copy_u8PinId));
               GPIOA_CRL |=   ((copy_u8Mode)   << (GPIO_SHIFT_BIT * copy_u8PinId));
           }
           else if(copy_u8PinId <= GPIO_PORT_END)
           {
               copy_u8PinId -= GPIO_ADJUST_BIT;
               GPIOA_CRH &= ~ ((GPIO_CLR_MODE) << (GPIO_SHIFT_BIT * copy_u8PinId));
               GPIOA_CRH |=   ((copy_u8Mode)   << (GPIO_SHIFT_BIT * copy_u8PinId));
           }
           else
           {
               /*!<TODO: Error Codes*/
           }
        break;
        case PORTB :
           if(copy_u8PinId <= GPIO_PORT_MIDDLE)
           {
               GPIOB_CRL &= ~ ((GPIO_CLR_MODE) << (GPIO_SHIFT_BIT * copy_u8PinId));
               GPIOB_CRL |=   ((copy_u8Mode)   << (GPIO_SHIFT_BIT * copy_u8PinId));
           }
           else if(copy_u8PinId <= GPIO_PORT_END)
           {
               copy_u8PinId -= GPIO_ADJUST_BIT;
               GPIOB_CRH &= ~ ((GPIO_CLR_MODE) << (GPIO_SHIFT_BIT * copy_u8PinId));
               GPIOB_CRH |=   ((copy_u8Mode)   << (GPIO_SHIFT_BIT * copy_u8PinId));
           }
           else
           {
               /*!<TODO: Error Codes*/
           }
        break;
        case PORTC :
           if(copy_u8PinId <= GPIO_PORT_MIDDLE)
           {
               GPIOC_CRL &= ~ ((GPIO_CLR_MODE) << (GPIO_SHIFT_BIT * copy_u8PinId));
               GPIOC_CRL |=   ((copy_u8Mode)   << (GPIO_SHIFT_BIT * copy_u8PinId));
           }
           else if(copy_u8PinId <= GPIO_PORT_END)
           {
               copy_u8PinId -= GPIO_ADJUST_BIT;
               GPIOC_CRH &= ~ ((GPIO_CLR_MODE) << (GPIO_SHIFT_BIT * copy_u8PinId));
               GPIOC_CRH |=   ((copy_u8Mode)   << (GPIO_SHIFT_BIT * copy_u8PinId));
           }
           else
           {
               /*!<TODO: Error Codes*/
           }
        break;
        default :
            /*TODO: Error Codes*/ 
        break;
    }
}

void GPIO_voidSetPinValue (GPIO_PinId_t copy_u8PinId , u8 copy_u8Value)
{
    GPIO_PortId_t copy_u8PortId;
    if(copy_u8PinId >= GPIO_PORTA_ENTRY && copy_u8PinId <= GPIO_PORTA_END)
    {
        copy_u8PortId = PORTA;
    }
    else if(copy_u8PinId >= GPIO_PORTB_ENTRY && copy_u8PinId <= GPIO_PORTB_END)
    {
        copy_u8PortId = PORTB;
        copy_u8PinId -= GPIO_ADJUST_PORTB_PIN;
    }
    else if(copy_u8PinId >= GPIO_PORTC_ENTRY && copy_u8PinId <= GPIO_PORTC_END)
    {
        copy_u8PortId = PORTC;
        copy_u8PinId -= GPIO_ADJUST_PORTC_PIN;
    }
    else
    {
        /*!<TODO: Error Codes*/
    }
    if(copy_u8PinId <= GPIO_PORT_END)
    {
        switch(copy_u8PortId)
        {
            case PORTA :
                switch(copy_u8Value)
                {
                    case LOW  : GPIOA_BRR = SET << copy_u8PinId;break;
                    case HIGH : GPIOA_BSR = SET << copy_u8PinId;break;   
                }
            break;
            case PORTB :
                switch(copy_u8Value)
                {
                    case LOW  : GPIOB_BRR = SET << copy_u8PinId;break;
                    case HIGH : GPIOB_BSR = SET << copy_u8PinId;break;     
                }
            break;
            case PORTC :
                switch(copy_u8Value)
                {
                    case LOW  : GPIOC_BRR = SET << copy_u8PinId;break;
                    case HIGH : GPIOC_BSR = SET << copy_u8PinId;break;    
                }
            break;
            default : 
                /*TODO: Error Codes*/
            break;
        }
    }
    else
    {
        /*TODO: Error Codes*/
    }
    
}

u8 GPIO_u8GetPinValue (GPIO_PinId_t copy_u8PinId)
{
    u8 u8_value = 0;
    GPIO_PortId_t copy_u8PortId;
    if(copy_u8PinId >= GPIO_PORTA_ENTRY && copy_u8PinId <= GPIO_PORTA_END)
    {
        copy_u8PortId = PORTA;
    }
    else if(copy_u8PinId >= GPIO_PORTB_ENTRY && copy_u8PinId <= GPIO_PORTB_END)
    {
        copy_u8PortId = PORTB;
        copy_u8PinId -= GPIO_ADJUST_PORTB_PIN;
    }
    else if(copy_u8PinId >= GPIO_PORTC_ENTRY && copy_u8PinId <= GPIO_PORTC_END)
    {
        copy_u8PortId = PORTC;
        copy_u8PinId -= GPIO_ADJUST_PORTC_PIN;
    }
    else
    {
        /*!<TODO: Error Codes*/
    }
    if(copy_u8PinId <= GPIO_PORT_END)
    {
        switch(copy_u8PortId)
        {
            case PORTA :
                u8_value = GET_BIT(GPIOA_IDR, copy_u8PinId);
            break;
            case PORTB :
                u8_value = GET_BIT(GPIOB_IDR, copy_u8PinId);
            break;
            case PORTC :
                u8_value = GET_BIT(GPIOC_IDR, copy_u8PinId);
            break;
            default :
                /*TODO: Error Codes*/
            break;
        }
    }
    else
    {
        /*TODO: Error Codes*/
    }
        
    return u8_value;
}

void GPIO_voidTogPinValue (GPIO_PinId_t copy_u8PinId)
{
    GPIO_PortId_t copy_u8PortId;
    if(copy_u8PinId >= GPIO_PORTA_ENTRY && copy_u8PinId <= GPIO_PORTA_END)
    {
        copy_u8PortId = PORTA;
    }
    else if(copy_u8PinId >= GPIO_PORTB_ENTRY && copy_u8PinId <= GPIO_PORTB_END)
    {
        copy_u8PortId = PORTB;
        copy_u8PinId -= GPIO_ADJUST_PORTB_PIN;
    }
    else if(copy_u8PinId >= GPIO_PORTC_ENTRY && copy_u8PinId <= GPIO_PORTC_END)
    {
        copy_u8PortId = PORTC;
        copy_u8PinId -= GPIO_ADJUST_PORTC_PIN;
    }
    else
    {
        /*!<TODO: Error Codes*/
    }
    if(copy_u8PinId <= GPIO_PORT_END)
    {
        switch(copy_u8PortId)
        {
            case PORTA :
                TOG_BIT(GPIOA_ODR, copy_u8PinId);
            break;
            case PORTB :
                TOG_BIT(GPIOB_ODR, copy_u8PinId);
            break;
            case PORTC :
                TOG_BIT(GPIOC_ODR, copy_u8PinId);
            break;
            default :
                /*TODO: Error Codes*/
            break;
        }
    }
    else
    {
        /*TODO: Error Codes*/
    }
}

void GPIO_voidSetPortMode (u8 copy_u8StPin, u8 copy_u8EdPin, GPIO_PIN_MODE copy_u8Mode)
{
	for (GPIO_PinId_t pins = copy_u8StPin ;pins <= copy_u8EdPin ;pins++)
    {
		GPIO_voidSetPinMode(pins, copy_u8Mode);
	}
}

void GPIO_voidSetPortValue (GPIO_PortId_t copy_u8PortId , u16 copy_u16Value)
{
    switch(copy_u8PortId)
    {
        case PORTA :
            GPIOA_ODR  |= copy_u16Value;
        break;
        case PORTB :
            GPIOB_ODR |= copy_u16Value;
        break;
        case PORTC :
            GPIOC_ODR |= copy_u16Value;
        break;
        default : 
            /*TODO: Error Codes*/
        break;
    }
    
}

void GPIO_voidSetClrPinsValue (GPIO_PortId_t copy_u8PortId, u32 copy_u32Value)
{
    switch(copy_u8PortId)
    {
         case PORTA :
            GPIOA_BSR = copy_u32Value;
         case PORTB :
            GPIOB_BSR = copy_u32Value;    
        break;
        case PORTC :
           GPIOC_BSR = copy_u32Value;     
        default : 
            /*TODO: Error Codes*/
        break;
       
    }
}

void GPIO_voidSetPinsValue (GPIO_PortId_t copy_u8PortId, u16 copy_u16Value)
{
    switch(copy_u8PortId)
    {
        case PORTA :
           GPIOA_BSR = copy_u16Value;
        case PORTB :
           GPIOB_BSR = copy_u16Value;    
        break;
        case PORTC :
           GPIOC_BSR = copy_u16Value;     
        default    : 
            /*TODO: Error Codes*/
        break;
       
    }
}

void GPIO_voidClrPinsValue (GPIO_PortId_t copy_u8PortId, u16 copy_u16Value)
{
    switch(copy_u8PortId)
    {
        case PORTA :
           GPIOA_BRR = copy_u16Value;
        case PORTB :
           GPIOB_BRR = copy_u16Value;    
        break;
        case PORTC :
           GPIOC_BRR = copy_u16Value;     
        default    : 
            /*TODO: Error Codes*/
        break;
    }
}

u8 GPIO_u8LockBitConfig(GPIO_PinId_t copy_u8PinId)
{
    GPIO_PortId_t copy_u8PortId;
	  u8 LCKValue  = 0;
    u8 LCKKValue = 0;
    if(copy_u8PinId >= GPIO_PORTA_ENTRY && copy_u8PinId <= GPIO_PORTA_END)
    {
        copy_u8PortId = PORTA;
    }
    else if(copy_u8PinId >= GPIO_PORTB_ENTRY && copy_u8PinId <= GPIO_PORTB_END)
    {
        copy_u8PortId = PORTB;
        copy_u8PinId -= GPIO_ADJUST_PORTB_PIN;
    }
    else if(copy_u8PinId >= GPIO_PORTC_ENTRY && copy_u8PinId <= GPIO_PORTC_END)
    {
        copy_u8PortId = PORTC;
        copy_u8PinId -= GPIO_ADJUST_PORTC_PIN;
    }
    else
    {
        /*!<TODO: Error Codes*/
    }
    
    switch(copy_u8PortId)
    {
        case PORTA :
           CLR_BIT(GPIOA_LCK, GPIO_LCK_LCKK);
           SET_BIT(GPIOA_LCK, copy_u8PinId);
           /*!<Key Writing Sequence*/
           SET_BIT(GPIOA_LCK, GPIO_LCK_LCKK);
           CLR_BIT(GPIOA_LCK, GPIO_LCK_LCKK);
           SET_BIT(GPIOA_LCK, GPIO_LCK_LCKK);
           LCKKValue = GET_BIT(GPIOA_LCK, GPIO_LCK_LCKK);
           LCKKValue = GET_BIT(GPIOA_LCK, GPIO_LCK_LCKK);

           LCKValue  = GET_BIT(GPIOA_LCK, copy_u8PinId);
        case PORTB :
           CLR_BIT(GPIOB_LCK, GPIO_LCK_LCKK);
           SET_BIT(GPIOB_LCK, copy_u8PinId);
           /*!<Key Writing Sequence*/
           SET_BIT(GPIOB_LCK, GPIO_LCK_LCKK);
           CLR_BIT(GPIOB_LCK, GPIO_LCK_LCKK);
           SET_BIT(GPIOB_LCK, GPIO_LCK_LCKK);
           LCKKValue = GET_BIT(GPIOB_LCK, GPIO_LCK_LCKK);
           LCKKValue = GET_BIT(GPIOB_LCK, GPIO_LCK_LCKK);

           LCKValue = GET_BIT(GPIOB_LCK, copy_u8PinId);    
        break;
        case PORTC :
           CLR_BIT(GPIOC_LCK, GPIO_LCK_LCKK);
           SET_BIT(GPIOC_LCK, copy_u8PinId);
           /*!<Key Writing Sequence*/
           SET_BIT(GPIOC_LCK, GPIO_LCK_LCKK);
           CLR_BIT(GPIOC_LCK, GPIO_LCK_LCKK);
           SET_BIT(GPIOC_LCK, GPIO_LCK_LCKK);
           LCKKValue = GET_BIT(GPIOC_LCK, GPIO_LCK_LCKK);
           LCKKValue = GET_BIT(GPIOC_LCK, GPIO_LCK_LCKK);

           LCKValue = GET_BIT(GPIOC_LCK, copy_u8PinId);       
        default    : 
            /*TODO: Error Codes*/
        break;
    }
    return LCKValue;
}


/*************** END OF FUNCTIONS ***************************************************************************/
