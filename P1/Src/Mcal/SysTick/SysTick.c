/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  SysTick module Driver
 *
 *      \details  The Driver Provide Initialization and configuration for SySTick  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysTick.h"
#include "SysCtrl_reg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/    

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (*SysTick_Cbf)(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : SySTick_Init()                                      
* \Description     : Initialiyation of SysTick peripheral
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : SysTickConfig: SySTick user configurations                 
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void SysTick_Init (const SysTick_ConfigType* SysTickConfig)
{
    
		/* Disable sysTick to set peripheral configurations*/
    STCTRL_REG.B.EN = 0x0;

    /* Configure Interrupt */
    STCTRL_REG.B.INTEN = SysTickConfig->IrqEnable;

    /* Configure Clock Source*/
    STCTRL_REG.B.CLK_SRC = SysTickConfig->ClkSrc;

    /* Reset current register */
    STCURRENT_REG.R = 0x000000;

    /* Load Count value */
    STRELOAD_REG.B.RELOAD = SysTickConfig->Ticks;

    /* Enable SysTick */
    STCTRL_REG.B.EN = 0x1;
		
		/* Set SysTick Call back function */
		SysTick_SetCbk(SysTickConfig->callback);
}

/******************************************************************************
* \Syntax          : SysTick_GetCurrentTicks()                                      
* \Description     : Get SysTick current tick count
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                 
* \Parameters (out): None                                                     
* \Return value:   : TickCount
*******************************************************************************/
SysTick_TickCount SysTick_GetCurrentTicks()
{
   
    /* Return current ticks from STCURRENT register */
    return (SysTick_TickCount) STCURRENT_REG.B.CURRENT;
}

/******************************************************************************
* \Syntax          : SysTick_SetTime()                                      
* \Description     : Set SysTick tick count
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ticks: tick count                 
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void SysTick_SetTime(uint32 ticks)
{
    /* Load Count value */
    STRELOAD_REG.B.RELOAD = ticks;
}

/******************************************************************************
* \Syntax          : SysTick_SetCbk()                                      
* \Description     : Set SysTick ISR Call back function with user call back
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                 
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void SysTick_SetCbk(void(*Cbf)(void))
{
	if(NULL_PTR != Cbf)
	{
		SysTick_Cbf = Cbf;
	}
}

/******************************************************************************
* \Syntax          : SysTick_Handler()                                      
* \Description     : SysTick Irq
*******************************************************************************/
void SysTick_Handler(void) __attribute__((used));
void SysTick_Handler(void)
{
    if(NULL_PTR != SysTick_Cbf)
		{
			SysTick_Cbf();
		}
}

/**********************************************************************************************************************
 *  END OF FILE: SySTick.c
 *********************************************************************************************************************/
