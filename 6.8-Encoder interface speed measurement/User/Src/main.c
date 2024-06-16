//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "Delay.h"
#include "Timer.h"
#include "Encoder.h"
#include "stm32f10x.h"

int16_t speed;

int main(void) {
    OLED_Init();
    Timer_Init();
    Encoder_Init();

    OLED_ShowString(2,1,"Speed:");

    while (1) {
        OLED_ShowSignedNum(2, 7, speed, 5);
    }
}

/**
 * TIM2中断服务函数
 * 该函数在TIM2中断发生时被调用，用于处理编码器的速度采集。
 *
 * @note 本函数中没有对中断源进行详细检查，假定中断源仅为TIM2的更新事件。
 */
void TIM2_IRQHandler(void) {
    // 检查TIM2的更新中断状态，如果中断状态为设置，则表示中断发生。
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        // 读取编码器的计数，用于计算速度。
        speed = Encoder_GetCount();
        // 清除TIM2的更新中断待处理位，以防止中断持续触发。
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
