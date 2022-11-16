/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_reg.h
 *       Module:  -
 *
 *  Description:  Contains Port Registers      
 *  
 *********************************************************************************************************************/
#ifndef PORT_REG_H
#define PORT_REG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Port_regdef.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* PORTs Base address
* The offset listed is a hexadecimal increment to the register's address,
* relative to that GPIO port's base address*/
#define GPIO_PORT_A_APB_BASEADDR                      0x40004000
#define GPIO_PORT_A_AHB_BASEADDR                      0x40058000
#define GPIO_PORT_B_APB_BASEADDR                      0x40005000
#define GPIO_PORT_B_AHB_BASEADDR                      0x40059000
#define GPIO_PORT_C_APB_BASEADDR                      0x40006000
#define GPIO_PORT_C_AHB_BASEADDR                      0x4005A000
#define GPIO_PORT_D_APB_BASEADDR                      0x40007000
#define GPIO_PORT_D_AHB_BASEADDR                      0x4005B000
#define GPIO_PORT_E_APB_BASEADDR                      0x40024000
#define GPIO_PORT_E_AHB_BASEADDR                      0x4005C000
#define GPIO_PORT_F_APB_BASEADDR                      0x40025000
#define GPIO_PORT_F_AHB_BASEADDR                      0x4005D000

/* GPIO Registers Offsets */
#define GPIODATA_OFFSET                               0x3FC       /* GPIO Data */
#define GPIODIR_OFFSET                                0x400       /* GPIO Direction */
#define GPIOIS_OFFSET                                 0x404       /* Interrupt Sense */
#define GPIOIBE_OFFSET                                0x408       /* GPIO Interrupt Both Edges */
#define GPIOIEV_OFFSET                                0x40C       /* GPIO Interrupt Event */
#define GPIOIM_OFFSET                                 0x410       /* GPIO Interrupt Mask */
#define GPIORIS_OFFSET                                0x414       /* GPIO Raw Interrupt Status */
#define GPIOMIS_OFFSET                                0x418       /* GPIO Masked Interrupt Status */
#define GPIOICR_OFFSET                                0x41C       /* GPIO Interrupt Clear */
#define GPIOAFSEL_OFFSET                              0x420       /* GPIO Alternate Function Select */
#define GPIODR2R_OFFSET                               0x500       /* GPIO 2-mA Drive Select */
#define GPIODR4R_OFFSET                               0x504       /* GPIO 4-mA Drive Select */
#define GPIODR8R_OFFSET                               0x508       /* GPIO 8-mA Drive Select */
#define GPIOODR_OFFSET                                0x50C       /* GPIO Open Drain Select */
#define GPIOPUR_OFFSET                                0x510       /* GPIO Pull-Up Select */
#define GPIOPDR_OFFSET                                0x514       /* GPIO Pull-Down Select */
#define GPIOSLR_OFFSET                                0x518       /* GPIO Slew Rate Control Select */
#define GPIODEN_OFFSET                                0x51C       /* GPIO Digital Enable */
#define GPIOLOCK_OFFSET                               0x520       /* GPIO Lock */
#define GPIOCR_OFFSET                                 0x524       /* GPIO Commit */
#define GPIOAMSEL_OFFSET                              0x528       /* GPIO Analog Mode Select */
#define GPIOPCTL_OFFSET                               0x52C       /* GPIO Port Control */
#define GPIOADCCTL_OFFSET                             0x530       /* GPIO ADC Control */
#define GPIODMACTL_OFFSET                             0x534       /* GPIO DMA Control */
#define GPIOPeriphID4_OFFSET                          0xFD0       /* GPIO Peripheral Identification 4 */
#define GPIOPeriphID5_OFFSET                          0xFD4       /* GPIO Peripheral Identification 5 */
#define GPIOPeriphID6_OFFSET                          0xFD8       /* GPIO Peripheral Identification 6 */
#define GPIOPeriphID7_OFFSET                          0xFDC       /* GPIO Peripheral Identification 7 */
#define GPIOPeriphID0_OFFSET                          0xFE0       /* GPIO Peripheral Identification 0 */
#define GPIOPeriphID1_OFFSET                          0xFE4       /* GPIO Peripheral Identification 1 */
#define GPIOPeriphID2_OFFSET                          0xFE8       /* GPIO Peripheral Identification 2 */
#define GPIOPeriphID3_OFFSET                          0xFEC       /* GPIO Peripheral Identification 3 */
#define GPIOPCellID0_OFFSET                           0xFF0       /* GPIO PrimeCell Identification 0 */
#define GPIOPCellID1_OFFSET                           0xFF4       /* GPIO PrimeCell Identification 1 */
#define GPIOPCellID2_OFFSET                           0xFF8       /* GPIO PrimeCell Identification 2 */
#define GPIOPCellID3_OFFSET                           0xFFC       /* GPIO PrimeCell Identification 3 */


