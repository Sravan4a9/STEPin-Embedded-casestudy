#include "project_config.h"

#include "delay.h"
#include "led.h"
#include "activity_1.h"
#include "activity_2.h"
#include "activity_3.h"


/**
 * @brief Setting non-inverting mode, prescalar and Fast PWM mode
 * 
 */
void activity_3()
{
    TCCR1A |=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B |=(1<<WGM12)|(1<<CS11); 
    /* Set PORTB */
    DDRB|=1<<PB1;

}