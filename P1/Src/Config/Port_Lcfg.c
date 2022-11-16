/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  Port module user configurations
 *
 *      \details  Link time configurations
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Port_Cfg.h"
#include "Port_Types.h"

 extern void Switch_1_Pressed();
 extern void Switch_2_Pressed();
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/    

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Port_ConfigType Port_Cfgs[NUMBER_OF_CONFIGURED_PINS] =
{
    {
        (Port_PinType) PORT_F_PIN_0,                                 /* Pin number */
        PORT_PIN_IN,                                                 /* Pin direction */
        PORT_PIN_MODE_GPIO,                                          /* Pin mode */
        PORT_PIN_PUR,                                                /* Pin pad type*/
        PORT_PIN_DRV2,                                               /* Drive Select*/
				/* Interrupt Configurations */
				{INTERRUPT_ENABLE, 
				 PIN_EDGE_DETECTION,
				 0,
				 INTERRUPT_RISING_EDGE,
				 Switch_2_Pressed}                                                
    },
    {
        (Port_PinType) PORT_F_PIN_1,                                  /* Pin number */
        PORT_PIN_OUT,                                                 /* Pin direction */
        PORT_PIN_MODE_GPIO,                                           /* Pin mode */
        PORT_PIN_PUR,                                                 /* Pin pad type*/
        PORT_PIN_DRV4,                                                /* Drive Select*/
			  /* Interrupt Configurations */
			  {INTERRUPT_DISABLE, 
				 PIN_SENSE_NONE,
				 0,
				 INTERRUPT_NONE,
				 NULL_PTR}
    },
    {
        (Port_PinType) PORT_F_PIN_2,                                 /* Pin number */
        PORT_PIN_OUT,                                                /* Pin direction */
        PORT_PIN_MODE_GPIO,                                          /* Pin mode */
        PORT_PIN_PUR,                                                /* Pin pad type*/
        PORT_PIN_DRV4,                                               /* Drive Select*/
			  /* Interrupt Configurations */
			  {INTERRUPT_DISABLE, 
				 PIN_SENSE_NONE,
				 0,
				 INTERRUPT_NONE,
				 NULL_PTR}
    },
    {
        (Port_PinType) PORT_F_PIN_3,                                 /* Pin number */
        PORT_PIN_OUT,                                                /* Pin direction */
        PORT_PIN_MODE_GPIO,                                         /* Pin mode */
        PORT_PIN_PUR,                                                /* Pin pad type*/
        PORT_PIN_DRV4,                                               /* Drive Select*/
			  /* Interrupt Configurations */
			  {INTERRUPT_DISABLE, 
				 PIN_SENSE_NONE,
				 0,
				 INTERRUPT_NONE,
				 NULL_PTR}
    },
    {
        (Port_PinType) PORT_F_PIN_4,                                  /* Pin number */
        PORT_PIN_IN,                                                  /* Pin direction */
        PORT_PIN_MODE_GPIO,                                           /* Pin mode */
        PORT_PIN_PUR,                                                 /* Pin pad type*/
        PORT_PIN_DRV2,                                                /* Drive Select*/
				/* Interrupt Configurations */
				{INTERRUPT_ENABLE, 
				 PIN_EDGE_DETECTION,
				 0,
				 INTERRUPT_RISING_EDGE,
				 Switch_1_Pressed}  
    }
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
