	/*
	 * FreeRTOS Kernel V10.2.0
	 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

	/* 
			NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
			The processor MUST be in supervisor mode when vTaskStartScheduler is 
			called.  The demo applications included in the FreeRTOS.org download switch
			to supervisor mode prior to main being called.  If you are not using one of
			these demo application projects then ensure Supervisor mode is used.
	*/


	/*
	 * Creates all the demo application tasks, then starts the scheduler.  The WEB
	 * documentation provides more details of the demo application tasks.
	 * 
	 * Main.c also creates a task called "Check".  This only executes every three 
	 * seconds but has the highest priority so is guaranteed to get processor time.  
	 * Its main function is to check that all the other tasks are still operational.
	 * Each task (other than the "flash" tasks) maintains a unique count that is 
	 * incremented each time the task successfully completes its function.  Should 
	 * any error occur within such a task the count is permanently halted.  The 
	 * check task inspects the count of each task to ensure it has changed since
	 * the last time the check task executed.  If all the count variables have 
	 * changed all the tasks are still executing error free, and the check task
	 * toggles the onboard LED.  Should any task contain an error at any time 
	 * the LED toggle rate will change from 3 seconds to 500ms.
	 *
	 */

	/* Standard includes. */
	#include <stdlib.h>
	#include <stdio.h>

	/* Scheduler includes. */
	#include "FreeRTOS.h"
	#include "task.h"
	#include "queue.h"
	#include "lpc21xx.h"

	/* Peripheral includes. */
	#include "serial.h"
	#include "GPIO.h"


	/*-----------------------------------------------------------*/

	/* Constants to setup I/O and processor. */
	#define mainBUS_CLK_FULL    ( ( unsigned char ) 0x01 )

	/* Constants for the ComTest demo application tasks. */
	#define mainCOM_TEST_BAUD_RATE    ( ( unsigned long ) 115200 )

	/* 12ms Ticks number*/
	#define TICKS_COUNT_12MS        ((configCPU_CLOCK_HZ / 5)/1000 * 12 ) /* (XTAL / 1000U)*time_in_ms  */

	/* 12ms Ticks number*/
	#define TICKS_COUNT_5MS        	((configCPU_CLOCK_HZ / 5)/1000 * 5 ) /* (XTAL / 1000U)*time_in_ms  */

	#define MESSAGE_LENGTH         15
	/* Button Messages */
	const char RISING_EDGE[MESSAGE_LENGTH]  = {'#','#','#','#','R','I','S','I','N','G','#','#','#','#','\n'};
	const char FALLING_EDGE[MESSAGE_LENGTH] = {'#','#','#','#','F','A','L','L','I','N','G','#','#','#','\n'};
	/* Periodic Message*/
	const char PERIODIC_MESSAGE[MESSAGE_LENGTH] = {'#','#','M','O','N','I','T','O','R','I','N','G','#','#','\n'};
	/* Default Message*/
	const char DEFAULT_MESSAGE[MESSAGE_LENGTH] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','\n'};

	/* global variables for runtime measurments*/
	int Task1_Tin = 0, Task2_Tin = 0, Task3_Tin = 0, Task4_Tin = 0, Task5_Tin = 0, Task6_Tin = 0;
	int Task1_Tout = 0, Task2_Tout = 0, Task3_Tout = 0, Task4_Tout = 0, Task5_Tout = 0, Task6_Tout = 0;
	int Task1_Ttot = 0, Task2_Ttot = 0, Task3_Ttot = 0, Task4_Ttot = 0, Task5_Ttot = 0, Task6_Ttot = 0;
	int System_Time = 0, CPU_Load = 0;

	TaskHandle_t xTask1_Handle = NULL;
	TaskHandle_t xTask2_Handle = NULL;
	TaskHandle_t xTask3_Handle = NULL;
	TaskHandle_t xTask4_Handle = NULL;
	TaskHandle_t xTask5_Handle = NULL;
	TaskHandle_t xTask6_Handle = NULL;

	QueueHandle_t xQueue1, xQueue2, xQueue3;
	/*
	 * Configure the processor for use with the Keil demo board.  This is very
	 * minimal as most of the setup is managed by the settings in the project
	 * file.
	 */
	static void prvSetupHardware( void );
	/*-----------------------------------------------------------*/

	/* Task to be created. */
	void vTask_1( void * pvParameters )
	{
			TickType_t xLastWakeTime = xTaskGetTickCount();
			pinState_t prevLevel, currLevel;
		
			/* Assign a tag value to the task. */
			vTaskSetApplicationTaskTag( NULL, ( void * ) 1);
		
			/* This task will monitor rising and falling edge on button 1 and send this event to the consumer task. */
			prevLevel = GPIO_read(PORT_0, PIN8);
		
			for( ;; )
			{
					currLevel = GPIO_read(PORT_0, PIN8);
					
					if ( prevLevel != currLevel)
					{
						/* transition detected */
						if (prevLevel == PIN_IS_LOW)
						{
							/* Rising Edge Detected */	
							xQueueSend( xQueue1,
												 ( void * ) &RISING_EDGE,
												 ( TickType_t ) 0 );
						}
						else
						{
							/* Falling Edge Detected */	
							xQueueSend( xQueue1,
												 ( void * ) &FALLING_EDGE,
												 ( TickType_t ) 0 );
						}
							
					}
					else
					{
						/* No level change */
					}
					vTaskDelayUntil(&xLastWakeTime, 50);
			}
	}

	void vTask_2( void * pvParameters )
	{
			TickType_t xLastWakeTime = xTaskGetTickCount();
			pinState_t prevLevel, currLevel;
		
			/* Assign a tag value to the task. */
					vTaskSetApplicationTaskTag( NULL, ( void * ) 2);
		
			/* This task will monitor rising and falling edge on button 2 and send this event to the consumer task. */
			prevLevel = GPIO_read(PORT_0, PIN9);
		
			for( ;; )
			{
					currLevel = GPIO_read(PORT_0, PIN9);
					
					if ( prevLevel != currLevel)
					{
						/* transition detected */
						if (prevLevel == PIN_IS_LOW)
						{
							/* Rising Edge Detected */	
							xQueueSend( xQueue2,
												 ( void * ) &RISING_EDGE,
												 ( TickType_t ) 0 );
						}
						else
						{
							/* Falling Edge Detected */	
							xQueueSend( xQueue2,
												 ( void * ) &FALLING_EDGE,
												 ( TickType_t ) 0 );
						}
							
					}
					else
					{
						/* No level change */
					}
					vTaskDelayUntil(&xLastWakeTime, 50);
			}
	}

	void vTask_3( void * pvParameters )
	{
			TickType_t xLastWakeTime = xTaskGetTickCount();
			
			/* Assign a tag value to the task. */
			vTaskSetApplicationTaskTag( NULL, ( void * ) 3);
			/* This task will send preiodic string every 100ms to the consumer task */
			for( ;; )
			{
					xQueueSend( xQueue3,
												 ( void * ) &PERIODIC_MESSAGE,
												 ( TickType_t ) 0 );
												 
					vTaskDelayUntil(&xLastWakeTime, 100);
			}
	}

	void vTask_4( void * pvParameters )
	{
			TickType_t xLastWakeTime = xTaskGetTickCount();
			char msg1[MESSAGE_LENGTH] = {' '};
			char msg2[MESSAGE_LENGTH] = {' '};
			char msg3[MESSAGE_LENGTH] = {' '};
			
			
			/* Assign a tag value to the task. */
			vTaskSetApplicationTaskTag( NULL, ( void * ) 4); 
			
			/* This is the consumer task which will write on UART any received string from other tasks */
			for( ;; )
			{
				if( xQueueReceive( xQueue1,
													 &(msg1),
													 (TickType_t )0) == pdPASS)
				{
					 /* msg1 now contains a copy of xMessage. */
						vSerialPutString((signed char *)msg1, MESSAGE_LENGTH);
				}
				else
				{
						/* msg1 is empty */
						vSerialPutString((signed char *)DEFAULT_MESSAGE, MESSAGE_LENGTH);
						
				}
					
				
				if( xQueueReceive( xQueue2,
													 &(msg2),
													 (TickType_t )0) == pdPASS)
				{
					 /* msg2 now contains a copy of xMessage. */
						vSerialPutString((signed char *)msg2, MESSAGE_LENGTH);
				}
				else
				{
						/* msg2 is empty */
						vSerialPutString((signed char *)DEFAULT_MESSAGE, MESSAGE_LENGTH);
						
				}
				
				if( xQueueReceive( xQueue3,
													 &(msg3),
													 (TickType_t )0) == pdPASS)
				{
					 /* msg3 now contains a copy of xMessage. */
						vSerialPutString((signed char *)msg3, MESSAGE_LENGTH);
				}
				else
				{
						/* msg3 is empty */
						vSerialPutString((signed char *)DEFAULT_MESSAGE, MESSAGE_LENGTH);
						
				}
				
				/* Reset Queues to their empty values */
				xQueueReset(xQueue1);
				xQueueReset(xQueue2);
				xQueueReset(xQueue3);
				
				vTaskDelayUntil(&xLastWakeTime, 20);
			}
	}

