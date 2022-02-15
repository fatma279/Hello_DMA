/*  Author  : Fatma                          */
/*  Date    : 8 Feb 2022                     */
/*  version : V1                             */

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H



void DMA_VoidChannelInit(void);

void DMA_VoidChannelStart(u32* Copy_pu32SourceAddress, u32* Copy_pu32DistinationeAddress,u16 Copy_u16BlockLength);








#endif
