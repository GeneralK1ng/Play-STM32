//
// Created by General_K1ng on 2024/4/24.
//

#include "stm32f10x.h"

/**
 * @brief 微秒级别延迟
 * @param xus 延迟时长，范围：0-233015
 */
void Delay_us(uint32_t xus) {
    // 设定定时器重装值
    SysTick->LOAD = xus * 72;
    // 清空当前计数值
    SysTick->VAL = 0x00;
    // 设置时钟为HCLK，启动定时器
    SysTick->CTRL = 0x00000005;
    // 等待计数器
    while (!(SysTick->CTRL & 0x00010000));
    // 关闭定时器
    SysTick->CTRL = 0x00000004;
}

/**
 * @brief 毫秒级别延迟
 * @param xms 延迟时长，范围：0-4294967295
 */
void Delay_ms(uint32_t xms) {
    while(xms--) {
        Delay_us(1000);
    }
}

/**
 * @brief 秒级别延迟
 * @param s 延迟时长，范围：0-4294967295
 */
void Delay_s(uint32_t xs) {
    while(xs--) {
        Delay_ms(1000);
    }
}