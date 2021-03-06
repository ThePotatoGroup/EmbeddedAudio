//
// Created by Bryce Cater on 3/24/16.
//

#ifndef EMBEDDEDAUDIO_SAMPLE_POOL_H
#define EMBEDDEDAUDIO_SAMPLE_POOL_H

#include "zedboard_freertos.h"
#include "EmbeddedAudioTypes.h"

typedef int sample_t;

typedef void (*request_samples_function)(void* pPool, int number_samples);


typedef struct sample_pool
{
    sample_t* start; // pointer to first sample
    sample_t* end; // pointer to last sample
    sample_t* top; // pointer to beginning of sample pool
    int thresh;
    size_t size;
    int sample_width;
    request_samples_function request_samples_callback;
} sample_pool_t;

void sample_pool_allocate(sample_pool_t* pPool);

int get_length(sample_pool_t* pPool);

int sample_pool_fill_samples(sample_pool_t* pPool, sample_t * pSamples_start, int length);

int sample_pool_get_available_count(sample_pool_t* pPool);

void advance_pointer(sample_pool_t* pPool, sample_t** pointer, int number_increment);

sample_t* sample_pool_get_sample(sample_pool_t* pPool);

#endif //EMBEDDEDAUDIO_SAMPLE_POOL_H
