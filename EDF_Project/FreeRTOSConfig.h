/*
 * FreeRTOS V202112.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
#include "GPIO.h"
#include <lpc21xx.h>


extern int Task1_Tin, Task2_Tin, Task3_Tin, Task4_Tin, Task5_Tin, Task6_Tin;
extern int Task1_Tout, Task2_Tout, Task3_Tout, Task4_Tout, Task5_Tout, Task6_Tout;
extern int Task1_Ttot, Task2_Ttot, Task3_Ttot, Task4_Ttot, Task5_Ttot, Task6_Ttot;
extern int System_Time, CPU_Load;
/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION            1
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             1
#define configCPU_CLOCK_HZ              ( ( unsigned long ) 60000000 )    /* =12.0MHz xtal multiplied by 5 using the PLL. */
#define configTICK_RATE_HZ              ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES            ( 4 )
#define configMINIMAL_STACK_SIZE        ( ( unsigned short ) 90 )
#define configTOTAL_HEAP_SIZE           ( ( size_t ) 13 * 1024 )
#define configMAX_TASK_NAME_LEN         ( 8 )
#define configUSE_TRACE_FACILITY        0
#define configUSE_16_BIT_TICKS          0
#define configIDLE_SHOULD_YIELD         1
#define configUSE_EDF_SCHEDULER         1
#define configUSE_APPLICATION_TASK_TAG  1
#define configQUEUE_REGISTRY_SIZE       0

#define configSUPPORT_DYNAMIC_ALLOCATION 1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES         0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet        1
#define INCLUDE_vTaskDelete                1
#define INCLUDE_vTaskCleanUpResources    0
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelayUntil            1
#define INCLUDE_vTaskDelay                1

/* Define the traceTASK_SWITCHED_IN() and traceTASK_SWITCHED_IN() macros to output the voltage associated 
    with the task being selected to run on port 0. */
#define traceTASK_SWITCHED_IN() do\
{\
																		if((int)pxCurrentTCB->pxTaskTag == 0) {GPIO_write(PORT_0, PIN7, PIN_IS_HIGH);}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 1)\
																		{\
																			Task1_Tin = T1TC;\
																			GPIO_write(PORT_0, PIN1, PIN_IS_HIGH);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 2)\
																		{\
																			Task2_Tin = T1TC;\
																			GPIO_write(PORT_0, PIN2, PIN_IS_HIGH);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 3)\
																		{\
																			Task3_Tin = T1TC;\
																			GPIO_write(PORT_0, PIN3, PIN_IS_HIGH);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 4)\
																		{\
																			Task4_Tin = T1TC;\
																			GPIO_write(PORT_0, PIN4, PIN_IS_HIGH);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 5)\
																		{\
																			Task5_Tin = T1TC;\
																			GPIO_write(PORT_0, PIN5, PIN_IS_HIGH);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 6)\
																		{\
																			Task6_Tin = T1TC;\
																			GPIO_write(PORT_0, PIN6, PIN_IS_HIGH);\
																		}\
}while(0)

#define traceTASK_SWITCHED_OUT() do\
{\
																		if((int)pxCurrentTCB->pxTaskTag == 0) {GPIO_write(PORT_0, PIN7, PIN_IS_LOW);}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 1)\
																		{\
																			Task1_Tout = T1TC;\
																			Task1_Ttot += Task1_Tout - Task1_Tin;\
																			GPIO_write(PORT_0, PIN1, PIN_IS_LOW);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 2)\
																		{\
																			Task2_Tout = T1TC;\
																			Task2_Ttot += Task2_Tout - Task2_Tin;\
																			GPIO_write(PORT_0, PIN2, PIN_IS_LOW);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 3)\
																		{\
																			Task3_Tout = T1TC;\
																			Task3_Ttot += Task3_Tout - Task3_Tin;\
																			GPIO_write(PORT_0, PIN3, PIN_IS_LOW);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 4)\
																		{\
																			Task4_Tout = T1TC;\
																			Task4_Ttot += Task4_Tout - Task4_Tin;\
																			GPIO_write(PORT_0, PIN4, PIN_IS_LOW);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 5)\
																		{\
																			Task5_Tout = T1TC;\
																			Task5_Ttot += Task5_Tout - Task5_Tin;\
																			GPIO_write(PORT_0, PIN5, PIN_IS_LOW);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 6)\
																		{\
																			Task6_Tout = T1TC;\
																			Task6_Ttot += Task6_Tout - Task6_Tin;\
																			GPIO_write(PORT_0, PIN6, PIN_IS_LOW);\
																		}\
																		System_Time = T1TC;\
																		CPU_Load = ((Task1_Ttot + Task2_Ttot + Task3_Ttot + Task4_Ttot + Task5_Ttot + Task6_Ttot)/ (float) System_Time) * 100;\
}while(0)
#endif /* FREERTOS_CONFIG_H */
