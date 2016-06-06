#ifndef __GPIO_setting_H__
#define __GPIO_setting_H__
#include <stdint.h>
#include "stm32f10x_gpio.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
void GPIO_conf(GPIO_TypeDef* GPIOx, uint16_t Pin, int Speed, int Mode);


#endif //__GPIO_setting_H__
