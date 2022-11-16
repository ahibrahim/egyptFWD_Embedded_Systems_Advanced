/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dio_Types.h"
#include "Port_reg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DIO_PA_GPIODATA_APB       (uint32)(GPIO_PORT_A_APB_BASEADDR + GPIODATA_OFFSET)
#define DIO_PA_GPIODATA_AHB       (uint32)(GPIO_PORT_A_AHB_BASEADDR + GPIODATA_OFFSET)
#define DIO_PB_GPIODATA_APB       (uint32)(GPIO_PORT_B_APB_BASEADDR + GPIODATA_OFFSET)
#define DIO_PB_GPIODATA_AHB       (uint32)(GPIO_PORT_B_AHB_BASEADDR + GPIODATA_OFFSET) 
#define DIO_PC_GPIODATA_APB       (uint32)(GPIO_PORT_C_APB_BASEADDR + GPIODATA_OFFSET)
#define DIO_PC_GPIODATA_AHB       (uint32)(GPIO_PORT_C_AHB_BASEADDR + GPIODATA_OFFSET) 
#define DIO_PD_GPIODATA_APB       (uint32)(GPIO_PORT_D_APB_BASEADDR + GPIODATA_OFFSET)
#define DIO_PD_GPIODATA_AHB       (uint32)(GPIO_PORT_D_AHB_BASEADDR + GPIODATA_OFFSET) 
#define DIO_PE_GPIODATA_APB       (uint32)(GPIO_PORT_E_APB_BASEADDR + GPIODATA_OFFSET)
#define DIO_PE_GPIODATA_AHB       (uint32)(GPIO_PORT_E_AHB_BASEADDR + GPIODATA_OFFSET) 
#define DIO_PF_GPIODATA_APB       (uint32)(GPIO_PORT_F_APB_BASEADDR + GPIODATA_OFFSET)
#define DIO_PF_GPIODATA_AHB       (uint32)(GPIO_PORT_F_AHB_BASEADDR + GPIODATA_OFFSET)    

#define PORT_A_MAX_CHANNELS       8
#define PORT_B_MAX_CHANNELS       8
#define PORT_C_MAX_CHANNELS       8
#define PORT_D_MAX_CHANNELS       8
#define PORT_E_MAX_CHANNELS       6
#define PORT_F_MAX_CHANNELS       5

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define BITBAND_MAP(REG, BIT)       (*((volatile uint32 *)(0x42000000 + ((uint32) (REG - 0x40000000) * 32) + (BIT * 4))))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : Dio_ReadChannel()                                      
* \Description     : Read Dio Channel 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId : Dio Channel ID                 
* \Parameters (out): None                                                     
* \Return value:   : DioLevelType: Low / High 
*******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
/******************************************************************************
* \Syntax          : Dio_WriteChannel()                                      
* \Description     : Write Dio Channel 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId : Dio Channel ID   
* \Parameters (in) : Level : Low / High               
* \Parameters (out): None                                                     
* \Return value:   : None 
*******************************************************************************/
void Dio_WriteChannel(
    Dio_ChannelType ChannelId, 
    Dio_LevelType Level);

/******************************************************************************
* \Syntax          : Dio_ReadPort()                                      
* \Description     : Read Dio Port 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortID : Dio Port ID                 
* \Parameters (out): None                                                     
* \Return value:   : Dio_PortLevelType 0-> 255 
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortID);

/******************************************************************************
* \Syntax          : Dio_WritePort()                                      
* \Description     : Write Dio Port 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId : Dio Port ID   
* \Parameters (in) : Level : Dio Port Level (0->255)              
* \Parameters (out): None                                                     
* \Return value:   : None 
*******************************************************************************/
void Dio_WritePort (
    Dio_PortType PortId, 
    Dio_PortLevelType Level);

/******************************************************************************
* \Syntax          : Dio_FlipChannel()                                      
* \Description     : Flip Dio Channel 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId : Dio Channel ID                 
* \Parameters (out): None                                                     
* \Return value:   : None 
*******************************************************************************/
void Dio_FlipChannel (Dio_ChannelType ChannelId);

#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
