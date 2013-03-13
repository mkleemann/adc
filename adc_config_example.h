/**
 * ----------------------------------------------------------------------------
 *
 * "THE ANY BEVERAGE-WARE LICENSE" (Revision 42 - based on beer-ware license):
 * <dev@layer128.net> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a be(ve)er(age) in return. (I don't
 * like beer much.)
 *
 * Matthias Kleemann
 *
 * ----------------------------------------------------------------------------
 *
 * \file adc_config_example.h
 *
 * \date Created: 24.02.2012 19:59:37
 * \author Matthias Kleemann
 *
 * \section adc_config_example ADC example configuration
 *
 * Note, that the example given here is set up for use with atmega8. Other AVRs
 * may need some different settings, so please check before first use.
 *
 **/



#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/**
 * @brief set voltage reference
 *
 * \code
 * REFS1 REFS0 Voltage Reference Selection
 *     0     0 AREF, Internal Vref turned off
 *     0     1 AVCC with external capacitor at AREF pin
 *     1     0 Reserved
 *     1     1 Internal 2.56V Voltage Reference with external capacitor at
 *             AREF pin
 * \endcode
 */
#define ADC_REF_SELECT        (1 << REFS0)

/**
 * @brief input channel selection
 *
 * \code
 * MUX3..0 Single Ended Input
 *    0000 ADC0
 *    0001 ADC1
 *    0010 ADC2
 *    0011 ADC3
 *    0100 ADC4
 *    0101 ADC5
 *    0110 ADC6
 *    0111 ADC7
 *    1000
 *    1001
 *    1010
 *    1011
 *    1100
 *    1101
 *    1110 1.30V (VBG)
 *    1111 0V (GND)
 * \endcode
 */
#define ADC_INPUT_CHANNEL     0

/**
 * @brief selects the input pin used for ADC
 */
#define ADC_INPUT_PIN         C,ADC_INPUT_CHANNEL

/**
 * @brief prescaler value between Fosc and CLKadc
 *
 * \code
 * ADPS2 ADPS1 ADPS0 Division Factor
 *     0     0     0 2
 *     0     0     1 2
 *     0     1     0 4
 *     0     1     1 8
 *     1     0     0 16
 *     1     0     1 32
 *     1     1     0 64
 *     1     1     1 128
 * \endcode
 */
#define ADC_PRESCALER         (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)

/**
 * @brief use only upper 8bit of ADC value
 *
 * This causes ADLAR bit to be set, so the ADC value is left aligned. It
 * only returns the upper byte in this case, so it can be used directly
 * as 8bit value. It also causes the lower two bit to be discarded
 * (10bit -> 8bit)
 */
#ifdef __DOXYGEN__   // options, not always defined
   #define ADC_8BIT_RESOLUTION
#else
   //#define ADC_8BIT_RESOLUTION
#endif

/**
 * @brief use left alignment of 16bit value
 *
 * This causes the ADLAR bit to be set, so the ADC value is left aligned.
 * In this case it returns the full 16bit value with the upper 10 bit
 * defining the value. Other than the switch ADC_8BIT_RESOLUTION, this
 * does not remove anything.
 *
 * \sa ADC_8BIT_RESOLUTION
 */
#ifdef __DOXYGEN__   // options, not always defined
   #define ADC_LEFT_ALIGNED
#else
   #define ADC_LEFT_ALIGNED
#endif

#endif /* ADC_CONFIG_H_ */

