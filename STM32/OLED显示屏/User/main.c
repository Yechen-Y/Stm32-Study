#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	OLED_ShowChar(1,1,'I');
	OLED_ShowString(2,1,"love you");
	OLED_ShowBinNum(3,1,0xAA55,16);
while(1)
{
}
}
