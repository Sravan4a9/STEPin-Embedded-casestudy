#include "project_config.h"

#include "delay.h"
#include "led.h"

#include "activity_1.h"
#include "activity_2.h"
#include "activity_3.h"

/**
 * @brief Configure ADC
 * 
 */
void InitADC()
{
    ADMUX|=1<<REFS0;
    /* ADC is Enabled and Set to 128 Prescalar */
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

/**
 * @brief ADC conversion starts
 * 
 * @param ch 
 * @return uint16_t 
 */
uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b000000111;
    ADMUX|=ch;
    ADCSRA|=1<<ADSC;            
    while(!(ADCSRA&(1<<ADIF))); // ADC Interrupt Flag
    ADCSRA|=1<<ADIF;
    return(ADC);
}

/**
 * @brief Intializing ADC port 
 * 
 */
void activity_2()
{
    InitADC();
    /* Set PORTC */
	DDRC|=(1<<PC0);
}