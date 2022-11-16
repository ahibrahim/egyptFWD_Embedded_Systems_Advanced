/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Switch.h
 *       Module:  Switch
 *
 *  Description:  header file for Switch Module    
 *  
 *********************************************************************************************************************/
#ifndef SWITCH_H
#define SWITCH_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Switch_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static uint8 ON_TIME_COUNT_SIGNAL;
static uint8 OFF_TIME_COUNT_SIGNAL;
/******************************************************************************
* \Syntax          : Switch_Pressed()                                      
* \Description     : Take an action if switch pressed
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : sw: Switch ID (SW_0, SW_1)                 
* \Parameters (out):                                                    
* \Return value:   : None
*******************************************************************************/
void Switch_Pressed (SwitchType sw);

#endif  /* SWITCH_H */

/**********************************************************************************************************************
 *  END OF FILE: Switch.h
 *********************************************************************************************************************/