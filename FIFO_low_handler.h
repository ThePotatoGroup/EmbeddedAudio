//
// Created by Bryce Cater on 3/24/16.
//

#ifndef EMBEDDEDAUDIO_FIFO_LOW_HANDLER_H
#define EMBEDDEDAUDIO_FIFO_LOW_HANDLER_H

#include "EmbeddedAudioTypes.h"
#include "FIFO.h"
#include "sample_pool.h"

typedef struct {
    FIFO_t* pFIFO;
    sample_pool_t* pSample_pool;
} pool_and_fifo_t;

void setup_FIFO_low_handler(sample_pool_t* sample_pool, FIFO_t* FIFO);

void FIFO_low_handler_ISR(void* pool_and_FIFO);

#endif //EMBEDDEDAUDIO_FIFO_LOW_HANDLER_H
