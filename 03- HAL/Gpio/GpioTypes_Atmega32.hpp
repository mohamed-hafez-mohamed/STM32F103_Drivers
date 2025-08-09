/**
 * @file E: GpioTypes_Atmega32.hpp
 * @brief Gpio Types For Atmega32 Target.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef GPIO_TYPES_ATMEGA_32_HPP
#define GPIO_TYPES_ATMEGA_32_HPP
/************************************
INCLUDES
************************************/
#include <cstdint>
/************************************
 * MACROS / CONSTANT EXPRESSIONS
 ************************************/

/************************************
EXPORTED VARIABLES
************************************/

/************************************
NAMESPACES
************************************/
namespace HAL
{
	namespace gpio
	{
		namespace types
		{
			/**
          * @brief Gpio Port ID Enumeration.
          */
			enum class port_id : std::uint8_t
			{
            A = UINT8_C(0),              ///< Port A ID
				B = UINT8_C(1),              ///< Port B ID
				C = UINT8_C(2),              ///< Port C ID
			}; 

			/**
          * @brief Gpio Pin ID Enumeration.
          */
			enum class pin_id : std::uint8_t
			{
				PA0  = UINT8_C(10),          ///< Pin PA0 ID
				PA1  = UINT8_C(11),          ///< Pin PA1 ID
				PA2  = UINT8_C(12),          ///< Pin PA2 ID
				PA3  = UINT8_C(13),          ///< Pin PA3 ID
				PA4  = UINT8_C(14),          ///< Pin PA4 ID
				PA5  = UINT8_C(15),          ///< Pin PA5 ID
				PA6  = UINT8_C(16),          ///< Pin PA6 ID
				PA7  = UINT8_C(17),          ///< Pin PA7 ID
            PA8  = UINT8_C(29),          ///< Pin PA8 ID
				PA9  = UINT8_C(30),          ///< Pin PA9 ID
				PA10 = UINT8_C(31),          ///< Pin PA10 ID
				PA11 = UINT8_C(32),          ///< Pin PA11 ID
				PA12 = UINT8_C(33),          ///< Pin PA12 ID
				PA15 = UINT8_C(34),          ///< Pin PA15 ID
            PB0  = UINT8_C(18),          ///< Pin PB0 ID
				PB1  = UINT8_C(19),          ///< Pin PB1 ID
				PB3  = UINT8_C(39),          ///< Pin PB3 ID
				PB4  = UINT8_C(40),          ///< Pin PB4 ID
				PB5  = UINT8_C(41),          ///< Pin PB5 ID
				PB6  = UINT8_C(42),          ///< Pin PB6 ID
				PB7  = UINT8_C(43),          ///< Pin PB7 ID
				PB8  = UINT8_C(45),          ///< Pin PD0 ID
				PB9  = UINT8_C(46),          ///< Pin PD1 ID
				PB10 = UINT8_C(21),          ///< Pin PD2 ID
				PB11 = UINT8_C(22),          ///< Pin PD3 ID
				PB12 = UINT8_C(25),          ///< Pin PD4 ID
				PB13 = UINT8_C(26),          ///< Pin PD5 ID
				PB14 = UINT8_C(27),          ///< Pin PD6 ID
				PB15 = UINT8_C(28),          ///< Pin PD7 ID
				PC0  = UINT8_C(22),          ///< Pin PD0 ID
				PC13 = UINT8_C(2),           ///< Pin PD1 ID
				PC14 = UINT8_C(3),           ///< Pin PD2 ID
				PC15 = UINT8_C(4),           ///< Pin PD3 ID
			};

			/**
          * @brief Gpio Direction Enumeration.
          */
			enum direction : std::uint8_t
			{
				Input = UINT8_C(0),          ///< Zero Means Input
				Output = UINT8_C(1)          ///< One Means Output
			};
			/**
          * @brief Gpio Port Width.
          */
			using port_width = std::uint16_t;
		} // namespace types
	} // namespace gpio
} // namespace HAL

#endif // GPIO_TYPES_ATMEGA_32_HPP

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/