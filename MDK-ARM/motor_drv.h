#ifndef  __motor_drv_H__
#define  __motor_drv_H__

#include "main.h"
#include "stm32f4xx.h"
#include "tim.h"
#include "gpio.h" 

void motor_Init(void);
void set_ccr(uint16_t ccr);
void motor_drive(int speed);



#endif
