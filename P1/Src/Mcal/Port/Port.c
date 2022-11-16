/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Port module Driver
 *
 *      \details  The Driver Configure All Ports/Pins 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/    
#define PORT_A               (Dio_PortType) 0x0A
#define PORT_B               (Dio_PortType) 0x0B
#define PORT_C               (Dio_PortType) 0x0C
#define PORT_D               (Dio_PortType) 0x0D
#define PORT_E               (Dio_PortType) 0x0E
#define PORT_F               (Dio_PortType) 0x0F
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (*GPIO_F0_Cbf)(void);
void (*GPIO_F4_Cbf)(void);
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
* \Syntax          : Port_Init()                                      
* \Description     : Initializes the Port Driver module 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr -> Pointer to configuration set                 
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(
const Port_ConfigType* ConfigPtr
)
{

    const Port_ConfigType* Port_ConfigPtr;
    uint8 PortNumber;
    uint8 PinNumber;
    
    Port_ConfigPtr = ConfigPtr;
    
    for (uint8 cfgIdx = 0; cfgIdx < NUMBER_OF_CONFIGURED_PINS; cfgIdx++,Port_ConfigPtr++)
    {
        PortNumber = (Port_ConfigPtr->Port_Pin_Number & 0xF0) >> 4;
        PinNumber = Port_ConfigPtr->Port_Pin_Number & 0x0F;
        
        switch (PortNumber)
        {
            case 0xA:
                /* Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register */
                RCGCGPIO_REG.B.R0 = 0x1;
                
                /* Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1 indicates output and a write of a 0 indicates input. */
                if (Port_ConfigPtr->Pin_Dir == PORT_PIN_OUT)
                {

                    PORT_A_GPIODIR_APB.B.DIR |= 1 << PinNumber;
                }
                else
                {
                    PORT_A_GPIODIR_APB.B.DIR &= ~(1 << PinNumber);
                } 
                /* for PA[1:0] , PA[5:2]  -> unlock the GPIOLOCK and uncommit the GPIOCR */
                if (PinNumber == 0x0 || PinNumber == 0x1 || PinNumber == 0x2 || PinNumber == 0x3 || PinNumber == 0x4 || PinNumber == 0x5)
                {
                    PORT_A_GPIOLOCK_APB.R = 0x4C4F434B;
                    PORT_A_GPIOCR_APB.B.CR |= 1 << PinNumber;
                }
                /* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.
                    If an alternate pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for the specific peripheral required.  */
                /*  To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. 
                   a. To enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the GPIOAMSEL register. */
                if (Port_ConfigPtr->Pin_Mode != PORT_PIN_MODE_GPIO) 
                {
                    PORT_A_GPIOAFSEL_APB.B.AFSEL |= 1 << PinNumber;
                    PORT_A_GPIOAMSEL_APB.B.GPIOAMSEL |= 1 << PinNumber;
                }
                else
                {
                    PORT_A_GPIOAFSEL_APB.B.AFSEL &= ~(1 << PinNumber);
                    PORT_A_GPIODEN_APB.B.DEN |= 1 << PinNumber;
                }

                PORT_A_GPIOPCTL_APB.R = (uint32) (Port_ConfigPtr->Pin_Mode << ((PinNumber-1) * GPIOPCTL_PMC_LENGTH));
                /*  Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers. */
                if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV8)
                {
                    PORT_A_GPIODR8R_APB.B.DRV8 |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV4)
                {
                    PORT_A_GPIODR4R_APB.B.DRV4 |= 1 << PinNumber;
                }
                else
                {
                    PORT_A_GPIODR2R_APB.B.DRV2 |= 1 << PinNumber;
                }
                /*  Program each pad in the port to have either pull-up, pull-down, or open drain functionality through the GPIOPUR, GPIOPDR, GPIOODR register. */
                if(Port_ConfigPtr->Pin_PadType == PORT_PIN_PUR)
                {
                    PORT_A_GPIOPUR_APB.B.PUE |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_PDR)
                {
                    PORT_A_GPIOPDR_APB.B.PDE |= 1 << PinNumber;
                }
                else
                {
                    PORT_A_GPIOODR_APB.B.ODE |= 1 << PinNumber;
                }

                
                if (Port_ConfigPtr->Pin_IntCfg.IntEn == INTERRUPT_ENABLE)
								{
									/*  Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event, and mask of the interrupts for each port.
                    Note: To prevent false interrupts, the following steps should be taken when re-configuring GPIO edge and interrupt sense registers:
                    a. Mask the corresponding port by clearing the IME field in the GPIOIM register.*/
										PORT_A_GPIOIM_APB.B.IME &=  ~(1 << PinNumber);
                    /* b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.*/
										if(Port_ConfigPtr->Pin_IntCfg.IntSense == PIN_EDGE_DETECTION)
										{
												PORT_A_GPIOIS_APB.B.IS &=  ~(1 << PinNumber);
										}
										else
										{
												PORT_A_GPIOIS_APB.B.IS |=  1 << PinNumber;
										}
										
										if((Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_RISING_EDGE) ||(Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_HIGH_LEVEL))
										{
												PORT_A_GPIOIEV_APB.B.IEV |=  1 << PinNumber;
										}
										else
										{
												PORT_A_GPIOIEV_APB.B.IEV &=  ~(1 << PinNumber);
										}
										
										if(Port_ConfigPtr->Pin_IntCfg.IntBE == 0x1)
										{
												PORT_A_GPIOIBE_APB.B.IBE |=  1 << PinNumber;
										}
										else
										{
												PORT_A_GPIOIBE_APB.B.IBE &=  ~(1 << PinNumber);
										}
										
                    /* c. Clear the GPIORIS register. */
										PORT_A_GPIORIS_APB.B.RIS &=  ~(1 << PinNumber);
                    /* d. Unmask the port by setting the IME field in the GPIOIM register. */
										PORT_A_GPIOIM_APB.B.IME |=  1 << PinNumber;
								}
                /* 8. Optionally, software can lock the configurations of the NMI and JTAG/SWD pins on the GPIO port pins, by setting the LOCK bits in the GPIOLOCK register. */
						break;
            case 0xB:
                /* Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register */
                RCGCGPIO_REG.B.R1 = 0x1;
                /* Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1 indicates output and a write of a 0 indicates input. */
                if (Port_ConfigPtr->Pin_Dir == PORT_PIN_OUT)
                {
                    PORT_B_GPIODIR_APB.B.DIR |= 1 << PinNumber;
                }
                else
                {
                    PORT_B_GPIODIR_APB.B.DIR &= ~(1 << PinNumber);
                } 
                /* for PB[3:2]  -> unlock the GPIOLOCK and uncommit the GPIOCR */
                if ( PinNumber == 0x2 || PinNumber == 0x3)
                {
                    PORT_B_GPIOLOCK_APB.R = 0x4C4F434B;
                    PORT_B_GPIOCR_APB.B.CR |= 1 << PinNumber;
                }
                /* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.
                    If an alternate pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for the specific peripheral required.  */
                /*  To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. 
                   a. To enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the GPIOAMSEL register. */
                if (Port_ConfigPtr->Pin_Mode != PORT_PIN_MODE_GPIO) 
                {
                    PORT_B_GPIOAFSEL_APB.B.AFSEL |= 1 << PinNumber;
                    PORT_B_GPIOAMSEL_APB.B.GPIOAMSEL |= 1 << PinNumber;
                }
                else
                {
                    PORT_B_GPIOAFSEL_APB.B.AFSEL &= ~(1 << PinNumber);
                    PORT_B_GPIODEN_APB.B.DEN |= 1 << PinNumber;
                }

                PORT_B_GPIOPCTL_APB.R = (uint32) (Port_ConfigPtr->Pin_Mode << ((PinNumber-1) * GPIOPCTL_PMC_LENGTH));
                /*  Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers. */
                if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV8)
                {
                    PORT_B_GPIODR8R_APB.B.DRV8 |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV4)
                {
                    PORT_B_GPIODR4R_APB.B.DRV4 |= 1 << PinNumber;
                }
                else
                {
                    PORT_B_GPIODR2R_APB.B.DRV2 |= 1 << PinNumber;
                }
                /*  Program each pad in the port to have either pull-up, pull-down, or open drain functionality through the GPIOPUR, GPIOPDR, GPIOODR register. */
                if(Port_ConfigPtr->Pin_PadType == PORT_PIN_PUR)
                {
                    PORT_B_GPIOPUR_APB.B.PUE |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_PDR)
                {
                    PORT_B_GPIOPDR_APB.B.PDE |= 1 << PinNumber;
                }
                else
                {
                    PORT_B_GPIOODR_APB.B.ODE |= 1 << PinNumber;
                }

                
                if (Port_ConfigPtr->Pin_IntCfg.IntEn == INTERRUPT_ENABLE)
								{
									/*  Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event, and mask of the interrupts for each port.
                    Note: To prevent false interrupts, the following steps should be taken when re-configuring GPIO edge and interrupt sense registers:
                    a. Mask the corresponding port by clearing the IME field in the GPIOIM register.*/
										PORT_B_GPIOIM_APB.B.IME &=  ~(1 << PinNumber);
                    /* b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.*/
										if(Port_ConfigPtr->Pin_IntCfg.IntSense == PIN_EDGE_DETECTION)
										{
												PORT_B_GPIOIS_APB.B.IS &=  ~(1 << PinNumber);
										}
										else
										{
												PORT_B_GPIOIS_APB.B.IS |=  1 << PinNumber;
										}
										
										if((Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_RISING_EDGE) ||(Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_HIGH_LEVEL))
										{
												PORT_B_GPIOIEV_APB.B.IEV |=  1 << PinNumber;
										}
										else
										{
												PORT_B_GPIOIEV_APB.B.IEV &=  ~(1 << PinNumber);
										}
										
										if(Port_ConfigPtr->Pin_IntCfg.IntBE == 0x1)
										{
												PORT_B_GPIOIBE_APB.B.IBE |=  1 << PinNumber;
										}
										else
										{
												PORT_B_GPIOIBE_APB.B.IBE &=  ~(1 << PinNumber);
										}
										
                    /* c. Clear the GPIORIS register. */
										PORT_B_GPIORIS_APB.B.RIS &=  ~(1 << PinNumber);
                    /* d. Unmask the port by setting the IME field in the GPIOIM register. */
										PORT_B_GPIOIM_APB.B.IME |=  1 << PinNumber;
								}
                /* 8. Optionally, software can lock the configurations of the NMI and JTAG/SWD pins on the GPIO port pins, by setting the LOCK bits in the GPIOLOCK register. */
						break;
            case 0xC:
                /* Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register */
                RCGCGPIO_REG.B.R2 = 0x1;
                /* Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1 indicates output and a write of a 0 indicates input. */
                if (Port_ConfigPtr->Pin_Dir == PORT_PIN_OUT)
                {
                    PORT_C_GPIODIR_APB.B.DIR |= 1 << PinNumber;
                }
                else
                {
                    PORT_C_GPIODIR_APB.B.DIR &= ~(1 << PinNumber);
                } 
                /* for PC[3:0]  -> unlock the GPIOLOCK and uncommit the GPIOCR */
                if (PinNumber == 0x0 || PinNumber == 0x1 || PinNumber == 0x2 || PinNumber == 0x3)
                {
                    PORT_C_GPIOLOCK_APB.R = 0x4C4F434B;
                    PORT_C_GPIOCR_APB.B.CR |= 1 << PinNumber;
                }
                /* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.
                    If an alternate pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for the specific peripheral required.  */
                /*  To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. 
                   a. To enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the GPIOAMSEL register. */
                if (Port_ConfigPtr->Pin_Mode != PORT_PIN_MODE_GPIO) 
                {
                    PORT_C_GPIOAFSEL_APB.B.AFSEL |= 1 << PinNumber;
                    PORT_C_GPIOAMSEL_APB.B.GPIOAMSEL |= 1 << PinNumber;
                }
                else
                {
                    PORT_C_GPIOAFSEL_APB.B.AFSEL &= ~(1 << PinNumber);
                    PORT_C_GPIODEN_APB.B.DEN |= 1 << PinNumber;
                }

                PORT_C_GPIOPCTL_APB.R = (uint32) (Port_ConfigPtr->Pin_Mode << ((PinNumber-1) * GPIOPCTL_PMC_LENGTH));
                /*  Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers. */
                if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV8)
                {
                    PORT_C_GPIODR8R_APB.B.DRV8 |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV4)
                {
                    PORT_C_GPIODR4R_APB.B.DRV4 |= 1 << PinNumber;
                }
                else
                {
                    PORT_C_GPIODR2R_APB.B.DRV2 |= 1 << PinNumber;
                }
                /*  Program each pad in the port to have either pull-up, pull-down, or open drain functionality through the GPIOPUR, GPIOPDR, GPIOODR register. */
                if(Port_ConfigPtr->Pin_PadType == PORT_PIN_PUR)
                {
                    PORT_C_GPIOPUR_APB.B.PUE |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_PDR)
                {
                    PORT_C_GPIOPDR_APB.B.PDE |= 1 << PinNumber;
                }
                else
                {
                    PORT_C_GPIOODR_APB.B.ODE |= 1 << PinNumber;
                }

                
                if (Port_ConfigPtr->Pin_IntCfg.IntEn == INTERRUPT_ENABLE)
								{
									/*  Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event, and mask of the interrupts for each port.
                    Note: To prevent false interrupts, the following steps should be taken when re-configuring GPIO edge and interrupt sense registers:
                    a. Mask the corresponding port by clearing the IME field in the GPIOIM register.*/
										PORT_C_GPIOIM_APB.B.IME &=  ~(1 << PinNumber);
                    /* b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.*/
										if(Port_ConfigPtr->Pin_IntCfg.IntSense == PIN_EDGE_DETECTION)
										{
												PORT_C_GPIOIS_APB.B.IS &=  ~(1 << PinNumber);
										}
										else
										{
												PORT_C_GPIOIS_APB.B.IS |=  1 << PinNumber;
										}
										
										if((Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_RISING_EDGE) ||(Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_HIGH_LEVEL))
										{
												PORT_C_GPIOIEV_APB.B.IEV |=  1 << PinNumber;
										}
										else
										{
												PORT_C_GPIOIEV_APB.B.IEV &=  ~(1 << PinNumber);
										}
										
										if(Port_ConfigPtr->Pin_IntCfg.IntBE == 0x1)
										{
												PORT_C_GPIOIBE_APB.B.IBE |=  1 << PinNumber;
										}
										else
										{
												PORT_C_GPIOIBE_APB.B.IBE &=  ~(1 << PinNumber);
										}
										
                    /* c. Clear the GPIORIS register. */
										PORT_C_GPIORIS_APB.B.RIS &=  ~(1 << PinNumber);
                    /* d. Unmask the port by setting the IME field in the GPIOIM register. */
										PORT_C_GPIOIM_APB.B.IME |=  1 << PinNumber;
								}
                /* 8. Optionally, software can lock the configurations of the NMI and JTAG/SWD pins on the GPIO port pins, by setting the LOCK bits in the GPIOLOCK register. */
						break;
            case 0xD:
                /* Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register */
                RCGCGPIO_REG.B.R3 = 0x1;
                /* Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1 indicates output and a write of a 0 indicates input. */
                if (Port_ConfigPtr->Pin_Dir == PORT_PIN_OUT)
                {
                    PORT_D_GPIODIR_APB.B.DIR |= 1 << PinNumber;
                }
                else
                {
                    PORT_D_GPIODIR_APB.B.DIR &= ~(1 << PinNumber);
                } 
                /* for PD[7]  -> unlock the GPIOLOCK and uncommit the GPIOCR */
                if (PinNumber == 0x7)
                {
                    PORT_D_GPIOLOCK_APB.R = 0x4C4F434B;
                    PORT_D_GPIOCR_APB.B.CR |= 1 << PinNumber;
                }
                 /* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.
                    If an alternate pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for the specific peripheral required.  */
                /*  To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. 
                   a. To enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the GPIOAMSEL register. */
                if (Port_ConfigPtr->Pin_Mode != PORT_PIN_MODE_GPIO) 
                {
                    PORT_D_GPIOAFSEL_APB.B.AFSEL |= 1 << PinNumber;
                    PORT_D_GPIOAMSEL_APB.B.GPIOAMSEL |= 1 << PinNumber;
                }
                else
                {
                    PORT_D_GPIOAFSEL_APB.B.AFSEL &= ~(1 << PinNumber);
                    PORT_D_GPIODEN_APB.B.DEN |= 1 << PinNumber;
                }

                PORT_D_GPIOPCTL_APB.R = (uint32) (Port_ConfigPtr->Pin_Mode << ((PinNumber-1) * GPIOPCTL_PMC_LENGTH));
                /*  Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers. */
                if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV8)
                {
                    PORT_D_GPIODR8R_APB.B.DRV8 |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV4)
                {
                    PORT_D_GPIODR4R_APB.B.DRV4 |= 1 << PinNumber;
                }
                else
                {
                    PORT_D_GPIODR2R_APB.B.DRV2 |= 1 << PinNumber;
                }
                /*  Program each pad in the port to have either pull-up, pull-down, or open drain functionality through the GPIOPUR, GPIOPDR, GPIOODR register. */
                if(Port_ConfigPtr->Pin_PadType == PORT_PIN_PUR)
                {
                    PORT_D_GPIOPUR_APB.B.PUE |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_PDR)
                {
                    PORT_D_GPIOPDR_APB.B.PDE |= 1 << PinNumber;
                }
                else
                {
                    PORT_D_GPIOODR_APB.B.ODE |= 1 << PinNumber;
                }

                
                if (Port_ConfigPtr->Pin_IntCfg.IntEn == INTERRUPT_ENABLE)
								{
									/*  Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event, and mask of the interrupts for each port.
                    Note: To prevent false interrupts, the following steps should be taken when re-configuring GPIO edge and interrupt sense registers:
                    a. Mask the corresponding port by clearing the IME field in the GPIOIM register.*/
										PORT_D_GPIOIM_APB.B.IME &=  ~(1 << PinNumber);
                    /* b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.*/
										if(Port_ConfigPtr->Pin_IntCfg.IntSense == PIN_EDGE_DETECTION)
										{
												PORT_D_GPIOIS_APB.B.IS &=  ~(1 << PinNumber);
										}
										else
										{
												PORT_D_GPIOIS_APB.B.IS |=  1 << PinNumber;
										}
										
										if((Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_RISING_EDGE) ||(Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_HIGH_LEVEL))
										{
												PORT_D_GPIOIEV_APB.B.IEV |=  1 << PinNumber;
										}
										else
										{
												PORT_D_GPIOIEV_APB.B.IEV &=  ~(1 << PinNumber);
										}
										
										if(Port_ConfigPtr->Pin_IntCfg.IntBE == 0x1)
										{
												PORT_D_GPIOIBE_APB.B.IBE |=  1 << PinNumber;
										}
										else
										{
												PORT_D_GPIOIBE_APB.B.IBE &=  ~(1 << PinNumber);
										}
										
                    /* c. Clear the GPIORIS register. */
										PORT_D_GPIORIS_APB.B.RIS &=  ~(1 << PinNumber);
                    /* d. Unmask the port by setting the IME field in the GPIOIM register. */
										PORT_D_GPIOIM_APB.B.IME |=  1 << PinNumber;
								}
                /* 8. Optionally, software can lock the configurations of the NMI and JTAG/SWD pins on the GPIO port pins, by setting the LOCK bits in the GPIOLOCK register. */
						break;
            case 0xE:
                /* Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register */
                RCGCGPIO_REG.B.R4 = 0x1;
                /* Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1 indicates output and a write of a 0 indicates input. */
                if (Port_ConfigPtr->Pin_Dir == PORT_PIN_OUT)
                {
                    PORT_E_GPIODIR_APB.B.DIR |= 1 << PinNumber;
                }
                else
                {
                    PORT_E_GPIODIR_APB.B.DIR &= ~(1 << PinNumber);
                } 
                /* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.
                    If an alternate pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for the specific peripheral required.  */
                /*  To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. 
                   a. To enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the GPIOAMSEL register. */
                if (Port_ConfigPtr->Pin_Mode != PORT_PIN_MODE_GPIO) 
                {
                    PORT_E_GPIOAFSEL_APB.B.AFSEL |= 1 << PinNumber;
                    PORT_E_GPIOAMSEL_APB.B.GPIOAMSEL |= 1 << PinNumber;
                }
                else
                {
                    PORT_E_GPIOAFSEL_APB.B.AFSEL &= ~(1 << PinNumber);
                    PORT_E_GPIODEN_APB.B.DEN |= 1 << PinNumber;
                }

                PORT_E_GPIOPCTL_APB.R = (uint32) (Port_ConfigPtr->Pin_Mode << ((PinNumber-1) * GPIOPCTL_PMC_LENGTH));
                /*  Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers. */
                if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV8)
                {
                    PORT_E_GPIODR8R_APB.B.DRV8 |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV4)
                {
                    PORT_E_GPIODR4R_APB.B.DRV4 |= 1 << PinNumber;
                }
                else
                {
                    PORT_E_GPIODR2R_APB.B.DRV2 |= 1 << PinNumber;
                }
                /*  Program each pad in the port to have either pull-up, pull-down, or open drain functionality through the GPIOPUR, GPIOPDR, GPIOODR register. */
                if(Port_ConfigPtr->Pin_PadType == PORT_PIN_PUR)
                {
                    PORT_E_GPIOPUR_APB.B.PUE |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_PDR)
                {
                    PORT_E_GPIOPDR_APB.B.PDE |= 1 << PinNumber;
                }
                else
                {
                    PORT_E_GPIOODR_APB.B.ODE |= 1 << PinNumber;
                }

                
                if (Port_ConfigPtr->Pin_IntCfg.IntEn == INTERRUPT_ENABLE)
								{
									/*  Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event, and mask of the interrupts for each port.
                    Note: To prevent false interrupts, the following steps should be taken when re-configuring GPIO edge and interrupt sense registers:
                    a. Mask the corresponding port by clearing the IME field in the GPIOIM register.*/
										PORT_E_GPIOIM_APB.B.IME &=  ~(1 << PinNumber);
                    /* b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.*/
										if(Port_ConfigPtr->Pin_IntCfg.IntSense == PIN_EDGE_DETECTION)
										{
												PORT_E_GPIOIS_APB.B.IS &=  ~(1 << PinNumber);
										}
										else
										{
												PORT_E_GPIOIS_APB.B.IS |=  1 << PinNumber;
										}
										
										if((Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_RISING_EDGE) ||(Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_HIGH_LEVEL))
										{
												PORT_E_GPIOIEV_APB.B.IEV |=  1 << PinNumber;
										}
										else
										{
												PORT_E_GPIOIEV_APB.B.IEV &=  ~(1 << PinNumber);
										}
										
										if(Port_ConfigPtr->Pin_IntCfg.IntBE == 0x1)
										{
												PORT_E_GPIOIBE_APB.B.IBE |=  1 << PinNumber;
										}
										else
										{
												PORT_E_GPIOIBE_APB.B.IBE &=  ~(1 << PinNumber);
										}
										
                    /* c. Clear the GPIORIS register. */
										PORT_E_GPIORIS_APB.B.RIS &=  ~(1 << PinNumber);
                    /* d. Unmask the port by setting the IME field in the GPIOIM register. */
										PORT_E_GPIOIM_APB.B.IME |=  1 << PinNumber;
								}
                /* 8. Optionally, software can lock the configurations of the NMI and JTAG/SWD pins on the GPIO port pins, by setting the LOCK bits in the GPIOLOCK register. */
						break;
            case 0xF:
                /* Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register */
                RCGCGPIO_REG.B.R5 = 0x1;
                /* Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1 indicates output and a write of a 0 indicates input. */
                if (Port_ConfigPtr->Pin_Dir == PORT_PIN_OUT)
                {
                    PORT_F_GPIODIR_APB.B.DIR |= 1 << PinNumber;
                }
                else
                {
                    PORT_F_GPIODIR_APB.B.DIR &= ~(1 << PinNumber);
                } 
                /* for PF[0]  -> unlock the GPIOLOCK and uncommit the GPIOCR */
                if (PinNumber == 0x0)
                {
                    PORT_F_GPIOLOCK_APB.R = 0x4C4F434B;
                    PORT_F_GPIOCR_APB.B.CR |= 1 << PinNumber;
                }
                /* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.
                    If an alternate pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for the specific peripheral required.  */
                /*  To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. 
                   a. To enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the GPIOAMSEL register. */
                if (Port_ConfigPtr->Pin_Mode != PORT_PIN_MODE_GPIO) 
                {
                    PORT_F_GPIOAFSEL_APB.B.AFSEL |= 1 << PinNumber;
                    PORT_F_GPIOAMSEL_APB.B.GPIOAMSEL |= 1 << PinNumber;
                }
                else
                {
                    PORT_F_GPIOAFSEL_APB.B.AFSEL &= ~(1 << PinNumber);
                    PORT_F_GPIODEN_APB.B.DEN |= 1 << PinNumber;
                }

                PORT_F_GPIOPCTL_APB.R = (uint32) (Port_ConfigPtr->Pin_Mode << ((PinNumber-1) * GPIOPCTL_PMC_LENGTH));
                /*  Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers. */
                if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV8)
                {
                    PORT_F_GPIODR8R_APB.B.DRV8 |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadDrvCurrent == PORT_PIN_DRV4)
                {
                    PORT_F_GPIODR4R_APB.B.DRV4 |= 1 << PinNumber;
                }
                else
                {
                    PORT_F_GPIODR2R_APB.B.DRV2 |= 1 << PinNumber;
                }
								
                /*  Program each pad in the port to have either pull-up, pull-down, or open drain functionality through the GPIOPUR, GPIOPDR, GPIOODR register. */
                if(Port_ConfigPtr->Pin_PadType == PORT_PIN_PUR)
                {
                    PORT_F_GPIOPUR_APB.B.PUE |= 1 << PinNumber;
                }
                else if(Port_ConfigPtr->Pin_PadType == PORT_PIN_PDR)
                {
                    PORT_F_GPIOPDR_APB.B.PDE |= 1 << PinNumber;
                }
                else
                {
                    PORT_F_GPIOODR_APB.B.ODE |= 1 << PinNumber;
                }

                if (Port_ConfigPtr->Pin_IntCfg.IntEn == INTERRUPT_ENABLE)
								{
									/*  Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event, and mask of the interrupts for each port.
                    Note: To prevent false interrupts, the following steps should be taken when re-configuring GPIO edge and interrupt sense registers:
                    a. Mask the corresponding port by clearing the IME field in the GPIOIM register.*/
										PORT_F_GPIOIM_APB.B.IME &=  ~(1 << PinNumber);
                    /* b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.*/
										if(Port_ConfigPtr->Pin_IntCfg.IntSense == PIN_EDGE_DETECTION)
										{
												PORT_F_GPIOIS_APB.B.IS &=  ~(1 << PinNumber);
										}
										else
										{
												PORT_F_GPIOIS_APB.B.IS |=  1 << PinNumber;
										}
										
										if((Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_RISING_EDGE) ||(Port_ConfigPtr->Pin_IntCfg.IntEv == INTERRUPT_HIGH_LEVEL))
										{
												PORT_F_GPIOIEV_APB.B.IEV |=  1 << PinNumber;
										}
										else
										{
												PORT_F_GPIOIEV_APB.B.IEV &=  ~(1 << PinNumber);
										}
										
										if(Port_ConfigPtr->Pin_IntCfg.IntBE == 0x1)
										{
												PORT_F_GPIOIBE_APB.B.IBE |=  1 << PinNumber;
										}
										else
										{
												PORT_F_GPIOIBE_APB.B.IBE &=  ~(1 << PinNumber);
										}
										
                    /* c. Clear the GPIORIS register. */
										PORT_F_GPIORIS_APB.B.RIS &=  ~(1 << PinNumber);
                    /* d. Unmask the port by setting the IME field in the GPIOIM register. */
										PORT_F_GPIOIM_APB.B.IME |=  1 << PinNumber;
										
										if(Port_ConfigPtr->Pin_IntCfg.Callback != NULL_PTR)
										{
											GPIOF_SetCbk(Port_ConfigPtr->Port_Pin_Number, Port_ConfigPtr->Pin_IntCfg.Callback);
										}
								}
                /* 8. Optionally, software can lock the configurations of the NMI and JTAG/SWD pins on the GPIO port pins, by setting the LOCK bits in the GPIOLOCK register. */
                break;
            default: ;
        }
    }
}

