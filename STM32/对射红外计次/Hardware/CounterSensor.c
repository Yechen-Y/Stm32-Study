#include "stm32f10x.h"                  // Device header

uint16_t CounterSensor_Count;
void CounterSensor_Init(void)
{
/*配置RCC即时钟，配置GPIO模式，配置AFIO选择端口，配置EXTI边沿触发方式即响应方式，配置NVIC优先级*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_14;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line=EXTI_Line14;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
}

uint16_t CounterSensor_Get(void)
{
	return CounterSensor_Count;
}
void EXTI15_10_IRQHandler(void)
{
//中断标志位的判断
	if(EXTI_GetITStatus(EXTI_Line14)== SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)==0)
		{
			CounterSensor_Count++;
			EXTI_ClearITPendingBit(EXTI_Line14);
		}
	}
}	
