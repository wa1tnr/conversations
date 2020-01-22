/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_ZERO_
#define _VARIANT_ARDUINO_ZERO_

// The definitions here needs a SAMD core >=1.6.6
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10606

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK	(F_CPU)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (16u)
#define NUM_DIGITAL_PINS     (16u)
#define NUM_ANALOG_INPUTS    (6u)
#define NUM_ANALOG_OUTPUTS   (9u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + PIN_A0 : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs

#define PIN_LED_13           (6u) // Red
#define PIN_LED_RXL          (7u) // Green
#define PIN_LED_TXL          (8u) // Blue
#define PIN_LED              PIN_LED_13
#define PIN_LED2             PIN_LED_RXL
#define PIN_LED3             PIN_LED_TXL
#define LED_BUILTIN          PIN_LED_13


/*
 * Analog pins
 */
#define PIN_A0               (0ul)
#define PIN_A1               (1ul)
#define PIN_A2               (2ul)
#define PIN_A3               (3ul)
#define PIN_A4               (4ul)
#define PIN_A5               (5ul)
#define PIN_DAC0             (8ul)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;

#define ADC_RESOLUTION		12

/*
 * Serial interfaces
 */

// Serial1 (sercom 0)
#define PIN_SERIAL1_RX       (5ul)
#define PIN_SERIAL1_TX       (4ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)

/*
 * SPI Interfaces
 */

// TODO tnr: mention (right here) that metro m0 and feather m0 were conflated by tnr ;)
// (tnr: have used documentation and code of both, without bothering to refactor)
// (tnr: oops.)

// TODO tnr: can interfaces count be incremented to '2' here?
#define SPI_INTERFACES_COUNT 2 // #define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (2ul) // PA06
#define PIN_SPI_MOSI         (0ul) // PA04
#define PIN_SPI_SCK          (1ul) // PA05
#define PERIPH_SPI           sercom0
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_2

// SPI FLASH
// TODO tnr: review all this as conflation of feather m0 with metro m0 happened

// tnr wanted: correct D-numbers for serpente, here (see CircuitPython stuff).
// tnr note: serpente-core from technoblogy assumed throughout.

/* circuitpython for serpente follows */
/*
from
 circuitpython/ports/atmel-samd/boards/serpente/mpconfigboard.h 

  6 #define SPI_FLASH_MOSI_PIN          &pin_PA16 // tnr D11
  7 #define SPI_FLASH_MISO_PIN          &pin_PA18 // tnr D12
  8 #define SPI_FLASH_SCK_PIN           &pin_PA17 // tnr  D9
  9 #define SPI_FLASH_CS_PIN            &pin_PA15 // tnr D10

from serpente-core technoblogy github repository:

 42   // 9..12 - SPI Flash
 43   { PORTA, 17, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT
 44   { PORTA, 15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT
 45   { PORTA, 16, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT
 46   { PORTA, 18, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT
*/

// verified after conflation feather and metro:
#define PIN_SPI1_MISO        (12ul) //  PA18 // D12  //     PA18 FLASH_MISO // D12
#define PIN_SPI1_MOSI        (11ul) //  PA16 // D11  //     PA16 FLASH_MOSI // D11
#define PIN_SPI1_SCK         (9ul)  //  PA17 //  D9  //     PA17 FLASH_SCK  //  D9
#define PIN_SPI1_SS          (10ul) //  PA15 // D10  //     PA15 FLASH_CS   // D10

// TODO tnr: which sercom is the SPI flashROM on?
// answer: schematic from arturo182 says 'sercom3 is always spi flash'

// TODO tnr: hint may be ATSAMD21E18A or the like - what did arturo182 use for a chip?

// TODO tnr: What are the names used for SPI flashROM (TX and RX seem likely to be USART stuff)

#define PERIPH_SPI1          sercom3 // serpente r2 schematic
#define PAD_SPI1_TX          SPI_PAD_0_SCK_1 // tnr checked datasheet e18a: sercom3 pad 0
#define PAD_SPI1_RX          SERCOM_RX_PAD_2 // tnr checked datasheet e18a: sercom3 pad 2

static const uint8_t SS	  = 3 ; // tnr PA7 ?
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

static const uint8_t SS1  = 10 ; // HW SS isn't used.  Set here only for reference. tnr: ?
// tnr: SS1 = 10 still good.
static const uint8_t MOSI1 = PIN_SPI_MOSI ; // tnr // odd but metro m0 does this
static const uint8_t MISO1 = PIN_SPI_MISO ; // tnr // odd but metro m0 does this
static const uint8_t SCK1  = PIN_SPI_SCK ;  // tnr // odd but metro m0 does this

// notes tnr - all that NO NO NO stuff probably from conflation of
//  the feather m0 express with the metro m0 express tnr ;)

// factual metro m0 express follows.

// PB03 // D36 // line 94 // SPI Flash MISO // metro m0 only
// PB22 // D37 // line 95 // SPI Flash MOSI // metro m0 only
// PB23 // D38 // line 96 // SPI Flash SCK  // metro m0 only
// PA13 // D39 // line 98 // SPI Flash SS   // metro m0 only

/* adafruit metro m0 stuff follows */
// variant.cpp metro m0:

/*
 92   // 36..38 - Secondary SPI
 93   // ----------------------
 94   { PORTB, 03, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT
 95   { PORTB, 22, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT
 96   { PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT
 97   // 39 Secondary SPI SS
 98   { PORTA, 13, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXT

 94 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // SPI Flash MISO
 95 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // SPI FLash MOSI
 96 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // SPI FLash SCK
 97 
 98 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 }, // SPI Flash SS
*/

/* adafruit metro m0 for circuitpython follows. */
/*

#define SPI_FLASH_MOSI_PIN          &pin_PB22
#define SPI_FLASH_MISO_PIN          &pin_PB03
#define SPI_FLASH_SCK_PIN           &pin_PB23
#define SPI_FLASH_CS_PIN            &pin_PA13

*/

/* end of adafruit metro m0 for circuitpython - tnr */

/* end of adafruit metro m0 stuff tnr */

// TNR FINAL: 22 Jan Wed 16:43 UTC - everything been gone over, perhaps.
// should compile or throw comprehensible errors that can be diagnosed.

// ready for a primitive test, perhaps.

// TODO 16:44 UTC 22 Jan - the SPI lib stuff (to exercise the code found here, in variant.h, properly)

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (4u)
#define PIN_WIRE_SCL         (5u)
#define PERIPH_WIRE          sercom0
#define WIRE_IT_HANDLER      SERCOM0_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (13ul)
#define PIN_USB_DM          (14ul)
#define PIN_USB_DP          (15ul)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;

extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

//QSPI Pins
#define PIN_QSPI_SCK    (9u)
#define PIN_QSPI_CS     (10u)
#define PIN_QSPI_IO0    (11u)
#define PIN_QSPI_IO1    (12u)

#endif /* _VARIANT_ARDUINO_ZERO_ */

