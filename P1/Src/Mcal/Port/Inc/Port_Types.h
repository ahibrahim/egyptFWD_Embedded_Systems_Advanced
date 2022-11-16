/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  Port Data types
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_A_PIN_0         (Port_PinType) 0xA0
#define PORT_A_PIN_1         (Port_PinType) 0xA1
#define PORT_A_PIN_2         (Port_PinType) 0xA2
#define PORT_A_PIN_3         (Port_PinType) 0xA3
#define PORT_A_PIN_4         (Port_PinType) 0xA4
#define PORT_A_PIN_5         (Port_PinType) 0xA5
#define PORT_A_PIN_6         (Port_PinType) 0xA6
#define PORT_A_PIN_7         (Port_PinType) 0xA7

#define PORT_B_PIN_0         (Port_PinType) 0xB0
#define PORT_B_PIN_1         (Port_PinType) 0xB1
#define PORT_B_PIN_2         (Port_PinType) 0xB2
#define PORT_B_PIN_3         (Port_PinType) 0xB3
#define PORT_B_PIN_4         (Port_PinType) 0xB4
#define PORT_B_PIN_5         (Port_PinType) 0xB5
#define PORT_B_PIN_6         (Port_PinType) 0xB6
#define PORT_B_PIN_7         (Port_PinType) 0xB7

#define PORT_C_PIN_0         (Port_PinType) 0xC0
#define PORT_C_PIN_1         (Port_PinType) 0xC1
#define PORT_C_PIN_2         (Port_PinType) 0xC2
#define PORT_C_PIN_3         (Port_PinType) 0xC3
#define PORT_C_PIN_4         (Port_PinType) 0xC4
#define PORT_C_PIN_5         (Port_PinType) 0xC5
#define PORT_C_PIN_6         (Port_PinType) 0xC6
#define PORT_C_PIN_7         (Port_PinType) 0xC7

#define PORT_D_PIN_0         (Port_PinType) 0xD0
#define PORT_D_PIN_1         (Port_PinType) 0xD1
#define PORT_D_PIN_2         (Port_PinType) 0xD2
#define PORT_D_PIN_3         (Port_PinType) 0xD3
#define PORT_D_PIN_4         (Port_PinType) 0xD4
#define PORT_D_PIN_5         (Port_PinType) 0xD5
#define PORT_D_PIN_6         (Port_PinType) 0xD6
#define PORT_D_PIN_7         (Port_PinType) 0xD7

#define PORT_E_PIN_0         (Port_PinType) 0xE0
#define PORT_E_PIN_1         (Port_PinType) 0xE1
#define PORT_E_PIN_2         (Port_PinType) 0xE2
#define PORT_E_PIN_3         (Port_PinType) 0xE3
#define PORT_E_PIN_4         (Port_PinType) 0xE4
#define PORT_E_PIN_5         (Port_PinType) 0xE5

#define PORT_F_PIN_0         (Port_PinType) 0xF0
#define PORT_F_PIN_1         (Port_PinType) 0xF1
#define PORT_F_PIN_2         (Port_PinType) 0xF2
#define PORT_F_PIN_3         (Port_PinType) 0xF3
#define PORT_F_PIN_4         (Port_PinType) 0xF4

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Port_PinType;

typedef void (*Cbkfn)(void);

typedef enum
{
    PORT_PIN_IN,
    PORT_PIN_OUT
} Port_PinDirectionType;

typedef enum
{
    PORT_PIN_MODE_GPIO = 0x00,
    PORT_PIN_MODE_ALT1,
    PORT_PIN_MODE_ALT2,
    PORT_PIN_MODE_ALT4,
    PORT_PIN_MODE_ALT5,
    PORT_PIN_MODE_ALT6,
    PORT_PIN_MODE_ALT7,
    PORT_PIN_MODE_ALT8,
    PORT_PIN_MODE_ALT9,
    PORT_PIN_MODE_ALT10,
    PORT_PIN_MODE_ALT11,
    PORT_PIN_MODE_ALT12,
    PORT_PIN_MODE_ALT13,
    PORT_PIN_MODE_ALT14,
    PORT_PIN_MODE_ALT15
}Port_PinModeType;

typedef enum
{
    PORT_PIN_PUR,
    PORT_PIN_PDR,
    PORT_PIN_OD
}Port_PinInternalAttachType;

typedef enum
{
    PORT_PIN_DRV2,
    PORT_PIN_DRV4,
    PORT_PIN_DRV8
}Port_PinOutputCurrentType;

typedef enum
{
	INTERRUPT_ENABLE,
	INTERRUPT_DISABLE
}InterruptEnableType;

typedef enum
{
	PIN_SENSE_NONE,
	PIN_EDGE_DETECTION,
	PIN_LEVEL_DETECTION
}InterruptSenseType;

typedef uint8 InterruptBothEdges;

typedef enum 
{
	INTERRUPT_NONE,
	INTERRUPT_RISING_EDGE,
	INTERRUPT_FALLING_EDGE,
	INTERRUPT_HIGH_LEVEL,
	INTERRUPT_LOW_LEVEL
}InterruptEventType;

typedef struct
{
	InterruptEnableType  IntEn;
	InterruptSenseType   IntSense;
	InterruptBothEdges   IntBE;
	InterruptEventType   IntEv;
	Cbkfn                Callback;
}Port_PinInterruptConfigType;

typedef struct
{
    Port_PinType Port_Pin_Number;                            /* Pin number */
    Port_PinDirectionType Pin_Dir;                           /* Pin direction */
    Port_PinModeType  Pin_Mode;                              /* Pin mode */
    Port_PinInternalAttachType Pin_PadType;                  /* Pin pad type*/
    Port_PinOutputCurrentType Pin_PadDrvCurrent;             /* Drive Select*/
		Port_PinInterruptConfigType Pin_IntCfg;									 /* Interrupt Configurations */
}Port_ConfigType;


 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