/* Port A registers (APB)*/
#define PORT_A_GPIODATA_APB                          (*(volatile GPIODATA*)(GPIO_PORT_A_APB_BASEADDR + GPIODATA_OFFSET))
#define PORT_A_GPIODIR_APB                           (*(volatile GPIODIR*)(GPIO_PORT_A_APB_BASEADDR + GPIODIR_OFFSET))
#define PORT_A_GPIOIS_APB                            (*(volatile GPIOIS*)(GPIO_PORT_A_APB_BASEADDR + GPIOIS_OFFSET))
#define PORT_A_GPIOIBE_APB                           (*(volatile GPIOIBE*)(GPIO_PORT_A_APB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_A_GPIOIEV_APB                           (*(volatile GPIOIEV*)(GPIO_PORT_A_APB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_A_GPIOIM_APB                            (*(volatile GPIOIM*)(GPIO_PORT_A_APB_BASEADDR + GPIOIM_OFFSET))
#define PORT_A_GPIORIS_APB                           (*(volatile GPIORIS*)(GPIO_PORT_A_APB_BASEADDR + GPIORIS_OFFSET))
#define PORT_A_GPIOMIS_APB                           (*(volatile GPIOMIS*)(GPIO_PORT_A_APB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_A_GPIOICR_APB                           (*(volatile GPIOICR*)(GPIO_PORT_A_APB_BASEADDR + GPIOICR_OFFSET))
#define PORT_A_GPIOAFSEL_APB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_A_APB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_A_GPIODR2R_APB                          (*(volatile GPIODR2R*)(GPIO_PORT_A_APB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_A_GPIODR4R_APB                          (*(volatile GPIODR4R*)(GPIO_PORT_A_APB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_A_GPIODR8R_APB                          (*(volatile GPIODR8R*)(GPIO_PORT_A_APB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_A_GPIOODR_APB                           (*(volatile GPIOODR*)(GPIO_PORT_A_APB_BASEADDR + GPIOODR_OFFSET))
#define PORT_A_GPIOPUR_APB                           (*(volatile GPIOPUR*)(GPIO_PORT_A_APB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_A_GPIOPDR_APB                           (*(volatile GPIOPDR*)(GPIO_PORT_A_APB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_A_GPIOSLR_APB                           (*(volatile GPIOSLR*)(GPIO_PORT_A_APB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_A_GPIODEN_APB                           (*(volatile GPIODEN*)(GPIO_PORT_A_APB_BASEADDR + GPIODEN_OFFSET))
#define PORT_A_GPIOLOCK_APB                          (*(volatile GPIOLOCK*)(GPIO_PORT_A_APB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_A_GPIOCR_APB                            (*(volatile GPIOCR*)(GPIO_PORT_A_APB_BASEADDR + GPIOCR_OFFSET))
#define PORT_A_GPIOAMSEL_APB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_A_APB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_A_GPIOPCTL_APB                          (*(volatile GPIOPCTL*)(GPIO_PORT_A_APB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_A_GPIOADCCTL_APB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_A_APB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_A_GPIODMACTL_APB                        (*(volatile GPIODMACTL*)(GPIO_PORT_A_APB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_A_GPIOPeriphID4_APB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_A_GPIOPeriphID5_APB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_A_GPIOPeriphID6_APB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_A_GPIOPeriphID7_APB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_A_GPIOPeriphID0_APB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_A_GPIOPeriphID1_APB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_A_GPIOPeriphID2_APB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_A_GPIOPeriphID3_APB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_A_APB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_A_GPIOPCellID0_APB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_A_APB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_A_GPIOPCellID1_APB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_A_APB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_A_GPIOPCellID2_APB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_A_APB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_A_GPIOPCellID3_APB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_A_APB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port A registers (AHB)*/
#define PORT_A_GPIODATA_AHB                          (*(volatile GPIODATA*)(GPIO_PORT_A_AHB_BASEADDR + GPIODATA_OFFSET))
#define PORT_A_GPIODIR_AHB                           (*(volatile GPIODIR*)(GPIO_PORT_A_AHB_BASEADDR + GPIODIR_OFFSET))
#define PORT_A_GPIOIS_AHB                            (*(volatile GPIOIS*)(GPIO_PORT_A_AHB_BASEADDR + GPIOIS_OFFSET))
#define PORT_A_GPIOIBE_AHB                           (*(volatile GPIOIBE*)(GPIO_PORT_A_AHB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_A_GPIOIEV_AHB                           (*(volatile GPIOIEV*)(GPIO_PORT_A_AHB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_A_GPIOIM_AHB                            (*(volatile GPIOIM*)(GPIO_PORT_A_AHB_BASEADDR + GPIOIM_OFFSET))
#define PORT_A_GPIORIS_AHB                           (*(volatile GPIORIS*)(GPIO_PORT_A_AHB_BASEADDR + GPIORIS_OFFSET))
#define PORT_A_GPIOMIS_AHB                           (*(volatile GPIOMIS*)(GPIO_PORT_A_AHB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_A_GPIOICR_AHB                           (*(volatile GPIOICR*)(GPIO_PORT_A_AHB_BASEADDR + GPIOICR_OFFSET))
#define PORT_A_GPIOAFSEL_AHB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_A_AHB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_A_GPIODR2R_AHB                          (*(volatile GPIODR2R*)(GPIO_PORT_A_AHB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_A_GPIODR4R_AHB                          (*(volatile GPIODR4R*)(GPIO_PORT_A_AHB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_A_GPIODR8R_AHB                          (*(volatile GPIODR8R*)(GPIO_PORT_A_AHB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_A_GPIOODR_AHB                           (*(volatile GPIOODR*)(GPIO_PORT_A_AHB_BASEADDR + GPIOODR_OFFSET))
#define PORT_A_GPIOPUR_AHB                           (*(volatile GPIOPUR*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_A_GPIOPDR_AHB                           (*(volatile GPIOPDR*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_A_GPIOSLR_AHB                           (*(volatile GPIOSLR*)(GPIO_PORT_A_AHB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_A_GPIODEN_AHB                           (*(volatile GPIODEN*)(GPIO_PORT_A_AHB_BASEADDR + GPIODEN_OFFSET))
#define PORT_A_GPIOLOCK_AHB                          (*(volatile GPIOLOCK*)(GPIO_PORT_A_AHB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_A_GPIOCR_AHB                            (*(volatile GPIOCR*)(GPIO_PORT_A_AHB_BASEADDR + GPIOCR_OFFSET))
#define PORT_A_GPIOAMSEL_AHB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_A_AHB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_A_GPIOPCTL_AHB                          (*(volatile GPIOPCTL*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_A_GPIOADCCTL_AHB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_A_AHB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_A_GPIODMACTL_AHB                        (*(volatile GPIODMACTL*)(GPIO_PORT_A_AHB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_A_GPIOPeriphID4_AHB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_A_GPIOPeriphID5_AHB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_A_GPIOPeriphID6_AHB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_A_GPIOPeriphID7_AHB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_A_GPIOPeriphID0_AHB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_A_GPIOPeriphID1_AHB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_A_GPIOPeriphID2_AHB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_A_GPIOPeriphID3_AHB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_A_GPIOPCellID0_AHB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_A_GPIOPCellID1_AHB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_A_GPIOPCellID2_AHB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_A_GPIOPCellID3_AHB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_A_AHB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port B registers (APB)*/
#define PORT_B_GPIODATA_APB                          (*(volatile GPIODATA*)(GPIO_PORT_B_APB_BASEADDR + GPIODATA_OFFSET))
#define PORT_B_GPIODIR_APB                           (*(volatile GPIODIR*)(GPIO_PORT_B_APB_BASEADDR + GPIODIR_OFFSET))
#define PORT_B_GPIOIS_APB                            (*(volatile GPIOIS*)(GPIO_PORT_B_APB_BASEADDR + GPIOIS_OFFSET))
#define PORT_B_GPIOIBE_APB                           (*(volatile GPIOIBE*)(GPIO_PORT_B_APB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_B_GPIOIEV_APB                           (*(volatile GPIOIEV*)(GPIO_PORT_B_APB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_B_GPIOIM_APB                            (*(volatile GPIOIM*)(GPIO_PORT_B_APB_BASEADDR + GPIOIM_OFFSET))
#define PORT_B_GPIORIS_APB                           (*(volatile GPIORIS*)(GPIO_PORT_B_APB_BASEADDR + GPIORIS_OFFSET))
#define PORT_B_GPIOMIS_APB                           (*(volatile GPIOMIS*)(GPIO_PORT_B_APB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_B_GPIOICR_APB                           (*(volatile GPIOICR*)(GPIO_PORT_B_APB_BASEADDR + GPIOICR_OFFSET))
#define PORT_B_GPIOAFSEL_APB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_B_APB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_B_GPIODR2R_APB                          (*(volatile GPIODR2R*)(GPIO_PORT_B_APB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_B_GPIODR4R_APB                          (*(volatile GPIODR4R*)(GPIO_PORT_B_APB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_B_GPIODR8R_APB                          (*(volatile GPIODR8R*)(GPIO_PORT_B_APB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_B_GPIOODR_APB                           (*(volatile GPIOODR*)(GPIO_PORT_B_APB_BASEADDR + GPIOODR_OFFSET))
#define PORT_B_GPIOPUR_APB                           (*(volatile GPIOPUR*)(GPIO_PORT_B_APB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_B_GPIOPDR_APB                           (*(volatile GPIOPDR*)(GPIO_PORT_B_APB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_B_GPIOSLR_APB                           (*(volatile GPIOSLR*)(GPIO_PORT_B_APB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_B_GPIODEN_APB                           (*(volatile GPIODEN*)(GPIO_PORT_B_APB_BASEADDR + GPIODEN_OFFSET))
#define PORT_B_GPIOLOCK_APB                          (*(volatile GPIOLOCK*)(GPIO_PORT_B_APB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_B_GPIOCR_APB                            (*(volatile GPIOCR*)(GPIO_PORT_B_APB_BASEADDR + GPIOCR_OFFSET))
#define PORT_B_GPIOAMSEL_APB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_B_APB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_B_GPIOPCTL_APB                          (*(volatile GPIOPCTL*)(GPIO_PORT_B_APB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_B_GPIOADCCTL_APB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_B_APB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_B_GPIODMACTL_APB                        (*(volatile GPIODMACTL*)(GPIO_PORT_B_APB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_B_GPIOPeriphID4_APB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_B_GPIOPeriphID5_APB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_B_GPIOPeriphID6_APB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_B_GPIOPeriphID7_APB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_B_GPIOPeriphID0_APB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_B_GPIOPeriphID1_APB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_B_GPIOPeriphID2_APB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_B_GPIOPeriphID3_APB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_B_APB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_B_GPIOPCellID0_APB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_B_APB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_B_GPIOPCellID1_APB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_B_APB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_B_GPIOPCellID2_APB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_B_APB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_B_GPIOPCellID3_APB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_B_APB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port B registers (AHB)*/
#define PORT_B_GPIODATA_AHB                          (*(volatile GPIODATA*)(GPIO_PORT_B_AHB_BASEADDR + GPIODATA_OFFSET))
#define PORT_B_GPIODIR_AHB                           (*(volatile GPIODIR*)(GPIO_PORT_B_AHB_BASEADDR + GPIODIR_OFFSET))
#define PORT_B_GPIOIS_AHB                            (*(volatile GPIOIS*)(GPIO_PORT_B_AHB_BASEADDR + GPIOIS_OFFSET))
#define PORT_B_GPIOIBE_AHB                           (*(volatile GPIOIBE*)(GPIO_PORT_B_AHB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_B_GPIOIEV_AHB                           (*(volatile GPIOIEV*)(GPIO_PORT_B_AHB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_B_GPIOIM_AHB                            (*(volatile GPIOIM*)(GPIO_PORT_B_AHB_BASEADDR + GPIOIM_OFFSET))
#define PORT_B_GPIORIS_AHB                           (*(volatile GPIORIS*)(GPIO_PORT_B_AHB_BASEADDR + GPIORIS_OFFSET))
#define PORT_B_GPIOMIS_AHB                           (*(volatile GPIOMIS*)(GPIO_PORT_B_AHB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_B_GPIOICR_AHB                           (*(volatile GPIOICR*)(GPIO_PORT_B_AHB_BASEADDR + GPIOICR_OFFSET))
#define PORT_B_GPIOAFSEL_AHB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_B_AHB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_B_GPIODR2R_AHB                          (*(volatile GPIODR2R*)(GPIO_PORT_B_AHB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_B_GPIODR4R_AHB                          (*(volatile GPIODR4R*)(GPIO_PORT_B_AHB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_B_GPIODR8R_AHB                          (*(volatile GPIODR8R*)(GPIO_PORT_B_AHB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_B_GPIOODR_AHB                           (*(volatile GPIOODR*)(GPIO_PORT_B_AHB_BASEADDR + GPIOODR_OFFSET))
#define PORT_B_GPIOPUR_AHB                           (*(volatile GPIOPUR*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_B_GPIOPDR_AHB                           (*(volatile GPIOPDR*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_B_GPIOSLR_AHB                           (*(volatile GPIOSLR*)(GPIO_PORT_B_AHB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_B_GPIODEN_AHB                           (*(volatile GPIODEN*)(GPIO_PORT_B_AHB_BASEADDR + GPIODEN_OFFSET))
#define PORT_B_GPIOLOCK_AHB                          (*(volatile GPIOLOCK*)(GPIO_PORT_B_AHB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_B_GPIOCR_AHB                            (*(volatile GPIOCR*)(GPIO_PORT_B_AHB_BASEADDR + GPIOCR_OFFSET))
#define PORT_B_GPIOAMSEL_AHB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_B_AHB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_B_GPIOPCTL_AHB                          (*(volatile GPIOPCTL*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_B_GPIOADCCTL_AHB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_B_AHB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_B_GPIODMACTL_AHB                        (*(volatile GPIODMACTL*)(GPIO_PORT_B_AHB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_B_GPIOPeriphID4_AHB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_B_GPIOPeriphID5_AHB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_B_GPIOPeriphID6_AHB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_B_GPIOPeriphID7_AHB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_B_GPIOPeriphID0_AHB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_B_GPIOPeriphID1_AHB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_B_GPIOPeriphID2_AHB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_B_GPIOPeriphID3_AHB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_B_GPIOPCellID0_AHB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_B_GPIOPCellID1_AHB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_B_GPIOPCellID2_AHB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_B_GPIOPCellID3_AHB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_B_AHB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port C registers (APB)*/
#define PORT_C_GPIODATA_APB                          (*(volatile GPIODATA*)(GPIO_PORT_C_APB_BASEADDR + GPIODATA_OFFSET))
#define PORT_C_GPIODIR_APB                           (*(volatile GPIODIR*)(GPIO_PORT_C_APB_BASEADDR + GPIODIR_OFFSET))
#define PORT_C_GPIOIS_APB                            (*(volatile GPIOIS*)(GPIO_PORT_C_APB_BASEADDR + GPIOIS_OFFSET))
#define PORT_C_GPIOIBE_APB                           (*(volatile GPIOIBE*)(GPIO_PORT_C_APB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_C_GPIOIEV_APB                           (*(volatile GPIOIEV*)(GPIO_PORT_C_APB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_C_GPIOIM_APB                            (*(volatile GPIOIM*)(GPIO_PORT_C_APB_BASEADDR + GPIOIM_OFFSET))
#define PORT_C_GPIORIS_APB                           (*(volatile GPIORIS*)(GPIO_PORT_C_APB_BASEADDR + GPIORIS_OFFSET))
#define PORT_C_GPIOMIS_APB                           (*(volatile GPIOMIS*)(GPIO_PORT_C_APB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_C_GPIOICR_APB                           (*(volatile GPIOICR*)(GPIO_PORT_C_APB_BASEADDR + GPIOICR_OFFSET))
#define PORT_C_GPIOAFSEL_APB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_C_APB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_C_GPIODR2R_APB                          (*(volatile GPIODR2R*)(GPIO_PORT_C_APB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_C_GPIODR4R_APB                          (*(volatile GPIODR4R*)(GPIO_PORT_C_APB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_C_GPIODR8R_APB                          (*(volatile GPIODR8R*)(GPIO_PORT_C_APB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_C_GPIOODR_APB                           (*(volatile GPIOODR*)(GPIO_PORT_C_APB_BASEADDR + GPIOODR_OFFSET))
#define PORT_C_GPIOPUR_APB                           (*(volatile GPIOPUR*)(GPIO_PORT_C_APB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_C_GPIOPDR_APB                           (*(volatile GPIOPDR*)(GPIO_PORT_C_APB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_C_GPIOSLR_APB                           (*(volatile GPIOSLR*)(GPIO_PORT_C_APB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_C_GPIODEN_APB                           (*(volatile GPIODEN*)(GPIO_PORT_C_APB_BASEADDR + GPIODEN_OFFSET))
#define PORT_C_GPIOLOCK_APB                          (*(volatile GPIOLOCK*)(GPIO_PORT_C_APB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_C_GPIOCR_APB                            (*(volatile GPIOCR*)(GPIO_PORT_C_APB_BASEADDR + GPIOCR_OFFSET))
#define PORT_C_GPIOAMSEL_APB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_C_APB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_C_GPIOPCTL_APB                          (*(volatile GPIOPCTL*)(GPIO_PORT_C_APB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_C_GPIOADCCTL_APB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_C_APB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_C_GPIODMACTL_APB                        (*(volatile GPIODMACTL*)(GPIO_PORT_C_APB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_C_GPIOPeriphID4_APB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_C_GPIOPeriphID5_APB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_C_GPIOPeriphID6_APB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_C_GPIOPeriphID7_APB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_C_GPIOPeriphID0_APB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_C_GPIOPeriphID1_APB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_C_GPIOPeriphID2_APB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_C_GPIOPeriphID3_APB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_C_APB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_C_GPIOPCellID0_APB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_C_APB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_C_GPIOPCellID1_APB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_C_APB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_C_GPIOPCellID2_APB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_C_APB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_C_GPIOPCellID3_APB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_C_APB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port C registers (AHB)*/
#define PORT_C_GPIODATA_AHB                          (*(volatile GPIODATA*)(GPIO_PORT_C_AHB_BASEADDR + GPIODATA_OFFSET))
#define PORT_C_GPIODIR_AHB                           (*(volatile GPIODIR*)(GPIO_PORT_C_AHB_BASEADDR + GPIODIR_OFFSET))
#define PORT_C_GPIOIS_AHB                            (*(volatile GPIOIS*)(GPIO_PORT_C_AHB_BASEADDR + GPIOIS_OFFSET))
#define PORT_C_GPIOIBE_AHB                           (*(volatile GPIOIBE*)(GPIO_PORT_C_AHB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_C_GPIOIEV_AHB                           (*(volatile GPIOIEV*)(GPIO_PORT_C_AHB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_C_GPIOIM_AHB                            (*(volatile GPIOIM*)(GPIO_PORT_C_AHB_BASEADDR + GPIOIM_OFFSET))
#define PORT_C_GPIORIS_AHB                           (*(volatile GPIORIS*)(GPIO_PORT_C_AHB_BASEADDR + GPIORIS_OFFSET))
#define PORT_C_GPIOMIS_AHB                           (*(volatile GPIOMIS*)(GPIO_PORT_C_AHB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_C_GPIOICR_AHB                           (*(volatile GPIOICR*)(GPIO_PORT_C_AHB_BASEADDR + GPIOICR_OFFSET))
#define PORT_C_GPIOAFSEL_AHB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_C_AHB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_C_GPIODR2R_AHB                          (*(volatile GPIODR2R*)(GPIO_PORT_C_AHB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_C_GPIODR4R_AHB                          (*(volatile GPIODR4R*)(GPIO_PORT_C_AHB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_C_GPIODR8R_AHB                          (*(volatile GPIODR8R*)(GPIO_PORT_C_AHB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_C_GPIOODR_AHB                           (*(volatile GPIOODR*)(GPIO_PORT_C_AHB_BASEADDR + GPIOODR_OFFSET))
#define PORT_C_GPIOPUR_AHB                           (*(volatile GPIOPUR*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_C_GPIOPDR_AHB                           (*(volatile GPIOPDR*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_C_GPIOSLR_AHB                           (*(volatile GPIOSLR*)(GPIO_PORT_C_AHB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_C_GPIODEN_AHB                           (*(volatile GPIODEN*)(GPIO_PORT_C_AHB_BASEADDR + GPIODEN_OFFSET))
#define PORT_C_GPIOLOCK_AHB                          (*(volatile GPIOLOCK*)(GPIO_PORT_C_AHB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_C_GPIOCR_AHB                            (*(volatile GPIOCR*)(GPIO_PORT_C_AHB_BASEADDR + GPIOCR_OFFSET))
#define PORT_C_GPIOAMSEL_AHB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_C_AHB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_C_GPIOPCTL_AHB                          (*(volatile GPIOPCTL*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_C_GPIOADCCTL_AHB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_C_AHB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_C_GPIODMACTL_AHB                        (*(volatile GPIODMACTL*)(GPIO_PORT_C_AHB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_C_GPIOPeriphID4_AHB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_C_GPIOPeriphID5_AHB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_C_GPIOPeriphID6_AHB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_C_GPIOPeriphID7_AHB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_C_GPIOPeriphID0_AHB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_C_GPIOPeriphID1_AHB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_C_GPIOPeriphID2_AHB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_C_GPIOPeriphID3_AHB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_C_GPIOPCellID0_AHB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_C_GPIOPCellID1_AHB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_C_GPIOPCellID2_AHB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_C_GPIOPCellID3_AHB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_C_AHB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port D registers (APB)*/
#define PORT_D_GPIODATA_APB                          (*(volatile GPIODATA*)(GPIO_PORT_D_APB_BASEADDR + GPIODATA_OFFSET))
#define PORT_D_GPIODIR_APB                           (*(volatile GPIODIR*)(GPIO_PORT_D_APB_BASEADDR + GPIODIR_OFFSET))
#define PORT_D_GPIOIS_APB                            (*(volatile GPIOIS*)(GPIO_PORT_D_APB_BASEADDR + GPIOIS_OFFSET))
#define PORT_D_GPIOIBE_APB                           (*(volatile GPIOIBE*)(GPIO_PORT_D_APB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_D_GPIOIEV_APB                           (*(volatile GPIOIEV*)(GPIO_PORT_D_APB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_D_GPIOIM_APB                            (*(volatile GPIOIM*)(GPIO_PORT_D_APB_BASEADDR + GPIOIM_OFFSET))
#define PORT_D_GPIORIS_APB                           (*(volatile GPIORIS*)(GPIO_PORT_D_APB_BASEADDR + GPIORIS_OFFSET))
#define PORT_D_GPIOMIS_APB                           (*(volatile GPIOMIS*)(GPIO_PORT_D_APB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_D_GPIOICR_APB                           (*(volatile GPIOICR*)(GPIO_PORT_D_APB_BASEADDR + GPIOICR_OFFSET))
#define PORT_D_GPIOAFSEL_APB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_D_APB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_D_GPIODR2R_APB                          (*(volatile GPIODR2R*)(GPIO_PORT_D_APB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_D_GPIODR4R_APB                          (*(volatile GPIODR4R*)(GPIO_PORT_D_APB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_D_GPIODR8R_APB                          (*(volatile GPIODR8R*)(GPIO_PORT_D_APB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_D_GPIOODR_APB                           (*(volatile GPIOODR*)(GPIO_PORT_D_APB_BASEADDR + GPIOODR_OFFSET))
#define PORT_D_GPIOPUR_APB                           (*(volatile GPIOPUR*)(GPIO_PORT_D_APB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_D_GPIOPDR_APB                           (*(volatile GPIOPDR*)(GPIO_PORT_D_APB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_D_GPIOSLR_APB                           (*(volatile GPIOSLR*)(GPIO_PORT_D_APB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_D_GPIODEN_APB                           (*(volatile GPIODEN*)(GPIO_PORT_D_APB_BASEADDR + GPIODEN_OFFSET))
#define PORT_D_GPIOLOCK_APB                          (*(volatile GPIOLOCK*)(GPIO_PORT_D_APB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_D_GPIOCR_APB                            (*(volatile GPIOCR*)(GPIO_PORT_D_APB_BASEADDR + GPIOCR_OFFSET))
#define PORT_D_GPIOAMSEL_APB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_D_APB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_D_GPIOPCTL_APB                          (*(volatile GPIOPCTL*)(GPIO_PORT_D_APB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_D_GPIOADCCTL_APB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_D_APB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_D_GPIODMACTL_APB                        (*(volatile GPIODMACTL*)(GPIO_PORT_D_APB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_D_GPIOPeriphID4_APB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_D_GPIOPeriphID5_APB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_D_GPIOPeriphID6_APB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_D_GPIOPeriphID7_APB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_D_GPIOPeriphID0_APB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_D_GPIOPeriphID1_APB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_D_GPIOPeriphID2_APB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_D_GPIOPeriphID3_APB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_D_APB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_D_GPIOPCellID0_APB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_D_APB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_D_GPIOPCellID1_APB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_D_APB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_D_GPIOPCellID2_APB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_D_APB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_D_GPIOPCellID3_APB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_D_APB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port D registers (AHB)*/
#define PORT_D_GPIODATA_AHB                          (*(volatile GPIODATA*)(GPIO_PORT_D_AHB_BASEADDR + GPIODATA_OFFSET))
#define PORT_D_GPIODIR_AHB                           (*(volatile GPIODIR*)(GPIO_PORT_D_AHB_BASEADDR + GPIODIR_OFFSET))
#define PORT_D_GPIOIS_AHB                            (*(volatile GPIOIS*)(GPIO_PORT_D_AHB_BASEADDR + GPIOIS_OFFSET))
#define PORT_D_GPIOIBE_AHB                           (*(volatile GPIOIBE*)(GPIO_PORT_D_AHB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_D_GPIOIEV_AHB                           (*(volatile GPIOIEV*)(GPIO_PORT_D_AHB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_D_GPIOIM_AHB                            (*(volatile GPIOIM*)(GPIO_PORT_D_AHB_BASEADDR + GPIOIM_OFFSET))
#define PORT_D_GPIORIS_AHB                           (*(volatile GPIORIS*)(GPIO_PORT_D_AHB_BASEADDR + GPIORIS_OFFSET))
#define PORT_D_GPIOMIS_AHB                           (*(volatile GPIOMIS*)(GPIO_PORT_D_AHB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_D_GPIOICR_AHB                           (*(volatile GPIOICR*)(GPIO_PORT_D_AHB_BASEADDR + GPIOICR_OFFSET))
#define PORT_D_GPIOAFSEL_AHB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_D_AHB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_D_GPIODR2R_AHB                          (*(volatile GPIODR2R*)(GPIO_PORT_D_AHB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_D_GPIODR4R_AHB                          (*(volatile GPIODR4R*)(GPIO_PORT_D_AHB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_D_GPIODR8R_AHB                          (*(volatile GPIODR8R*)(GPIO_PORT_D_AHB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_D_GPIOODR_AHB                           (*(volatile GPIOODR*)(GPIO_PORT_D_AHB_BASEADDR + GPIOODR_OFFSET))
#define PORT_D_GPIOPUR_AHB                           (*(volatile GPIOPUR*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_D_GPIOPDR_AHB                           (*(volatile GPIOPDR*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_D_GPIOSLR_AHB                           (*(volatile GPIOSLR*)(GPIO_PORT_D_AHB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_D_GPIODEN_AHB                           (*(volatile GPIODEN*)(GPIO_PORT_D_AHB_BASEADDR + GPIODEN_OFFSET))
#define PORT_D_GPIOLOCK_AHB                          (*(volatile GPIOLOCK*)(GPIO_PORT_D_AHB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_D_GPIOCR_AHB                            (*(volatile GPIOCR*)(GPIO_PORT_D_AHB_BASEADDR + GPIOCR_OFFSET))
#define PORT_D_GPIOAMSEL_AHB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_D_AHB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_D_GPIOPCTL_AHB                          (*(volatile GPIOPCTL*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_D_GPIOADCCTL_AHB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_D_AHB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_D_GPIODMACTL_AHB                        (*(volatile GPIODMACTL*)(GPIO_PORT_D_AHB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_D_GPIOPeriphID4_AHB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_D_GPIOPeriphID5_AHB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_D_GPIOPeriphID6_AHB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_D_GPIOPeriphID7_AHB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_D_GPIOPeriphID0_AHB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_D_GPIOPeriphID1_AHB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_D_GPIOPeriphID2_AHB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_D_GPIOPeriphID3_AHB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_D_GPIOPCellID0_AHB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_D_GPIOPCellID1_AHB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_D_GPIOPCellID2_AHB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_D_GPIOPCellID3_AHB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_D_AHB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port E registers (APB)*/
#define PORT_E_GPIODATA_APB                          (*(volatile GPIODATA*)(GPIO_PORT_E_APB_BASEADDR + GPIODATA_OFFSET))
#define PORT_E_GPIODIR_APB                           (*(volatile GPIODIR*)(GPIO_PORT_E_APB_BASEADDR + GPIODIR_OFFSET))
#define PORT_E_GPIOIS_APB                            (*(volatile GPIOIS*)(GPIO_PORT_E_APB_BASEADDR + GPIOIS_OFFSET))
#define PORT_E_GPIOIBE_APB                           (*(volatile GPIOIBE*)(GPIO_PORT_E_APB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_E_GPIOIEV_APB                           (*(volatile GPIOIEV*)(GPIO_PORT_E_APB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_E_GPIOIM_APB                            (*(volatile GPIOIM*)(GPIO_PORT_E_APB_BASEADDR + GPIOIM_OFFSET))
#define PORT_E_GPIORIS_APB                           (*(volatile GPIORIS*)(GPIO_PORT_E_APB_BASEADDR + GPIORIS_OFFSET))
#define PORT_E_GPIOMIS_APB                           (*(volatile GPIOMIS*)(GPIO_PORT_E_APB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_E_GPIOICR_APB                           (*(volatile GPIOICR*)(GPIO_PORT_E_APB_BASEADDR + GPIOICR_OFFSET))
#define PORT_E_GPIOAFSEL_APB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_E_APB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_E_GPIODR2R_APB                          (*(volatile GPIODR2R*)(GPIO_PORT_E_APB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_E_GPIODR4R_APB                          (*(volatile GPIODR4R*)(GPIO_PORT_E_APB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_E_GPIODR8R_APB                          (*(volatile GPIODR8R*)(GPIO_PORT_E_APB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_E_GPIOODR_APB                           (*(volatile GPIOODR*)(GPIO_PORT_E_APB_BASEADDR + GPIOODR_OFFSET))
#define PORT_E_GPIOPUR_APB                           (*(volatile GPIOPUR*)(GPIO_PORT_E_APB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_E_GPIOPDR_APB                           (*(volatile GPIOPDR*)(GPIO_PORT_E_APB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_E_GPIOSLR_APB                           (*(volatile GPIOSLR*)(GPIO_PORT_E_APB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_E_GPIODEN_APB                           (*(volatile GPIODEN*)(GPIO_PORT_E_APB_BASEADDR + GPIODEN_OFFSET))
#define PORT_E_GPIOLOCK_APB                          (*(volatile GPIOLOCK*)(GPIO_PORT_E_APB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_E_GPIOCR_APB                            (*(volatile GPIOCR*)(GPIO_PORT_E_APB_BASEADDR + GPIOCR_OFFSET))
#define PORT_E_GPIOAMSEL_APB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_E_APB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_E_GPIOPCTL_APB                          (*(volatile GPIOPCTL*)(GPIO_PORT_E_APB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_E_GPIOADCCTL_APB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_E_APB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_E_GPIODMACTL_APB                        (*(volatile GPIODMACTL*)(GPIO_PORT_E_APB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_E_GPIOPeriphID4_APB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_E_GPIOPeriphID5_APB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_E_GPIOPeriphID6_APB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_E_GPIOPeriphID7_APB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_E_GPIOPeriphID0_APB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_E_GPIOPeriphID1_APB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_E_GPIOPeriphID2_APB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_E_GPIOPeriphID3_APB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_E_APB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_E_GPIOPCellID0_APB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_E_APB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_E_GPIOPCellID1_APB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_E_APB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_E_GPIOPCellID2_APB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_E_APB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_E_GPIOPCellID3_APB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_E_APB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port E registers (AHB)*/
#define PORT_E_GPIODATA_AHB                          (*(volatile GPIODATA*)(GPIO_PORT_E_AHB_BASEADDR + GPIODATA_OFFSET))
#define PORT_E_GPIODIR_AHB                           (*(volatile GPIODIR*)(GPIO_PORT_E_AHB_BASEADDR + GPIODIR_OFFSET))
#define PORT_E_GPIOIS_AHB                            (*(volatile GPIOIS*)(GPIO_PORT_E_AHB_BASEADDR + GPIOIS_OFFSET))
#define PORT_E_GPIOIBE_AHB                           (*(volatile GPIOIBE*)(GPIO_PORT_E_AHB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_E_GPIOIEV_AHB                           (*(volatile GPIOIEV*)(GPIO_PORT_E_AHB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_E_GPIOIM_AHB                            (*(volatile GPIOIM*)(GPIO_PORT_E_AHB_BASEADDR + GPIOIM_OFFSET))
#define PORT_E_GPIORIS_AHB                           (*(volatile GPIORIS*)(GPIO_PORT_E_AHB_BASEADDR + GPIORIS_OFFSET))
#define PORT_E_GPIOMIS_AHB                           (*(volatile GPIOMIS*)(GPIO_PORT_E_AHB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_E_GPIOICR_AHB                           (*(volatile GPIOICR*)(GPIO_PORT_E_AHB_BASEADDR + GPIOICR_OFFSET))
#define PORT_E_GPIOAFSEL_AHB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_E_AHB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_E_GPIODR2R_AHB                          (*(volatile GPIODR2R*)(GPIO_PORT_E_AHB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_E_GPIODR4R_AHB                          (*(volatile GPIODR4R*)(GPIO_PORT_E_AHB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_E_GPIODR8R_AHB                          (*(volatile GPIODR8R*)(GPIO_PORT_E_AHB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_E_GPIOODR_AHB                           (*(volatile GPIOODR*)(GPIO_PORT_E_AHB_BASEADDR + GPIOODR_OFFSET))
#define PORT_E_GPIOPUR_AHB                           (*(volatile GPIOPUR*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_E_GPIOPDR_AHB                           (*(volatile GPIOPDR*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_E_GPIOSLR_AHB                           (*(volatile GPIOSLR*)(GPIO_PORT_E_AHB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_E_GPIODEN_AHB                           (*(volatile GPIODEN*)(GPIO_PORT_E_AHB_BASEADDR + GPIODEN_OFFSET))
#define PORT_E_GPIOLOCK_AHB                          (*(volatile GPIOLOCK*)(GPIO_PORT_E_AHB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_E_GPIOCR_AHB                            (*(volatile GPIOCR*)(GPIO_PORT_E_AHB_BASEADDR + GPIOCR_OFFSET))
#define PORT_E_GPIOAMSEL_AHB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_E_AHB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_E_GPIOPCTL_AHB                          (*(volatile GPIOPCTL*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_E_GPIOADCCTL_AHB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_E_AHB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_E_GPIODMACTL_AHB                        (*(volatile GPIODMACTL*)(GPIO_PORT_E_AHB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_E_GPIOPeriphID4_AHB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_E_GPIOPeriphID5_AHB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_E_GPIOPeriphID6_AHB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_E_GPIOPeriphID7_AHB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_E_GPIOPeriphID0_AHB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_E_GPIOPeriphID1_AHB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_E_GPIOPeriphID2_AHB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_E_GPIOPeriphID3_AHB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_E_GPIOPCellID0_AHB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_E_GPIOPCellID1_AHB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_E_GPIOPCellID2_AHB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_E_GPIOPCellID3_AHB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_E_AHB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port F registers (APB)*/
#define PORT_F_GPIODATA_APB                          (*(volatile GPIODATA*)(GPIO_PORT_F_APB_BASEADDR + GPIODATA_OFFSET))
#define PORT_F_GPIODIR_APB                           (*(volatile GPIODIR*)(GPIO_PORT_F_APB_BASEADDR + GPIODIR_OFFSET))
#define PORT_F_GPIOIS_APB                            (*(volatile GPIOIS*)(GPIO_PORT_F_APB_BASEADDR + GPIOIS_OFFSET))
#define PORT_F_GPIOIBE_APB                           (*(volatile GPIOIBE*)(GPIO_PORT_F_APB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_F_GPIOIEV_APB                           (*(volatile GPIOIEV*)(GPIO_PORT_F_APB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_F_GPIOIM_APB                            (*(volatile GPIOIM*)(GPIO_PORT_F_APB_BASEADDR + GPIOIM_OFFSET))
#define PORT_F_GPIORIS_APB                           (*(volatile GPIORIS*)(GPIO_PORT_F_APB_BASEADDR + GPIORIS_OFFSET))
#define PORT_F_GPIOMIS_APB                           (*(volatile GPIOMIS*)(GPIO_PORT_F_APB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_F_GPIOICR_APB                           (*(volatile GPIOICR*)(GPIO_PORT_F_APB_BASEADDR + GPIOICR_OFFSET))
#define PORT_F_GPIOAFSEL_APB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_F_APB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_F_GPIODR2R_APB                          (*(volatile GPIODR2R*)(GPIO_PORT_F_APB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_F_GPIODR4R_APB                          (*(volatile GPIODR4R*)(GPIO_PORT_F_APB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_F_GPIODR8R_APB                          (*(volatile GPIODR8R*)(GPIO_PORT_F_APB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_F_GPIOODR_APB                           (*(volatile GPIOODR*)(GPIO_PORT_F_APB_BASEADDR + GPIOODR_OFFSET))
#define PORT_F_GPIOPUR_APB                           (*(volatile GPIOPUR*)(GPIO_PORT_F_APB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_F_GPIOPDR_APB                           (*(volatile GPIOPDR*)(GPIO_PORT_F_APB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_F_GPIOSLR_APB                           (*(volatile GPIOSLR*)(GPIO_PORT_F_APB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_F_GPIODEN_APB                           (*(volatile GPIODEN*)(GPIO_PORT_F_APB_BASEADDR + GPIODEN_OFFSET))
#define PORT_F_GPIOLOCK_APB                          (*(volatile GPIOLOCK*)(GPIO_PORT_F_APB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_F_GPIOCR_APB                            (*(volatile GPIOCR*)(GPIO_PORT_F_APB_BASEADDR + GPIOCR_OFFSET))
#define PORT_F_GPIOAMSEL_APB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_F_APB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_F_GPIOPCTL_APB                          (*(volatile GPIOPCTL*)(GPIO_PORT_F_APB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_F_GPIOADCCTL_APB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_F_APB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_F_GPIODMACTL_APB                        (*(volatile GPIODMACTL*)(GPIO_PORT_F_APB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_F_GPIOPeriphID4_APB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_F_GPIOPeriphID5_APB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_F_GPIOPeriphID6_APB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_F_GPIOPeriphID7_APB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_F_GPIOPeriphID0_APB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_F_GPIOPeriphID1_APB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_F_GPIOPeriphID2_APB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_F_GPIOPeriphID3_APB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_F_APB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_F_GPIOPCellID0_APB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_F_APB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_F_GPIOPCellID1_APB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_F_APB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_F_GPIOPCellID2_APB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_F_APB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_F_GPIOPCellID3_APB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_F_APB_BASEADDR + GPIOPCellID3_OFFSET))

