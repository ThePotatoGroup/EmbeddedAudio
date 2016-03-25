//
// Created by Bryce Cater on 3/24/16.
//

#include "FIFO_low_handler.h"

void setup_FIFO_low_handler(sample_pool_t* sample_pool, FIFO_t* FIFO)
{
    pool_and_fifo_t pool_and_fifo = {sample_pool, FIFO};


    XScuGic *pGic; // pointer to GIC interrupt driver
    pGic = prvGetInterruptControllerInstance(); // retrieve pointer to initialized instance

    // connect own interrupt handler
    XScuGic_Connect(pGic, XPS_FPGA15_INT_ID, (Xil_ExceptionHandler) FIFO_low_handler_ISR, (void*) &pool_and_fifo);

    // enable IRQ interrupt at GIC
    XScuGic_Enable(pGic, XPS_FPGA15_INT_ID);

    // define priority and trigger type for AXI Stream FIFO IRQ
    XScuGic_SetPriorityTriggerType(pGic, XPS_FPGA15_INT_ID, 0xA0, 0x3);

    // Enable IRQ in processor core
    Xil_ExceptionEnableMask(XIL_EXCEPTION_IRQ);
}

void FIFO_low_handler_ISR(void* pool_and_FIFO)
{
    sample_pool_t* pSample_pool = ((pool_and_fifo_t*)pool_and_FIFO)->pSample_pool;
    FIFO_t* pFIFO= ((pool_and_fifo_t*)pool_and_FIFO)->pFIFO;

    if (FIFO_get_interrupt_status(pFIFO, FIFO_INT_TFPE))
    {
        int FIFO_vacancy_count = FIFO_tx_get_vacancies(pFIFO);
        int available_samples_count = sample_pool_get_available_count(pSample_pool);
        int sample_count_to_get = FIFO_vacancy_count;
        if (FIFO_vacancy_count > available_samples_count)
        {
            sample_count_to_get = available_samples_count;
        }

        if (sample_count_to_get == 0)
        {
            // TODO Pause audio if no samples are available
        }

        int i;
        for (i=0;i<sample_count_to_get;i++)
        {
            sample_t* sample = sample_pool_get_sample(pSample_pool);
            FIFO_tx_write_u32(pFIFO, (u32*)sample);
        }

        FIFO_clear_interrupt_status(pFIFO, FIFO_INT_TFPE);
    }
}