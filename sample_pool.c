//
// Created by Bryce Carter on 3/24/16.
//

#include "sample_pool.h"

int sample_pool_fill_samples(sample_pool_t* pPool, sample_t * pSamples_start, int length)
{
    pPool->length = pPool->length + length;
    memcopy(pPool->end, pSamples_start, length);

    //advancing the end pointer, with looping
    if (((pPool->end - pPool->top)/pPool->sample_width + length) > size)
    {
        pPool->end = pPool->top + (length - (size - (pPool->end - pPool->top)/pPool->sample_width))*pPool->sample_width; // loop to top of pool
    }else
    {
        pPool->end = pPool->end + (pPool->sample_width * length);
    }
}

int sample_pool_get_available_count(sample_pool_t* pPool)
{
    return pPool->size - pPool->length;
}

sample_t* sample_pool_get_sample(sample_pool_t* pPool)
{
    //shortening the length
    pPool->length = pPool->length - 1;

    //check the thresh
    if (pPool->length < pPool->thresh)
    {
        //TCP request more samples
    }

    //advancing the start pointer, with looping
    if ((pPool->start + pPool->sample_width - pPool->top)/pPool->sample_width > size)
    {
        pPool->start = pPool->top; // loop to top of pool
    }else
    {
        pPool->start = pPool->start + pPool->sample_width;
    }

    return pPool->start;
}