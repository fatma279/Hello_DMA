/*
 * DMA.c
 *
 *  Created on: Feb 13, 2022
 *      Author: TECH VALLEY
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_VoidChannelInit(){

	DMA->Channel[CHANNEL_ID].CCR=(MEMORT_TO_MEMORY)<<14   ;     //Memory to memory

	DMA->Channel[CHANNEL_ID].CCR=(CHANNEL_PRIORITY)<<12   ;     //channel priority

	DMA->Channel[CHANNEL_ID].CCR=(MEMORY_SIZE)<<10        ;	    //memory size

	DMA->Channel[CHANNEL_ID].CCR=(PERIPHERAL_SIZE)<<8     ;     //peripheral size

	DMA->Channel[CHANNEL_ID].CCR=(MEMORY_INC)<<7          ;     //memory increment

	DMA->Channel[CHANNEL_ID].CCR=(PERIPHERAL_INC)<<6      ;     //peripheral increment

	DMA->Channel[CHANNEL_ID].CCR=(CIRCULAR_MODE)<<5       ;     //circular mode

	DMA->Channel[CHANNEL_ID].CCR=(DATA_DIRECTION)<<5       ;     //data direction

	DMA->Channel[CHANNEL_ID].CCR=(TE_INTERRUPT)<<4         ;     //Transfer error interrupt

	DMA->Channel[CHANNEL_ID].CCR=(HI_INTERRUPT)<<3         ;     //Half transfer interrupt

	DMA->Channel[CHANNEL_ID].CCR=(TC_INTERRUPT)<<2         ;     //Transfer complete interrupt

	DMA->Channel[CHANNEL_ID].CCR=(CHANNEL_STATUS)<<2       ;      //channel mode


	/* another way to writ all these
	 	DMA->Channel[0].CCR=0x00007AC2;
	 */

}

void DMA_VoidChannelStart(u32* Copy_pu32SourceAddress, u32* Copy_pu32DistinationeAddress,u16 Copy_u16BlockLength)
{
	/*Make sure channel is disabled*/
	CLR_BIT(DMA->Channel[CHANNEL_ID].CCR,0);

	/*Load the addresses*/
	DMA->Channel[CHANNEL_ID].CPAR = Copy_pu32SourceAddress;
	DMA->Channel[CHANNEL_ID].CMAR = Copy_pu32DistinationeAddress;

	/*Load the block length*/
	DMA->Channel[CHANNEL_ID].CNDTR = Copy_u16BlockLength;

	/*Make channel enabled*/
	SET_BIT(DMA->Channel[CHANNEL_ID].CCR,0);

}

