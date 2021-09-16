  
#ifndef __PROJECT_CONFIG_H__
#define __PROJECT_CONFIG_H__

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */
#define SW1_PORT (PORTD1)   //Switch 1 port number
#define SW2_PORT (PORTD0)   //Switch 2 port number
#define SW_PIN (PIND)      //Switch PIN number
#define Output_Compare_Register_1_A (OCR1A)
#endif /* __PROJECT_CONFIG_H__ */