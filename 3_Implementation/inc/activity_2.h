#ifndef __ACTIVITY_2_H__
#define __ACTIVITY_2_H__

#include "project_config.h"
#include <util/delay.h>

#include <avr/io.h>

/**
 * Include files
 */ 
void InitADC();

uint16_t ReadADC(uint8_t ch);

void activity_2();

#endif  /** __ACTIVITY_2_H_ */