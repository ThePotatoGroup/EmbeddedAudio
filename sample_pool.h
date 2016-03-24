//
// Created by Bryce Cater on 3/24/16.
//

#ifndef EMBEDDEDAUDIO_SAMPLE_POOL_H
#define EMBEDDEDAUDIO_SAMPLE_POOL_H

typedef int sample_t;

typedef struct sample_pool
{
    sample_t* start;
    int length;
    int thresh;
    int size;
    int sample_width;
} sample_pool_t;

int sample_pool_fill_samples(sample_pool_t* pPool, int* pSamples_start, int length);
int sample_pool_fill_samples(sample_pool_t* pPool, short* pSamples_start, int length);
int sample_pool_fill_samples(sample_pool_t* pPool, char* pSamples_start, int length);

int sample_pool_get_available_count(sample_pool_t* pPool);

int sample_pool_write_sample(u32* pTargetReg);


#endif //EMBEDDEDAUDIO_SAMPLE_POOL_H