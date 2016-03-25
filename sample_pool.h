//
// Created by Bryce Cater on 3/24/16.
//

#ifndef EMBEDDEDAUDIO_SAMPLE_POOL_H
#define EMBEDDEDAUDIO_SAMPLE_POOL_H

#include "zedboard_freertos.h"
#include "EmbeddedAudioTypes.h"

typedef int sample_t;

typedef struct sample_pool
{
    sample_t* start;
    sample_t* end;
    sample_t* top;
    int length;
    int thresh;
    size_t size;
    int sample_width;
} sample_pool_t;

void sample_pool_allocate(sample_pool_t* pPool);

int sample_pool_fill_samples(sample_pool_t* pPool, sample_t * pSamples_start, int length);

int sample_pool_get_available_count(sample_pool_t* pPool);

sample_t* sample_pool_get_sample(sample_pool_t* pPool);


#endif //EMBEDDEDAUDIO_SAMPLE_POOL_H
