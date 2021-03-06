//
// Created by Bryce Cater on 3/25/16.
//

#define FIFO_BASE_ADDR 0x43C00000
#define POOL_SIZE 4000
#define POOL_THRESH 2000

#include "FIFO.h"
#include "FIFO_low_handler.h"
#include "sample_data/snd_sample.c"
#include "sample_pool.h"
#include "EmbeddedAudioTypes.h"
#include "zedboard_freertos.h"

unsigned int* current_sample;

void testbench_pool_low_callback(sample_pool_t* pPool, int number_needed)
{
    sample_pool_fill_samples(pPool, (sample_t*)current_sample, number_needed);
    current_sample += number_needed* sizeof(sample_t*);
}

void task(void *pvParameters)
{
	for( ;;)
	{
		vTaskDelay(1);
	}
}

int main()
{
    current_sample = snd_samples;

    FIFO_t FIFO = {FIFO_BASE_ADDR};
    FIFO_init(&FIFO);

    sample_pool_t main_sample_pool;
    main_sample_pool.size = POOL_SIZE;
    main_sample_pool.request_samples_callback = testbench_pool_low_callback;
    sample_pool_allocate(&main_sample_pool);
    main_sample_pool.thresh = POOL_THRESH;

    setup_FIFO_low_handler(&main_sample_pool, &FIFO);

    // Request initial set of data
    main_sample_pool.request_samples_callback(&main_sample_pool, main_sample_pool.size);

    xTaskCreate(task, (signed char*)"HW",configMINIMAL_STACK_SIZE, NULL,tskIDLE_PRIORITY+1,NULL);

    vTaskStartScheduler();
    return(0);
}

typedef int myfunnyvar;