/******************************************************************************
* \Syntax          : GPIOF_SetCbk()                                      
* \Description     : Set GPIOF Call back function with user call back
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                 
* \Parameters (out): None                                                     
* \Return value:   : None
*******************************************************************************/
void GPIOF_SetCbk(Port_PinType pin, void(*Cbf)(void))
{
	if(NULL_PTR != Cbf)
	{
		switch(pin)
		{
			case 0xF0:
				GPIO_F0_Cbf = Cbf;
			break;
			case 0xF4:
				GPIO_F4_Cbf = Cbf;
			break;
			default: ;
		}
	}
}

/******************************************************************************
* \Syntax          : GPIOF_Handler()                                      
* \Description     : GPIOF Irq
*******************************************************************************/
void GPIOF_Handler(void) __attribute__((used));
void GPIOF_Handler(void)
{
		if((PORT_F_GPIORIS_APB.B.RIS & 0x1) == 0x1)
		{
				GPIO_F0_Cbf();
			/* Clear Interrupt */
			PORT_F_GPIOICR_APB.B.IC = 0x01;
		}
		if((PORT_F_GPIORIS_APB.B.RIS & 0x10) == 0x10)
		{
				GPIO_F4_Cbf();
			/* Clear Interrupt */
			PORT_F_GPIOICR_APB.B.IC = 0x10;
		}
		
}


/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
