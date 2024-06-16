//
// Created by General_K1ng on 2024/6/14.
//

#ifndef __PWM_DRIVING_LED_BREATHING_LIGHT_PWM_H
#define __PWM_DRIVING_LED_BREATHING_LIGHT_PWM_H

#include <stdint-gcc.h>

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetPrescaler(uint16_t Prescaler);

#endif //__PWM_DRIVING_LED_BREATHING_LIGHT_PWM_H
