/*  Author  : Fatma                          */
/*  Date    : 8 Feb 2022               */
/*  version : V1                             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "DMA_interface.h"
#include "DMA_private.h"


u16 Local_u16Index;


void main(void)
{
   MRCC_voidInitSysClock();                 /*chose clock system to HSE 8MHZ */
   MRCC_voidEnableClock(AHB, DMA1);         /*Enable DMA1 clock*/
   DMA_VoidChannelInit();                   /*DMA_initialization*/
   MNVIC_voidInit();                        /*NVIC_initialization*/
   MNVIC_voidEnableInterrupt(11);           /*enable interrupt for DMA channel1*/


	u32 Arr1[100]={0};
	u32 Arr2[100];

	u32 Arr3[100]={0};
	u32 Arr4[100];


	DMA_VoidChannelStart(Arr1,Arr2,100);        /*copy arr1 to aar2 with block length=100 using DMA*/


	/*copy arr3 to aar4 with block length=100 using processor*/
	for(Local_u16Index=0;Local_u16Index<100;Local_u16Index++)
	{

		Arr4[Local_u16Index]=Arr3[Local_u16Index];
	}

  /*//Infinite loop
  while (1)
    {
       // Add your code here.
    }*/
}


void DMA1_Channel1_IRQHandler(void)
{
	/*Clear Interrupt flag*/
	DMA->IFCR=1<<0;		/*Clear Global Interrupt flag of channel1*/
	DMA->IFCR=1<<0;		/*Clear transfer complete Interrupt flag of channel1*/
}
