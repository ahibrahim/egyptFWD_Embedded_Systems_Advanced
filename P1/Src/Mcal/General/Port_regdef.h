/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_regdef.h
 *       Module:  -
 *
 *  Description:  Contains Port Registers Definitions
 *  
 *********************************************************************************************************************/
#ifndef PORT_REGDEF_H
#define PORT_REGDEF_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

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
    uint32 DATA     :8;
    uint32 RESERVED :24;
}GPIODATA_BF;

typedef union 
{
    uint32 R;
    GPIODATA_BF B;
}GPIODATA;

typedef struct 
{
    uint32 DIR      :8;
    uint32 RESERVED :24;
}GPIODIR_BF;

typedef union 
{
    uint32 R;
    GPIODIR_BF B;
}GPIODIR;

typedef struct 
{
    uint32 IS       :8;
    uint32 RESERVED :24;
}GPIOIS_BF;

typedef union 
{
    uint32 R;
    GPIOIS_BF B;
}GPIOIS;

typedef struct 
{
    uint32 IBE      :8;
    uint32 RESERVED :24;
}GPIOIBE_BF;

typedef union 
{
    uint32 R;
    GPIOIBE_BF B;
}GPIOIBE;

typedef struct 
{
    uint32 IEV      :8;
    uint32 RESERVED :24;
}GPIOIEV_BF;

typedef union 
{
    uint32 R;
    GPIOIEV_BF B;
}GPIOIEV;

typedef struct 
{
    uint32 IME      :8;
    uint32 RESERVED :24;
}GPIOIM_BF;

typedef union 
{
    uint32 R;
    GPIOIM_BF B;
}GPIOIM;

typedef struct 
{
    uint32 RIS      :8;
    uint32 RESERVED :24;
}GPIORIS_BF;

typedef union 
{
    uint32 R;
    GPIORIS_BF B;
}GPIORIS;

typedef struct 
{
    uint32 MIS      :8;
    uint32 RESERVED :24;
}GPIOMIS_BF;

typedef union 
{
    uint32 R;
    GPIOMIS_BF B;
}GPIOMIS;

typedef struct 
{
    uint32 IC       :8;
    uint32 RESERVED :24;
}GPIOICR_BF;

typedef union 
{
    uint32 R;
    GPIOICR_BF B;
}GPIOICR;

typedef struct 
{
    uint32 AFSEL    :8;
    uint32 RESERVED :24;
}GPIOAFSEL_BF;

typedef union 
{
    uint32 R;
    GPIOAFSEL_BF B;
}GPIOAFSEL;

typedef struct 
{
    uint32 DRV2     :8;
    uint32 RESERVED :24;
}GPIODR2R_BF;

typedef union 
{
    uint32 R;
    GPIODR2R_BF B;
}GPIODR2R;

typedef struct 
{
    uint32 DRV4     :8;
    uint32 RESERVED :24;
}GPIODR4R_BF;

typedef union 
{
    uint32 R;
    GPIODR4R_BF B;
}GPIODR4R;

typedef struct 
{
    uint32 DRV8     :8;
    uint32 RESERVED :24;
}GPIODR8R_BF;

typedef union 
{
    uint32 R;
    GPIODR8R_BF B;
}GPIODR8R;

typedef struct 
{
    uint32 ODE      :8;
    uint32 RESERVED :24;
}GPIOODR_BF;

typedef union 
{
    uint32 R;
    GPIOODR_BF B;
}GPIOODR;

typedef struct 
{
    uint32 PUE      :8;
    uint32 RESERVED :24;
}GPIOPUR_BF;

typedef union 
{
    uint32 R;
    GPIOPUR_BF B;
}GPIOPUR;

typedef struct 
{
    uint32 PDE      :8;
    uint32 RESERVED :24;
}GPIOPDR_BF;

typedef union 
{
    uint32 R;
    GPIOPDR_BF B;
}GPIOPDR;

typedef struct 
{
    uint32 SRL      :8;
    uint32 RESERVED :24;
}GPIOSLR_BF;

typedef union 
{
    uint32 R;
    GPIOSLR_BF B;
}GPIOSLR;

typedef struct 
{
    uint32 DEN      :8;
    uint32 RESERVED :24;
}GPIODEN_BF;

