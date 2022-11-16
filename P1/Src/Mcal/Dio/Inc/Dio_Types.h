/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  Dio Data types
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_A               (Dio_PortType) 0x0A
#define PORT_B               (Dio_PortType) 0x0B
#define PORT_C               (Dio_PortType) 0x0C
#define PORT_D               (Dio_PortType) 0x0D
#define PORT_E               (Dio_PortType) 0x0E
#define PORT_F               (Dio_PortType) 0x0F

#define DIO_CHANNEL_A0      (Dio_ChannelType) 0xA0
#define DIO_CHANNEL_A1      (Dio_ChannelType) 0xA1
#define DIO_CHANNEL_A2      (Dio_ChannelType) 0xA2
#define DIO_CHANNEL_A3      (Dio_ChannelType) 0xA3
#define DIO_CHANNEL_A4      (Dio_ChannelType) 0xA4
#define DIO_CHANNEL_A5      (Dio_ChannelType) 0xA5
#define DIO_CHANNEL_A6      (Dio_ChannelType) 0xA6
#define DIO_CHANNEL_A7      (Dio_ChannelType) 0xA7

#define DIO_CHANNEL_B0      (Dio_ChannelType) 0xB0
#define DIO_CHANNEL_B1      (Dio_ChannelType) 0xB1
#define DIO_CHANNEL_B2      (Dio_ChannelType) 0xB2
#define DIO_CHANNEL_B3      (Dio_ChannelType) 0xB3
#define DIO_CHANNEL_B4      (Dio_ChannelType) 0xB4
#define DIO_CHANNEL_B5      (Dio_ChannelType) 0xB5
#define DIO_CHANNEL_B6      (Dio_ChannelType) 0xB6
#define DIO_CHANNEL_B7      (Dio_ChannelType) 0xB7

#define DIO_CHANNEL_C0      (Dio_ChannelType) 0xC0
#define DIO_CHANNEL_C1      (Dio_ChannelType) 0xC1
#define DIO_CHANNEL_C2      (Dio_ChannelType) 0xC2
#define DIO_CHANNEL_C3      (Dio_ChannelType) 0xC3
#define DIO_CHANNEL_C4      (Dio_ChannelType) 0xC4
#define DIO_CHANNEL_C5      (Dio_ChannelType) 0xC5
#define DIO_CHANNEL_C6      (Dio_ChannelType) 0xC6
#define DIO_CHANNEL_C7      (Dio_ChannelType) 0xC7

#define DIO_CHANNEL_D0      (Dio_ChannelType) 0xD0
#define DIO_CHANNEL_D1      (Dio_ChannelType) 0xD1
#define DIO_CHANNEL_D2      (Dio_ChannelType) 0xD2
#define DIO_CHANNEL_D3      (Dio_ChannelType) 0xD3
#define DIO_CHANNEL_D4      (Dio_ChannelType) 0xD4
#define DIO_CHANNEL_D5      (Dio_ChannelType) 0xD5
#define DIO_CHANNEL_D6      (Dio_ChannelType) 0xD6
#define DIO_CHANNEL_D7      (Dio_ChannelType) 0xD7

#define DIO_CHANNEL_E0      (Dio_ChannelType) 0xE0
#define DIO_CHANNEL_E1      (Dio_ChannelType) 0xE1
#define DIO_CHANNEL_E2      (Dio_ChannelType) 0xE2
#define DIO_CHANNEL_E3      (Dio_ChannelType) 0xE3
#define DIO_CHANNEL_E4      (Dio_ChannelType) 0xE4
#define DIO_CHANNEL_E5      (Dio_ChannelType) 0xE5

#define DIO_CHANNEL_F0      (Dio_ChannelType) 0xF0
#define DIO_CHANNEL_F1      (Dio_ChannelType) 0xF1
#define DIO_CHANNEL_F2      (Dio_ChannelType) 0xF2
#define DIO_CHANNEL_F3      (Dio_ChannelType) 0xF3
#define DIO_CHANNEL_F4      (Dio_ChannelType) 0xF4

#define DIO_LEVEL_LOW       (Dio_LevelType) 0x00
#define DIO_LEVEL_HIGH      (Dio_LevelType) 0x01
#define DIO_LEVEL_UNKWN     (Dio_LevelType) 0xFF

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Dio_PortType;

typedef uint8 Dio_ChannelType;

typedef uint8 Dio_LevelType;

typedef uint8 Dio_PortLevelType;
 
#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
