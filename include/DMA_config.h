/*  Author  : Fatma                          */
/*  Date    : 8 Feb 2022                     */
/*  version : V1                             */


#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H


/*Channel ID from 0 to 6 */
#define CHANNEL_ID   0


/*Memory to memory mode
This bit is set and cleared by software.
       MEMORT_TO_MEMORY disabled = 0
       MEMORT_TO_MEMORY enabled  = 1    */
#define MEMORT_TO_MEMORY  1



/*Channel priority level
      00: Low
      01: Medium
      10: High
      11: Very high */
#define CHANNEL_PRIORITY   0b11



 /*Memory size
    00: 8-bits
    01: 16-bits
    10: 32-bits
    11: Reserved  */
#define MEMORY_SIZE   0b10



 /*Peripheral size
      00: 8-bits
      01: 16-bits
      10: 32-bits
      11: Reserved  */
#define PERIPHERAL_SIZE   0b10



/*Memory increment mode
 Memory increment mode disabled  = 0
 Memory increment mode enabled   = 1    */
#define MEMORY_INC   1



/*Peripheral increment mode
 Peripheral increment mode disabled  = 0
 Peripheral increment mode enabled   = 1   */
#define PERIPHERAL_INC   1



/* Circular mode
   Circular mode disabled  = 0
   Circular mode enabled   = 1 */
 #define CIRCULAR_MODE   0



/*Data transfer direction
   peripheral to memory = 0
   memory to peripheral = 1  */
#define DATA_DIRECTION   0



/*Transfer error interrupt enable
  TE interrupt disabled   = 0
  TE interrupt enabled    = 1 */
#define TE_INTERRUPT   0



/*Half transfer interrupt enable
  HT interrupt disabled  = 0
  HT interrupt enabled   = 1   */
#define HI_INTERRUPT   0



/* Transfer complete interrupt enable
  TC interrupt disabled  = 0
  TC interrupt enabled   = 1  */
#define TC_INTERRUPT   1



/*Channel enable
  Channel disabled = 0
  Channel enabled  = 1 */
#define CHANNEL_STATUS   0




#endif
