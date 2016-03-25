//
// Created by Bryce Cater on 3/25/16.
//

#define FIFO_BASE_ADDR 0x43C00000
#define POOL_SIZE 4000
#define POOL_THRESH 2000

#include "FIFO.h"
#include "FIFO_low_handler.h"
#include "sample_pool.h"
#include "EmbeddedAudioTypes.h"
#include "zedboard_freertos.h"

int main()
{
    FIFO_t FIFO = {FIFO_BASE_ADDR};
    FIFO_init(&FIFO);

    sample_pool_t main_sample_pool;
    main_sample_pool.size = POOL_SIZE;
    sample_pool_allocate(&main_sample_pool);
    main_sample_pool.thresh = POOL_THRESH;

    setup_FIFO_low_handler(&main_sample_pool, &FIFO);
}

