/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick.h
 *       Module:  SysTick
 *
 *  Description:  header file for SysTick Module    
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SysTick_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
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
void SysTick_Init (const SysTick_ConfigType* SysTickConfig);


/******************************************************************************
* \Syntax          : SySTick_GetCurrentTicks()                                      
* \Description     : Get SysTick current tick count
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                 
* \Parameters (out): None                                                     
* \Return value:   : TickCount
*******************************************************************************/
SysTick_TickCount SysTick_GetCurrentTicks(void);

/******************************************************************************
* \Syntax          : SysTick_ResetReloadCounts()                                      
* \Description     : Set SysTick tick count
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ticks: tick count                 
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void SysTick_SetTime(uint32 ticks);

/******************************************************************************
* \Syntax          : SysTick_SetCbk()                                      
* \Description     : Set SysTick ISR Call back function with user call back
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                 
* \Parameters (out): None                                                     
* \Return value:   : TickCount
*******************************************************************************/
void SysTick_SetCbk(void(*Cbf)(void));

#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick.h
 *********************************************************************************************************************/