typedef union 
{
    uint32 R;
    GPIODEN_BF B;
}GPIODEN;

typedef struct 
{
    uint32 LOCK     :32;
}GPIOLOCK_BF;

typedef union 
{
    uint32 R;
    GPIOLOCK_BF B;
}GPIOLOCK;

typedef struct 
{
    uint32 CR    :8;
    uint32 RESERVED :24;
}GPIOCR_BF;

typedef union 
{
    uint32 R;
    GPIOCR_BF B;
}GPIOCR;

typedef struct 
{
    uint32 GPIOAMSEL:8;
    uint32 RESERVED :24;
}GPIOAMSEL_BF;

typedef union 
{
    uint32 R;
    GPIOAMSEL_BF B;
}GPIOAMSEL;

typedef struct 
{
    uint32 PMC0     :4;
    uint32 PMC1     :4;
    uint32 PMC2     :4;
    uint32 PMC3     :4;
    uint32 PMC4     :4;
    uint32 PMC5     :4;
    uint32 PMC6     :4;
    uint32 PMC7     :4;
}GPIOPCTL_BF;

typedef union 
{
    uint32 R;
    GPIOPCTL_BF B;
}GPIOPCTL;

typedef struct 
{
    uint32 ADCEN    :8;
    uint32 RESERVED :24;
}GPIOADCCTL_BF;

typedef union 
{
    uint32 R;
    GPIOADCCTL_BF B;
}GPIOADCCTL;

typedef struct 
{
    uint32 DMAEN    :8;
    uint32 RESERVED :24;
}GPIODMACTL_BF;

typedef union 
{
    uint32 R;
    GPIODMACTL_BF B;
}GPIODMACTL;

typedef struct 
{
    uint32 PID4     :8;
    uint32 RESERVED :24;
}GPIOPeriphID4_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID4_BF B;
}GPIOPeriphID4;

typedef struct 
{
    uint32 PID5     :8;
    uint32 RESERVED :24;
}GPIOPeriphID5_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID5_BF B;
}GPIOPeriphID5;

typedef struct 
{
    uint32 PID6     :8;
    uint32 RESERVED :24;
}GPIOPeriphID6_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID6_BF B;
}GPIOPeriphID6;

typedef struct 
{
    uint32 PID7     :8;
    uint32 RESERVED :24;
}GPIOPeriphID7_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID7_BF B;
}GPIOPeriphID7;

typedef struct 
{
    uint32 PID0     :8;
    uint32 RESERVED :24;
}GPIOPeriphID0_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID0_BF B;
}GPIOPeriphID0;

typedef struct 
{
    uint32 PID1     :8;
    uint32 RESERVED :24;
}GPIOPeriphID1_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID1_BF B;
}GPIOPeriphID1;

typedef struct 
{
    uint32 PID2     :8;
    uint32 RESERVED :24;
}GPIOPeriphID2_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID2_BF B;
}GPIOPeriphID2;

typedef struct 
{
    uint32 PID3     :8;
    uint32 RESERVED :24;
}GPIOPeriphID3_BF;

typedef union 
{
    uint32 R;
    GPIOPeriphID3_BF B;
}GPIOPeriphID3;

typedef struct 
{
    uint32 CID0     :8;
    uint32 RESERVED :24;
}GPIOPCellID0_BF;

typedef union 
{
    uint32 R;
    GPIOPCellID0_BF B;
}GPIOPCellID0;

typedef struct 
{
    uint32 CID1     :8;
    uint32 RESERVED :24;
}GPIOPCellID1_BF;

typedef union 
{
    uint32 R;
    GPIOPCellID1_BF B;
}GPIOPCellID1;

typedef struct 
{
    uint32 CID2     :8;
    uint32 RESERVED :24;
}GPIOPCellID2_BF;

typedef union 
{
    uint32 R;
    GPIOPCellID2_BF B;
}GPIOPCellID2;

typedef struct 
{
    uint32 CID3     :8;
    uint32 RESERVED :24;
}GPIOPCellID3_BF;

typedef union 
{
    uint32 R;
    GPIOPCellID3_BF B;
}GPIOPCellID3;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_REGDEF_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_regdef.h
 *********************************************************************************************************************/
