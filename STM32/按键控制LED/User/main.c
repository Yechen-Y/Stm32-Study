#include "stm32f10x.h"  // Device header
#include "Led.h"
#include "Key.h"
#include "Delay.h"
int main(void)
{
	Led_Init();
	Key_Init();
while(1)
{
	Led_On();
}
}
