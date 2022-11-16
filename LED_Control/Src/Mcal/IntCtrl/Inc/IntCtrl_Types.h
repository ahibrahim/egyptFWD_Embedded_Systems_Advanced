/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define XXX           0x4
#define XXY           0x5
#define XYY           0x6
#define YYY           0x7


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 IntCtrlBinPtType;

typedef enum
{
    INT_GPIO_PORT_A = 0,
    INT_GPIO_PORT_B,
    INT_GPIO_PORT_C,
    INT_GPIO_PORT_D,
    INT_GPIO_PORT_E,
    INT_UART0,
    INT_UART1,
    INT_SSI0,
    INT_I2C0,
    INT_PWM0_FAULT,
    INT_PWM0_GENERATOR_0,
    INT_PWM0_GENERATOR_1,
    INT_PWM0_GENERATOR_2,
    INT_QEI0,
    INT_ADC0_SEQUENCE_0,
    INT_ADC0_SEQUENCE_1,
    INT_ADC0_SEQUENCE_2,
    INT_ADC0_SEQUENCE_3,
    INT_WATCHDOG_TIMERs_0_1,
    INT_16_32_BIT_TIMER_0A,
    INT_16_32_BIT_TIMER_0B,
    INT_16_32_BIT_TIMER_1A,
    INT_16_32_BIT_TIMER_1B,
    INT_16_32_BIT_TIMER_2A,
    INT_16_32_BIT_TIMER_2B,
    INT_ANALOG_COMPARATOR_0,
    INT_ANALOG_COMPARATOR_1,
    RESERVED_27,
    INT_SYSTEM_CONTROL,
    INT_FLASH_EEPROM_MEMORY_CONTROL,
    INT_GPIO_PORT_F,
    RESERVED_31,
    RESERVED_32,
    INT_UART2,
    INT_SSI1,
    INT_16_32_BIT_TIMER_3A,
    INT_16_32_BIT_TIMER_3B,
    INT_I2C1,
    INT_QEI1,
    INT_CAN0,
    INT_CAN1,
    RESERVED_41,
    RESERVED_42,
    INT_HIBERNATION_MODULE,
    INT_USB,
    INT_PWM_GENERATOR_3,
    INT_UDMA_SOFTWARE,
    INT_UDMA_ERROR,
    INT_ADC1_SEQUENCE_0,
    INT_ADC1_SEQUENCE_1,
    INT_ADC1_SEQUENCE_2,
    INT_ADC1_SEQUENCE_3,
    RESERVED_52,
    RESERVED_53,
    RESERVED_54,
    RESERVED_55,
    RESERVED_56,
    INT_SSI2,
    INT_SSI3,
    INT_UART3,
    INT_UART4,
    INT_UART5,
    INT_UART6,
    INT_UART7,
    RESERVED_64,
    RESERVED_65,
    RESERVED_66,
    RESERVED_67,
    INT_I2C2,
    INT_I2C3,
    INT_16_32_BIT_TIMER_4A,
    INT_16_32_BIT_TIMER_4B,
    RESERVED_72,
    RESERVED_73,
    RESERVED_74,
    RESERVED_75,
    RESERVED_76,
    RESERVED_77,
    RESERVED_78,
    RESERVED_79,
    RESERVED_80,
    RESERVED_81,
    RESERVED_82,
    RESERVED_83,
    RESERVED_84,
    RESERVED_85,
    RESERVED_86,
    RESERVED_87,
    RESERVED_88,
    RESERVED_89,
    RESERVED_90,
    RESERVED_91,
    INT_16_32_BIT_TIMER_5A,
    INT_16_32_BIT_TIMER_5B,
    INT_32_64_BIT_TIMER_0A,
    INT_32_64_BIT_TIMER_0B,
    INT_32_64_BIT_TIMER_1A,
    INT_32_64_BIT_TIMER_1B,
    INT_32_64_BIT_TIMER_2A,
    INT_32_64_BIT_TIMER_2B,
    INT_32_64_BIT_TIMER_3A,
    INT_32_64_BIT_TIMER_3B,
    INT_32_64_BIT_TIMER_4A,
    INT_32_64_BIT_TIMER_4B,
    INT_32_64_BIT_TIMER_5A,
    INT_32_64_BIT_TIMER_5B,
    INT_SYSTEM_EXCEPTION,
    RESERVED_107,
    RESERVED_108,
    RESERVED_109,
    RESERVED_110,
    RESERVED_111,
    RESERVED_112,
    RESERVED_113,
    RESERVED_114,
    RESERVED_115,
    RESERVED_116,
    RESERVED_117,
    RESERVED_118,
    RESERVED_119,
    RESERVED_120,
    RESERVED_121,
    RESERVED_122,
    RESERVED_123,
    RESERVED_124,
    RESERVED_125,
    RESERVED_126,
    RESERVED_127,
    RESERVED_128,
    RESERVED_129,
    RESERVED_130,
    RESERVED_131,
    RESERVED_132,
    RESERVED_133,
    INT_PWM1_GENERATOR_0,
    INT_PWM1_GENERATOR_1,
    INT_PWM1_GENERATOR_2,
    INT_PWM1_GENERATOR_3,
    INT_PWM1_FAULT
}IntCtrl_InterruptType;

typedef struct
{
		IntCtrl_InterruptType Interrupt;
    uint8 InterruptGroupPriority;
    uint8 InterruptGroupSubPriority;
}IntCtrl_IntPriorityType;

typedef struct
{
		IntCtrlBinPtType BinPt;  /* Binary Point */
		IntCtrl_IntPriorityType IntPriority[];
} IntCtrl_CfgType;




 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
