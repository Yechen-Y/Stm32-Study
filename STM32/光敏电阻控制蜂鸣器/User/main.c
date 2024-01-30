#include "stm32f10x.h"  // Device header
#include "LightSensor.h"
#include "Buzzer.h"
int main(void)
{
	Buzzer_Init();
	LightSensor_Init();
while(1)
{
	if(LightSensor_Get()==1)
	{
		Buzzer_On();
	}
	else
	{
		Buzzer_Off();
	}
}
}
