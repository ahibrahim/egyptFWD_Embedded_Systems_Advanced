/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Dio module Driver
 *
 *      \details  The Driver Provide Read and Write services for Dio Channels 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/    

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : Dio_ReadChannel()                                      
* \Description     : Read Dio Channel 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId : Dio Channel ID                 
* \Parameters (out): None                                                     
* \Return value:   : DioLevelType: Low / High 
*******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType dioLevel = DIO_LEVEL_UNKWN;
    uint8 pinNumber = ChannelId & 0x0F;
    uint8 portNumber = (ChannelId & 0xF0) >> 4;

    switch (portNumber)
    {
        case PORT_A:
            dioLevel = (Dio_LevelType) ((PORT_A_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01); 
        break;
        case PORT_B:
            dioLevel = (Dio_LevelType) ((PORT_B_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01); 
        break;
        case PORT_C:
            dioLevel = (Dio_LevelType) ((PORT_C_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01); 
        break;
        case PORT_D:
            dioLevel = (Dio_LevelType) ((PORT_D_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01); 
        break;
        case PORT_E:
            dioLevel = (Dio_LevelType) ((PORT_E_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01); 
        break;
        case PORT_F:
            dioLevel = (Dio_LevelType) ((PORT_F_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01); 
        break;
        default:;
    }

    return dioLevel;

}

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
    Dio_LevelType Level)
{
	  uint8 pinNumber = 0x00;
    uint8 portNumber = 0x00;

    pinNumber = ChannelId & 0x0F;
    portNumber = (ChannelId & 0xF0) >> 4;

    switch (portNumber)
    {
        case PORT_A:
            BITBAND_MAP(DIO_PA_GPIODATA_APB, pinNumber) = Level; 
        break;
        case PORT_B:
            BITBAND_MAP(DIO_PB_GPIODATA_APB, pinNumber) = Level; 
        break;
        case PORT_C:
            BITBAND_MAP(DIO_PC_GPIODATA_APB, pinNumber) = Level;  
        break;
        case PORT_D:
            BITBAND_MAP(DIO_PD_GPIODATA_APB, pinNumber) = Level;  
        break;
        case PORT_E:
            BITBAND_MAP(DIO_PE_GPIODATA_APB, pinNumber) = Level;  
        break;
        case PORT_F:
         BITBAND_MAP(DIO_PF_GPIODATA_APB, pinNumber) = Level;
        break;
        default: ;
    }
}

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
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortID)
{
    Dio_PortLevelType dioPortLevel = 0xFF;

    switch (PortID)
    {
        case PORT_A:
            dioPortLevel = (Dio_PortLevelType) PORT_A_GPIODATA_APB.B.DATA; 
        break;
        case PORT_B:
            dioPortLevel = (Dio_PortLevelType) PORT_B_GPIODATA_APB.B.DATA;
        break;
        case PORT_C:
            dioPortLevel = (Dio_PortLevelType) PORT_C_GPIODATA_APB.B.DATA; 
        break;
        case PORT_D:
            dioPortLevel = (Dio_PortLevelType) PORT_D_GPIODATA_APB.B.DATA; 
        break;
        case PORT_E:
            dioPortLevel = (Dio_PortLevelType) PORT_E_GPIODATA_APB.B.DATA; 
        break;
        case PORT_F:
            dioPortLevel = (Dio_PortLevelType) PORT_F_GPIODATA_APB.B.DATA; 
        break;
        default: ;
    }

    return dioPortLevel;
}

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
    Dio_PortLevelType Level)
{
    uint8 pinNumber;
    switch (PortId)
    {
        case PORT_A:
            for(pinNumber = 0 ; pinNumber < PORT_A_MAX_CHANNELS; pinNumber++)
            {
                BITBAND_MAP(DIO_PA_GPIODATA_APB, pinNumber) = (Dio_LevelType) ((Level >> pinNumber) & 0x01);
            } 
        break;
        case PORT_B:
            for(pinNumber = 0 ; pinNumber < PORT_B_MAX_CHANNELS; pinNumber++)
            {
                BITBAND_MAP(DIO_PB_GPIODATA_APB, pinNumber) = (Dio_LevelType) ((Level >> pinNumber) & 0x01);
            } 
        break;
        case PORT_C:
            for(pinNumber = 0 ; pinNumber < PORT_C_MAX_CHANNELS; pinNumber++)
            {
                BITBAND_MAP(DIO_PC_GPIODATA_APB, pinNumber) = (Dio_LevelType) ((Level >> pinNumber) & 0x01);
            }   
        break;
        case PORT_D:
            for(pinNumber = 0 ; pinNumber < PORT_D_MAX_CHANNELS; pinNumber++)
            {
                BITBAND_MAP(DIO_PD_GPIODATA_APB, pinNumber) = (Dio_LevelType) ((Level >> pinNumber) & 0x01);
            }  
        break;
        case PORT_E:
            for(pinNumber = 0 ; pinNumber < PORT_E_MAX_CHANNELS; pinNumber++)
            {
                BITBAND_MAP(DIO_PE_GPIODATA_APB, pinNumber) = (Dio_LevelType) ((Level >> pinNumber) & 0x01);
            }  
        break;
        case PORT_F:
            for(pinNumber = 0 ; pinNumber < PORT_F_MAX_CHANNELS; pinNumber++)
            {
                BITBAND_MAP(DIO_PF_GPIODATA_APB, pinNumber) = (Dio_LevelType) ((Level >> pinNumber) & 0x01);
            }  
        break;
        default: ;
    }
}

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
void Dio_FlipChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType dioLevel;
    uint8 pinNumber = ChannelId & 0x0F;
    uint8 portNumber = (ChannelId & 0xF0) >> 4;

    switch (portNumber)
    {
        case PORT_A:
            dioLevel = (Dio_LevelType) (((uint32) PORT_A_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01);
            BITBAND_MAP(DIO_PA_GPIODATA_APB, pinNumber) = !dioLevel;
        break;
        case PORT_B:
            dioLevel = (Dio_LevelType) ((PORT_B_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01);
            BITBAND_MAP(DIO_PB_GPIODATA_APB, pinNumber) = !dioLevel; 
        break;
        case PORT_C:
            dioLevel = (Dio_LevelType) ((PORT_C_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01);
            BITBAND_MAP(DIO_PC_GPIODATA_APB, pinNumber) = !dioLevel; 
        break;
        case PORT_D:
            dioLevel = (Dio_LevelType) ((PORT_D_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01);
            BITBAND_MAP(DIO_PD_GPIODATA_APB, pinNumber) = !dioLevel; 
        break;
        case PORT_E:
            dioLevel = (Dio_LevelType) ((PORT_E_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01);
            BITBAND_MAP(DIO_PE_GPIODATA_APB, pinNumber) = !dioLevel;  
        break;
        case PORT_F:
            dioLevel = (Dio_LevelType) ((PORT_F_GPIODATA_APB.B.DATA >> pinNumber)  & 0x01);
            BITBAND_MAP(DIO_PF_GPIODATA_APB, pinNumber) = !dioLevel;  
        break;
        default: ;
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