void vTask_5( void * pvParameters )
{

	TickType_t xLastWakeTime = xTaskGetTickCount();
	uint32_t i = 0;
	uint32_t x = TICKS_COUNT_5MS; 
		
		//			/* Assign a tag value to the task. */
			vTaskSetApplicationTaskTag( NULL, ( void * ) 5);
	for( ; ; )
	{
		for( i=0 ; i <= x; i++)
		{
			
		}
		
		vTaskDelayUntil( &xLastWakeTime , 10);
	}		
		
}

void vTask_6( void * pvParameters )
{

		TickType_t xLastWakeTime = xTaskGetTickCount();
		uint32_t i = 0;
		uint32_t x = TICKS_COUNT_12MS;
	
		/* Assign a tag value to the task. */
		vTaskSetApplicationTaskTag( NULL, ( void * ) 6);
	
		for( ; ; )
		{		
			for( i=0 ; i <= x; i++)
			{
				
			}
			
			vTaskDelayUntil( &xLastWakeTime , 100);
			
		}		
		
}

	/*
	 * Application entry point:
	 * Starts all the other tasks, then starts the scheduler. 
	 */
	int main( void )
	{

			/* Create a queue capable of containing 50 unsigned char values. */
			xQueue1 = xQueueCreate((int) MESSAGE_LENGTH, sizeof(char)); 
			xQueue2 = xQueueCreate((int) MESSAGE_LENGTH, sizeof(char)); 
			xQueue3 = xQueueCreate((int) MESSAGE_LENGTH, sizeof(char));
		
			if (xQueue1 == NULL || xQueue2 == NULL || xQueue3 == NULL) return -1;
		
			/* Setup the hardware for use with the Keil demo board. */
			prvSetupHardware();

			
			/* Create Tasks here */
					xTaskPeriodicCreate(
											vTask_1,           /* Function that implements the task. */
											"Button_1_Monitor",          /* Text name for the task. */
											100,               /* Stack size in words, not bytes. */
											( void * ) 0,      /* Parameter passed into the task. */
											1,                 /* Priority at which the task is created. */
											&xTask1_Handle,    /* Used to pass out the created task's handle. */
											50);               /* Task Periodicity (Deadline) */
																					
					xTaskPeriodicCreate(
											vTask_2,           /* Function that implements the task. */
											"Button_2_Monitor",          /* Text name for the task. */
											100,               /* Stack size in words, not bytes. */
											( void * ) 0,      /* Parameter passed into the task. */
											1,                 /* Priority at which the task is created. */
											&xTask2_Handle,    /* Used to pass out the created task's handle. */
											50);               /* Task Periodicity (Deadline) */
																					
					xTaskPeriodicCreate(
											vTask_3,           /* Function that implements the task. */
											"Periodic_Transmitter",          /* Text name for the task. */
											100,               /* Stack size in words, not bytes. */
											( void * ) 0,      /* Parameter passed into the task. */
											1,                 /* Priority at which the task is created. */
											&xTask3_Handle,    /* Used to pass out the created task's handle. */
											100);              /* Task Periodicity (Deadline) */
																					
					xTaskPeriodicCreate(
											vTask_4,           /* Function that implements the task. */
											"Uart_Receiver",          /* Text name for the task. */
											100,               /* Stack size in words, not bytes. */
											( void * ) 0,      /* Parameter passed into the task. */
											1,                 /* Priority at which the task is created. */
											&xTask4_Handle,          /* Used to pass out the created task's handle. */
											20);                     /* Task Periodicity (Deadline) */
																					
					xTaskPeriodicCreate(
											vTask_5,           /* Function that implements the task. */
											"Load_1_Simulation",          /* Text name for the task. */
											100,               /* Stack size in words, not bytes. */
											( void * ) 0,      /* Parameter passed into the task. */
											1,                 /* Priority at which the task is created. */
											&xTask5_Handle,    /* Used to pass out the created task's handle. */
											10);               /* Task Periodicity (Deadline) */
																					
					xTaskPeriodicCreate(
											vTask_6,           /* Function that implements the task. */
											"Load_2_Simulation",          /* Text name for the task. */
											100,               /* Stack size in words, not bytes. */
											( void * ) 0,      /* Parameter passed into the task. */
											1,                 /* Priority at which the task is created. */
											&xTask6_Handle,    /* Used to pass out the created task's handle. */
											100);               /* Task Periodicity (Deadline) */


			/* Now all the tasks have been created - start the scheduler.

			NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
			The processor MUST be in supervisor mode when vTaskStartScheduler is 
			called.  The demo applications included in the FreeRTOS.org download switch
			to supervisor mode prior to main being called.  If you are not using one of
			these demo application projects then ensure Supervisor mode is used here. */
			vTaskStartScheduler();

			/* Should never reach here!  If you do then there was not enough heap
			available for the idle task to be created. */
			for( ;; );
	}
	/*-----------------------------------------------------------*/

	/* Function to reset timer 1 */
	void timer1Reset(void)
	{
			T1TCR |= 0x2;
			T1TCR &= ~0x2;
	}

	/* Function to initialize and start timer 1 */
	static void configTimer1(void)
	{
			T1PR = 1000;
			T1TCR |= 0x1;
	}

	static void prvSetupHardware( void )
	{
			/* Perform the hardware setup required.  This is minimal as most of the
			setup is managed by the settings in the project file. */

			/* Configure UART */
			xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

			/* Configure GPIO */
			GPIO_init();
			/* Config trace timer 1 and read T1TC to get current tick */
			configTimer1();

			/* Setup the peripheral bus to be the same as the PLL output. */
			VPBDIV = mainBUS_CLK_FULL;
	}
	/*
	void vApplicationIdleHook( void )
	{

	}
	*/
	void vApplicationTickHook( void )
	{
			GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
			GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
	}
	/*-----------------------------------------------------------*/


