//
// Created by General_K1ng on 2024/4/25.
//

#ifndef __OLED_H
#define __OLED_H

#include "stdint.h"
/**
 * @brief 初始化OLED显示器
 * 
 * 该函数用于初始化OLED显示器，包括设置显示模式、分辨率和其他必要的初始化步骤。
 * 初始化后，OLED显示器将准备好显示文本和图形。
 */
void OLED_Init(void);

/**
 * @brief 清空OLED显示器
 * 
 * 该函数用于清空OLED显示器的显示内容，相当于在整个屏幕上画一片黑色。
 */
void OLED_Clear(void);

/**
 * @brief 在指定位置显示一个字符
 * 
 * @param Line 行号，指定字符显示的行位置
 * @param Column 列号，指定字符显示的列位置
 * @param Char 待显示的字符
 * 
 * 该函数用于在OLED显示器的指定位置显示一个字符。字符的行号和列号用于确定其在屏幕上的精确位置。
 */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);

/**
 * @brief 在指定位置显示一个字符串
 * 
 * @param Line 行号，指定字符串显示的起始行位置
 * @param Column 列号，指定字符串显示的起始列位置
 * @param String 待显示的字符串
 * 
 * 该函数用于在OLED显示器的指定位置开始显示一个字符串。字符串将从给定的行和列位置开始，按顺序显示。
 */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);

/**
 * @brief 在指定位置显示一个无符号整数
 * 
 * @param Line 行号，指定数字显示的起始行位置
 * @param Column 列号，指定数字显示的起始列位置
 * @param Number 待显示的无符号整数
 * @param Length 整数显示的位数
 * 
 * 该函数用于在OLED显示器的指定位置显示一个无符号整数。位数参数用于控制整数的显示宽度。
 */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

/**
 * @brief 在指定位置显示一个有符号整数
 * 
 * @param Line 行号，指定数字显示的起始行位置
 * @param Column 列号，指定数字显示的起始列位置
 * @param Number 待显示的有符号整数
 * @param Length 整数显示的位数
 * 
 * 该函数用于在OLED显示器的指定位置显示一个有符号整数。位数参数用于控制整数的显示宽度。
 */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);

/**
 * @brief 在指定位置显示一个无符号十六进制数
 * 
 * @param Line 行号，指定数字显示的起始行位置
 * @param Column 列号，指定数字显示的起始列位置
 * @param Number 待显示的无符号十六进制数
 * @param Length 十六进制数显示的位数
 * 
 * 该函数用于在OLED显示器的指定位置显示一个无符号十六进制数。位数参数用于控制十六进制数的显示宽度。
 */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

/**
 * @brief 在指定位置显示一个无符号二进制数
 * 
 * @param Line 行号，指定数字显示的起始行位置
 * @param Column 列号，指定数字显示的起始列位置
 * @param Number 待显示的无符号二进制数
 * @param Length 二进制数显示的位数
 * 
 * 该函数用于在OLED显示器的指定位置显示一个无符号二进制数。位数参数用于控制二进制数的显示宽度。
 */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
