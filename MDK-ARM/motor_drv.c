#include "motor_drv.h"                 

void motor_Init(void)
{
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);        //启动pwm输出
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL); //启动编码器
}


void set_ccr(uint16_t ccr)//0到99间取值
{
    __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,ccr); 
}

void motor_drive(int speed)
{
    if(speed>0)
    {
        HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_RESET);
    }

    if(speed<0)
    {
        HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_SET);
    }

    if(speed==0)
    {
        HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_RESET);  
    }

    set_ccr((uint16_t)speed);
}
