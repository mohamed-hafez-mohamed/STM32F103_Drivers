/**
 * @file Gpio_DriverLib.cpp
 * @brief Gpio Driver Source File.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */
/************************************
INCLUDES
************************************/
#include "MCAL\GPIO\GPIO_interface.h"
#include "Gpio.hpp"
/************************************
EXTERN VARIABLES
************************************/

/************************************
PRIVATE MACROS / DEFINES / CONSTANT EXPRESSIONS
************************************/

/************************************
PRIVATE TYPEDEFS / CLASSES
************************************/

/************************************

STATIC / ANONYMOUS NAMESPACE VARIABLES
************************************/

/************************************

GLOBAL VARIABLES
************************************/

/************************************

STATIC FUNCTION PROTOTYPES
************************************/

/************************************

STATIC FUNCTION IMPLEMENTATION
************************************/

/************************************

GLOBAL FUNCTIONS IMPLEMENTATION
**********************************/
using namespace HAL::gpio;

void Gpio::init(void)
{
   /** 
	 * Initialization is done in the mcal libray.
	 * Add any initialization code if needed.
	 */
}

bool pin_view::get_pin_value(void) const
{
	return static_cast<bool>(GPIO_u8GetPinValue(static_cast<GPIO_PinId_t>(m_pin)));
}

pin_view::operator bool(void) const
{
	return static_cast<bool>(GPIO_u8GetPinValue(static_cast<GPIO_PinId_t>(m_pin)));
}

void pin::set_direction(direction pin_direction)
{
	GPIO_voidSetPinMode(static_cast<GPIO_PinId_t>(m_pin), static_cast<GPIO_PIN_MODE>(pin_direction));
}

void pin::set_pin(void)
{
	GPIO_voidSetPinValue(static_cast<GPIO_PinId_t>(m_pin), static_cast<u8>(true));
}

void pin::clear_pin(void)
{
	GPIO_voidSetPinValue(static_cast<GPIO_PinId_t>(m_pin), static_cast<u8>(false));
}

void pin::toggle_pin(void)
{
	GPIO_voidTogPinValue(static_cast<GPIO_PinId_t>(m_pin));
}

void pin::write_pin(bool pin_state)
{
	GPIO_voidSetPinValue(static_cast<GPIO_PinId_t>(m_pin), static_cast<u8>(pin_state));
}

pin& pin::operator =(bool pin_state)
{
   GPIO_voidSetPinValue(static_cast<GPIO_PinId_t>(m_pin), static_cast<u8>(pin_state));
	return *this;
}

port_width port_view::get_port_value(void) const
{
	
}

port_view::operator port_width(void) const
{
	
}

void port::write_port(port_width port_state)
{
	GPIO_voidSetPortValue(static_cast<GPIO_PortId_t>(m_port), static_cast<u16>(port_state));
}

port& port::operator =(port_width port_state)
{
   GPIO_voidSetPortValue(static_cast<GPIO_PortId_t>(m_port), static_cast<u16>(port_state));
	return *this;
}

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/