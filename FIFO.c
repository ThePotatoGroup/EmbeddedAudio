//
// Created by Bryce Cater on 3/24/16.
//

#include "FIFO.h"

int FIFO_tx_write_u32(FIFO_t* pFIFO, u32* data)
{
    *(u32 *)(pFIFO->base_address + FIFO_TX_DATA) = data;
    *(u32 *)(pFIFO->base_address + FIFO_TX_LENGTH) = 0x00000004; //data length is 4 for a u32
}


int FIFO_tx_get_vacancies(FIFO_t* pFIFO)
{
    return (*(u32 *)(pFIFO->base_address + FIFO_TX_VAC))&0xFFF;
}


void FIFO_tx_reset(FIFO_t* pFIFO)
{
    *(u32 *)(pFIFO->base_address + FIFO_TX_RESET) = FIFO_TX_RESET_VALUE;
}


bool FIFO_tx_get_interrupt_status(FIFO_t* pFIFO, int interruptBitPosition)
{
    return *(u32 *)(pFIFO->base_address + FIFO_INT_STATUS) & interruptBitPosition;
}


void FIFO_tx_clear_interrupt_status(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(u32 *)(pFIFO->base_address + FIFO_INT_STATUS) |= 0x1 << interruptBitPosition;
}


void FIFO_tx_enable_interrupt(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) |= 0x1 << interruptBitPosition;
}


void FIFO_tx_disable_interrupt(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) &= ~(0x1 << interruptBitPosition);
}


void FIFO_tx_enable_all_Interrupts(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) |= 0xFFF80000;
}


void FIFO_tx_disable_all_Interrupts(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) &= ~0xFFF80000;
}