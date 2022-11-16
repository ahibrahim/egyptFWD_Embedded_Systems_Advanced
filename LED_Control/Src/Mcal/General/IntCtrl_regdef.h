/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_regdef.h
 *       Module:  IntCtrl_regdef
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_REGDEF_H
#define INTCTRL_REGDEF_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct
{
    uint32 VECTRESET  :1;
    uint32 VECTCLRACT :1;
    uint32 SYSRESREQ  :1;
    uint32 RESERVED   :5;
    uint32 PRIGROUP   :3;
    uint32 RESERVED1  :4;
    uint32 ENDIANESS  :1;
    uint32 VECTKEY    :16;
}APINT_BF;

typedef union
{
    uint32 R;
    APINT_BF B;
}APINT_Tag;

typedef struct
{
		uint32 RESERVED1 :5;
		uint32 MEM       :3;
		uint32 RESERVED2 :5;
    uint32 BUS       :3;
		uint32 RESERVED3 :5;
    uint32 USAGE     :3;
		uint32 RESERVED4 :8;
}SYSPRI1_BF;

typedef union
{ 
    uint32 R;
    SYSPRI1_BF B;
}SYSPRI1_Tag;

typedef struct
{
		uint32 RESERVED :29;
		uint32 SVC       :3;
}SYSPRI2_BF;

typedef union
{ 
    uint32 R;
    SYSPRI2_BF B;
}SYSPRI2_Tag;

typedef struct
{
		uint32 RESERVED1 :5;
		uint32 DEBUG     :3;
		uint32 RESERVED2 :13;
    uint32 PENDSV       :3;
		uint32 RESERVED3 :5;
    uint32 TICK     :3;
}SYSPRI3_BF;

typedef union
{ 
    uint32 R;
    SYSPRI3_BF B;
}SYSPRI3_Tag;

typedef struct
{
		uint32 RESERVED1 :5;
		uint32 INTA      :3;
		uint32 RESERVED2 :5;
		uint32 INTB      :3;
		uint32 RESERVED3 :5;
		uint32 INTC      :3;
		uint32 RESERVED4 :5;
		uint32 INTD      :3;

}PRI_BF;

typedef union
{ 
    uint32 R;
    PRI_BF B;
}PRI_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* INTCTRL_REGDEF_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_regdef.h
 *********************************************************************************************************************/
