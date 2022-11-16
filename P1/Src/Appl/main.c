#include "main.h"

#define TIMERDEFAULTVALUE        0xF42400U   /* 1 second */
// state variable to keep track of led current state

uint8 LedState = LED_OFF;

int main()
{
	/* Initialize Port module */
	Port_Init(Port_Cfgs);
	/* Initialize SysTick */
	SysTick_Init(&SysTick_Config);
	/* Initialize the Interrupt Controller module */
	IntCrtl_Init(&IntCtrl_Config);
	
	// reset the ON and OFF counters
	ON_TIME_COUNT_SIGNAL = 1U;
	OFF_TIME_COUNT_SIGNAL = 1U;

	while(1)
	{
			/* code */
	}
}

void Appl_SysTick_Cbk()
{
	if (LedState == LED_OFF)
	{
		Led_Ctrl (LED_BLUE, LED_ON);
		SysTick_SetTime(TIMERDEFAULTVALUE * OFF_TIME_COUNT_SIGNAL);
		LedState = LED_ON;
	}
	else
	{
		Led_Ctrl (LED_BLUE, LED_OFF);
		SysTick_SetTime(TIMERDEFAULTVALUE * ON_TIME_COUNT_SIGNAL);
		LedState = LED_OFF;
	}

}	


void Switch_1_Pressed()
{
	ON_TIME_COUNT_SIGNAL++;
}

void Switch_2_Pressed()
{
	OFF_TIME_COUNT_SIGNAL++;
}
