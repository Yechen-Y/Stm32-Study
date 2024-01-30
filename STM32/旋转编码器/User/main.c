#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
int main(void)
{
	OLED_Init();
	Encoder_Init();
	OLED_ShowString(1,1,"Count:");
while(1)
{
	OLED_ShowSignedNum(2,1,Encoder_Get(),5);
}
}
