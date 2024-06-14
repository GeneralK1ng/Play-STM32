//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "Delay.h"
#include "Timer.h"
#include "stm32f10x.h"

uint16_t Num;

int main(void) {
    OLED_Init();
    Timer_Init();

    //OLED_ShowString(1, 3 , "Hello World!");
    //OLED_ShowString(3, 3 , "General_K1ng");

    while (1) {
        OLED_ShowString(2, 1, "Num:");
        OLED_ShowNum(2, 6, Num, 5);
    }
}
/**
 * TIM2中断服务函数
 * 该函数在TIM2中断发生时被调用，用于处理定时器2的更新中断。
 * 主要功能是增加一个计数器，并清除中断标志位。
 */
void TIM2_IRQHandler(void) {
    // 检查TIM2的更新中断是否发生
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        // 中断发生时，计数器加一
        Num++;
        // 清除中断标志位，防止中断再次触发
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
