//
// Created by Bryce Carter on 3/24/16.
//

#include "sample_pool.h"

void sample_pool_allocate(sample_pool_t* pPool)
{
    pPool->sample_width = sizeof(sample_t);
    pPool->start = (sample_t *) malloc(pPool->size * pPool->sample_width);
    pPool->end = pPool->start;
}

int get_length(sample_pool_t* pPool)
{
    return (pPool->end - pPool->start)/pPool->sample_width;
}

int sample_pool_fill_samples(sample_pool_t* pPool, sample_t * pSamples_start, int length)
{
    memcpy(pPool->end, pSamples_start, length);

    //advancing the end pointer, with looping
    advance_pointer(pPool, &(pPool->end), length);
}

int sample_pool_get_available_count(sample_pool_t* pPool)
{
    return pPool->size - get_length(pPool);
}

void advance_pointer(sample_pool_t* pPool, sample_t** pointer, int number_increment)
{
    *pointer = (*pointer - pPool->top + (number_increment * pPool->sample_width))%(pPool->size * pPool->sample_width) + pPool->top;
}

sample_t* sample_pool_get_sample(sample_pool_t* pPool)
{
    sample_t* sample_pointer = pPool->start; // desired sample at current start position

    //advancing the start pointer, with looping
    advance_pointer(pPool, &(pPool->start), 1);

    //check the thresh
    if (get_length(pPool) < pPool->thresh)
    {
        //TCP request more samples
    }

    return sample_pointer;
}

