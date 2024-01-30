#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructre;
	GPIO_InitStructre.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructre.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructre.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructre);
	
while(1)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	Delay_ms(500);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	Delay_ms(500);
}
}
