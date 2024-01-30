#include "stm32f10x.h"                  // Device header

void Led_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructrue;
	GPIO_InitStructrue.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructrue.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructrue.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructrue);
	GPIO_SetBits(GPIOA,GPIO_Pin_0 | GPIO_Pin_1);
}

void Led_Turn(uint8_t i)
{
	switch(i)
	{
		case 1:
			if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0)==1)
			{
				GPIO_ResetBits(GPIOA,GPIO_Pin_0);
			}
			else
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_0);
			}
			break;
			case 2:
			if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==1)
			{
				GPIO_ResetBits(GPIOA,GPIO_Pin_1);
			}
			else
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_1);
			}
			break;
			default:
				break;
	}
}
void Led_On(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}
void Led_Off(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
}