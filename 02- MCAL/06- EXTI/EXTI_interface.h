/****************************************************************************
* Title                 :   EXTI   
* Filename              :   EXTI_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   25/08/2020
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
*  25/8/20   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  EXTI_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

#define EXTI_NUMBER_OF_EXTI    16
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef void (*EXTI_voidPtrToFunction)(void *);
typedef void* EXTI_voidPtrToParameter;

typedef enum
{
    LINE0 = 0,           
    LINE1,
    LINE2,           
    LINE3,           
    LINE4, 
    LINE5,          
    LINE6,           
    LINE7,           
    LINE8,           
    LINE9,          
    LINE10,          
    LINE11,          
    LINE12,          
    LINE13,          
    LINE14,          
    LINE15          
}EXTI_Lines_t;

typedef enum
{
    EXTI0_ID = 0,           
    EXTI1_ID,
    EXTI2_ID,           
    EXTI3_ID,           
    EXTI4_ID,           
    EXTI5_ID,           
    EXTI6_ID,           
    EXTI7_ID,           
    EXTI8_ID,          
    EXTI9_ID,          
    EXTI10_ID,          
    EXTI11_ID,          
    EXTI12_ID,          
    EXTI13_ID,          
    EXTI14_ID, 
    EXTI15_ID        
}EXTI_InterruptId_t;

typedef enum
{
    RISING = 0,
    FALLING,       
    ON_CHANGE       
}EXTI_IntSignalSensitive_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
u8 EXTI_u8Init(u8 copy_LineIndex, EXTI_Lines_t copy_Line[], EXTI_IntSignalSensitive_t copy_Mode); 

u8 EXTI_u8EnableEXTI(u8 copy_LineIndex, EXTI_Lines_t copy_Line[]);

u8 EXTI_u8DisableEXTI(u8 copy_LineIndex, EXTI_Lines_t copy_Line[]);

u8 EXTI_u8SwTrigger(u8 copy_LineIndex, EXTI_Lines_t copy_Line[]);

u8 EXTI_u8SetSignalLatch(u8 copy_LineIndex, EXTI_Lines_t copy_Line[], EXTI_IntSignalSensitive_t copy_Mode);

u8 EXTI_u8InitISRWithFunction(u8 Copy_Index, EXTI_InterruptId_t Copy_ExtiId[], EXTI_voidPtrToFunction Copy_PtrFunction[], void * Copy_Parameter[]);
#endif /*File_H_*/

/*** End of File **************************************************************/
