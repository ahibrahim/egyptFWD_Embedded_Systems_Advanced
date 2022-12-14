/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtrl_regdef.h
 *       Module:  -
 *
 *  Description:  Contains System control Registers Definitions
 *  
 *********************************************************************************************************************/
#ifndef SYSCTRL_REGDEF_H
#define SYSCTRL_REGDEF_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 R0       :1;
    uint32 R1       :1;
    uint32 R2       :1;
    uint32 R3       :1;
    uint32 R4       :1;
    uint32 R5       :1;
    uint32 RESERVED :26;
}RCGCGPIO_BF;

typedef union 
{
    uint32 R;
    RCGCGPIO_BF B;
}RCGCGPIO;

typedef struct
{
    uint32 EN   :1;
    uint32 INTEN    :1;
    uint32 CLK_SRC  :1;
    uint32 RESERVED1:13;
    uint32 COUNT    :1;
    uint32 RESERVED2:15;
}STCTRL_BF;

typedef union 
{
    uint32 R;
    STCTRL_BF B;
}STCTRL;


typedef struct
{
    uint32 RELOAD   :24;
    uint32 RESERVED :8;
}STRELOAD_BF;

typedef union 
{
    uint32 R;
    STRELOAD_BF B;
}STRELOAD;


typedef struct
{
    uint32 CURRENT  :24;
    uint32 RESERVED :8;
}STCURRENT_BF;


typedef union 
{
    uint32 R;
    STCURRENT_BF B;
}STCURRENT;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* SYSCTRL_REGDEF_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_regdef.h
 *********************************************************************************************************************/
