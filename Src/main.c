/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
#include<stdint.h>
#include"main.h"

/* task handler function prototypes */
void task1_handler(void); //This is task1
void task2_handler(void); //this is task2
void task3_handler(void); //this is task3
void task4_handler(void); // this is task4 of the application

void init_systick_timer(uint32_t tick_hz);

/* This function executes in THREAD MODE of the processor */
int main(void)
{
  init_systick_timer(TICK_HZ);
  for(;;);
}

void task1_handler(void)
{
	while(1)
	{
		printf("This is Task1\n");
	}
}

void task2_handler(void)
{
	while(1)
	{
		printf("This is Task2\n");
	}
}

void task3_handler(void)
{
	while(1)
	{
		printf("This is Task3\n");
	}
}

void task4_handler(void)
{
	while(1)
	{
		printf("This is Task4\n");
	}
}

void init_systick_timer(uint32_t tick_hz)
{
  uint32_t *pSCSR = (uint32_t *)0xE000E010;
  uint32_t *pSRVR = (uint32_t *)0xE000E014;
  /* calculation of reload value */
  uint32_t count_value = (SYSTICK_TIM_CLK/tick_hz)-1; /* reload value is 16000-1 */
  /* Clear the value of SRVR */
  *pSRVR &= ~(0xFFFFFFFF);
  *pSRVR |= count_value;

  //do some settings
  *pSCSR |= ( 1 << 1); //Enables SysTick exception request:
  *pSCSR |= ( 1 << 2);  //Indicates the clock source, processor clock source

  //enable the systick
  *pSCSR |= ( 1 << 0); //enables the counter
}

void  SysTick_Handler(void)
{

}
