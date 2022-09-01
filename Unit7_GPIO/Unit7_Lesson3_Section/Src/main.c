/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "STM32F103C6_GPIO_Driver.h"
#include "sTM32F103x8.h"
#include "LCD.h"
#include "Key_Pad_Driver.h"
#define Zero	0x40
#define One 	0x79
#define Two		0x24
#define Three	0x30
#define Four	0x19
#define Five	0x12
#define Six		0x02
#define Seven	0x78
#define Eight	0x00
#define Nine	0x18
void clock_init()
{
	RCC_GPIOA_CLK_EN();  // Enable GPIOA Clock
	RCC_GPIOB_CLK_EN();   //Enable GPIOB Clock
}
void Gpio_init(){
	GPIO_Pin_Config_t Pin_Cfg;
	Pin_Cfg.GPIO_Pin_Number = GPIO_PIN_9 ;
	Pin_Cfg.GPIO_Mode = GPIO_Mode_Output_PP;
	Pin_Cfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
	Pin_Cfg.GPIO_Pin_Number = GPIO_PIN_10 ;
	Pin_Cfg.GPIO_Mode = GPIO_Mode_Output_PP;
	Pin_Cfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
	Pin_Cfg.GPIO_Pin_Number = GPIO_PIN_11 ;
	Pin_Cfg.GPIO_Mode = GPIO_Mode_Output_PP;
	Pin_Cfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
	Pin_Cfg.GPIO_Pin_Number = GPIO_PIN_12 ;
	Pin_Cfg.GPIO_Mode = GPIO_Mode_Output_PP;
	Pin_Cfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
	Pin_Cfg.GPIO_Pin_Number = GPIO_PIN_13 ;
	Pin_Cfg.GPIO_Mode = GPIO_Mode_Output_PP;
	Pin_Cfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
	Pin_Cfg.GPIO_Pin_Number = GPIO_PIN_14 ;
	Pin_Cfg.GPIO_Mode = GPIO_Mode_Output_PP;
	Pin_Cfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
	Pin_Cfg.GPIO_Pin_Number = GPIO_PIN_15 ;
	Pin_Cfg.GPIO_Mode = GPIO_Mode_Output_PP;
	Pin_Cfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
}
void wait_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}
int main(void)
{

	clock_init();
	Gpio_init();
	LCD_Init();
	unsigned char seg[] = {Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Zero};
	unsigned char lcd[] = {'0','1','2','3','4','5','6','7','8','9','0'};
	for(unsigned char i = 0 ; i< 11 ; i++)
	{
		MCAL_GPIO_WritePort(GPIOB, seg[i]<<9);
		LCD_Send_A_Character(lcd[i]);
		wait_ms(100);
	}
	LCD_Clear_Screen();
	keypad_init();
	LCD_Send_A_String("LCD IS Ready");
	char Keypressed;
	LCD_Init();
	keypad_init();
	while (1)
	{
		Keypressed = Keypad_getKey();
		switch(Keypressed)
		{
		case  ('A'): break; //No Key Pressed
		case  ('?'): LCD_Clear_Screen();break;
		default: LCD_Send_A_Character(Keypressed);break;
		}
	}
}

