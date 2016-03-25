//
// Created by Bryce Cater on 3/24/16.
//

#include "FIFO.h"

void FIFO_init(FIFO_t* pFIFO)
{
    //Reset AXI-Streaming FIFO Transmit side
    FIFO_tx_reset(pFIFO);
    //Initialize the TX FIFO buffer with 0
    *(volatile u32 *) (pFIFO->base_address + FIFO_TX_DES) = 0x00;

    //Reset AXI-Streaming FIFO Receive side
    FIFO_rx_reset(pFIFO);
    //Initialize the RX FIFO buffer with 0
    *(volatile u32 *) (pFIFO->base_address + FIFO_RX_DES) = 0x00;

    /* Reset the core and generate the external reset by writing to the Local Link Reset Register. */
    *(volatile u32 *) (pFIFO + FIFO_LLR_OFFSET) = FIFO_LLR_RESET_VALUE;

    /* clear all pending interrupts */
    *(volatile u32 *) (pFIFO->base_address + FIFO_INT_STATUS) = 0xffffffff;
}


int FIFO_tx_write_u32(FIFO_t* pFIFO, u32* data)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_TX_DATA) = data;
    *(volatile u32 *)(pFIFO->base_address + FIFO_TX_LENGTH) = 0x00000004; //data length is 4 for a u32
}


int FIFO_tx_get_vacancies(FIFO_t* pFIFO)
{
    return (*(volatile u32 *)(pFIFO->base_address + FIFO_TX_VAC))&0xFFF;
}


void FIFO_tx_reset(FIFO_t* pFIFO)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_TX_RESET) = FIFO_TX_RESET_VALUE;
}


int FIFO_rx_get_vacancies(FIFO_t* pFIFO)
{
    return (*(volatile u32 *)(pFIFO->base_address + FIFO_TX_VAC))&0xFFF;
}


void FIFO_rx_reset(FIFO_t* pFIFO)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_TX_RESET) = FIFO_TX_RESET_VALUE;
}


bool FIFO_get_interrupt_status(FIFO_t* pFIFO, int interruptBitPosition)
{
    return *(volatile u32 *)(pFIFO->base_address + FIFO_INT_STATUS) & interruptBitPosition;
}


void FIFO_clear_interrupt_status(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_INT_STATUS) = 0x1 << interruptBitPosition;
}


void FIFO_enable_interrupt(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) |= 0x1 << interruptBitPosition;
}


void FIFO_disable_interrupt(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) &= ~(0x1 << interruptBitPosition);
}


void FIFO_enable_all_Interrupts(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) |= 0xFFF80000;
}


void FIFO_disable_all_Interrupts(FIFO_t* pFIFO, int interruptBitPosition)
{
    *(volatile u32 *)(pFIFO->base_address + FIFO_INT_ENABLE) &= ~0xFFF80000;
}