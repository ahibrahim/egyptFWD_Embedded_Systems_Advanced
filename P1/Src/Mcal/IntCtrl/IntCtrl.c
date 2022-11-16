/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "IntCtrl_reg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define VECTKEY      0xFA05U
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
* \Syntax          : IntCrtl_Init()                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into NVIC\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Cfg: User configurations                       
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(const IntCtrl_CfgType* Cfg)
{

    /* Configure Grouping\SubGrouping System in APINT register in SCB*/
		/* Register Key */
		APINT.R = (VECTKEY << 16) |(Cfg->BinPt << 8);


		for (uint8 PrIdx = 0; PrIdx <INTCTRL_MAX_CONFIGURATIONS; PrIdx++)
		{
			/* Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers */
			/* Calculate the PRIx Index and Bit Index*/
			uint8 priRegIdx = (uint8)(Cfg->IntPriority[PrIdx].Interrupt / 4);
			uint8 priBitIdx = (uint8)(Cfg->IntPriority[PrIdx].Interrupt % 4);
			
			switch(priBitIdx)
			{
				case 0:
					(*(PRI_REG_START_ADDRESS + (priRegIdx * 0x4))).B.INTA = Cfg->IntPriority[PrIdx].InterruptGroupPriority|Cfg->IntPriority[PrIdx].InterruptGroupPriority;
					break;
				case 1:
					(*(PRI_REG_START_ADDRESS + (priRegIdx * 0x4))).B.INTB = Cfg->IntPriority[PrIdx].InterruptGroupPriority|Cfg->IntPriority[PrIdx].InterruptGroupPriority;
					break;
				case 2:
					(*(PRI_REG_START_ADDRESS + (priRegIdx * 0x4))).B.INTC = Cfg->IntPriority[PrIdx].InterruptGroupPriority|Cfg->IntPriority[PrIdx].InterruptGroupPriority;
					break;
				case 3:
					(*(PRI_REG_START_ADDRESS + (priRegIdx * 0x4))).B.INTD = Cfg->IntPriority[PrIdx].InterruptGroupPriority|Cfg->IntPriority[PrIdx].InterruptGroupPriority;
					break;
				default: ;
			}
			
			/* Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
			/* Calculate the ENx Index and Bit Index*/
			uint8 enRegIdx = (uint8)(Cfg->IntPriority[PrIdx].Interrupt / 32);
			uint8 enBitIdx = (uint8)(Cfg->IntPriority[PrIdx].Interrupt % 32);
			
			*(EN_REG_START_ADDRESS + (enRegIdx * 0x4)) = 1 << enBitIdx;
		}

		/* SysTick Exception Priority */
		SYSPRI3.B.TICK = 0x1;
    

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