/* Port F registers (AHB)*/
#define PORT_F_GPIODATA_AHB                          (*(volatile GPIODATA*)(GPIO_PORT_F_AHB_BASEADDR + GPIODATA_OFFSET))
#define PORT_F_GPIODIR_AHB                           (*(volatile GPIODIR*)(GPIO_PORT_F_AHB_BASEADDR + GPIODIR_OFFSET))
#define PORT_F_GPIOIS_AHB                            (*(volatile GPIOIS*)(GPIO_PORT_F_AHB_BASEADDR + GPIOIS_OFFSET))
#define PORT_F_GPIOIBE_AHB                           (*(volatile GPIOIBE*)(GPIO_PORT_F_AHB_BASEADDR + GPIOIBE_OFFSET))
#define PORT_F_GPIOIEV_AHB                           (*(volatile GPIOIEV*)(GPIO_PORT_F_AHB_BASEADDR + GPIOIEV_OFFSET))
#define PORT_F_GPIOIM_AHB                            (*(volatile GPIOIM*)(GPIO_PORT_F_AHB_BASEADDR + GPIOIM_OFFSET))
#define PORT_F_GPIORIS_AHB                           (*(volatile GPIORIS*)(GPIO_PORT_F_AHB_BASEADDR + GPIORIS_OFFSET))
#define PORT_F_GPIOMIS_AHB                           (*(volatile GPIOMIS*)(GPIO_PORT_F_AHB_BASEADDR + GPIOMIS_OFFSET))
#define PORT_F_GPIOICR_AHB                           (*(volatile GPIOICR*)(GPIO_PORT_F_AHB_BASEADDR + GPIOICR_OFFSET))
#define PORT_F_GPIOAFSEL_AHB                         (*(volatile GPIOAFSEL*)(GPIO_PORT_F_AHB_BASEADDR + GPIOAFSEL_OFFSET))
#define PORT_F_GPIODR2R_AHB                          (*(volatile GPIODR2R*)(GPIO_PORT_F_AHB_BASEADDR + GPIODR2R_OFFSET))
#define PORT_F_GPIODR4R_AHB                          (*(volatile GPIODR4R*)(GPIO_PORT_F_AHB_BASEADDR + GPIODR4R_OFFSET))
#define PORT_F_GPIODR8R_AHB                          (*(volatile GPIODR8R*)(GPIO_PORT_F_AHB_BASEADDR + GPIODR8R_OFFSET))
#define PORT_F_GPIOODR_AHB                           (*(volatile GPIOODR*)(GPIO_PORT_F_AHB_BASEADDR + GPIOODR_OFFSET))
#define PORT_F_GPIOPUR_AHB                           (*(volatile GPIOPUR*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPUR_OFFSET))
#define PORT_F_GPIOPDR_AHB                           (*(volatile GPIOPDR*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPDR_OFFSET))
#define PORT_F_GPIOSLR_AHB                           (*(volatile GPIOSLR*)(GPIO_PORT_F_AHB_BASEADDR + GPIOSLR_OFFSET))
#define PORT_F_GPIODEN_AHB                           (*(volatile GPIODEN*)(GPIO_PORT_F_AHB_BASEADDR + GPIODEN_OFFSET))
#define PORT_F_GPIOLOCK_AHB                          (*(volatile GPIOLOCK*)(GPIO_PORT_F_AHB_BASEADDR + GPIOLOCK_OFFSET))
#define PORT_F_GPIOCR_AHB                            (*(volatile GPIOCR*)(GPIO_PORT_F_AHB_BASEADDR + GPIOCR_OFFSET))
#define PORT_F_GPIOAMSEL_AHB                         (*(volatile GPIOAMSEL*)(GPIO_PORT_F_AHB_BASEADDR + GPIOAMSEL_OFFSET))
#define PORT_F_GPIOPCTL_AHB                          (*(volatile GPIOPCTL*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPCTL_OFFSET))
#define PORT_F_GPIOADCCTL_AHB                        (*(volatile GPIOADCCTL*)(GPIO_PORT_F_AHB_BASEADDR + GPIOADCCTL_OFFSET))
#define PORT_F_GPIODMACTL_AHB                        (*(volatile GPIODMACTL*)(GPIO_PORT_F_AHB_BASEADDR + GPIODMACTL_OFFSET))
#define PORT_F_GPIOPeriphID4_AHB                     (*(volatile GPIOPeriphID4*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID4_OFFSET))
#define PORT_F_GPIOPeriphID5_AHB                     (*(volatile GPIOPeriphID5*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID5_OFFSET))
#define PORT_F_GPIOPeriphID6_AHB                     (*(volatile GPIOPeriphID6*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID6_OFFSET))
#define PORT_F_GPIOPeriphID7_AHB                     (*(volatile GPIOPeriphID7*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID7_OFFSET))
#define PORT_F_GPIOPeriphID0_AHB                     (*(volatile GPIOPeriphID0*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID0_OFFSET))
#define PORT_F_GPIOPeriphID1_AHB                     (*(volatile GPIOPeriphID1*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID1_OFFSET))
#define PORT_F_GPIOPeriphID2_AHB                     (*(volatile GPIOPeriphID2*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID2_OFFSET))
#define PORT_F_GPIOPeriphID3_AHB                     (*(volatile GPIOPeriphID3*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPeriphID3_OFFSET))
#define PORT_F_GPIOPCellID0_AHB                      (*(volatile GPIOPCellID0*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPCellID0_OFFSET))
#define PORT_F_GPIOPCellID1_AHB                      (*(volatile GPIOPCellID1*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPCellID1_OFFSET))
#define PORT_F_GPIOPCellID2_AHB                      (*(volatile GPIOPCellID2*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPCellID2_OFFSET))
#define PORT_F_GPIOPCellID3_AHB                      (*(volatile GPIOPCellID3*)(GPIO_PORT_F_AHB_BASEADDR + GPIOPCellID3_OFFSET))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_REG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_reg.h
 *********************************************************************************************************************/
