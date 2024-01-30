#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CounterSensor.h"
int main(void)
{
	OLED_Init();
	OLED_ShowString(1,1,"Count:");
	CounterSensor_Init();
while(1)
{
	OLED_ShowNum(2,1,CounterSensor_Get(),5);
}
}
