//
// Created by Bryce Cater on 3/24/16.
//

#ifndef EMBEDDEDAUDIO_ADAU1761_CONTROL_H
#define EMBEDDEDAUDIO_ADAU1761_CONTROL_H

#include "i2c.h"

typedef struct adau1761_codec {
    int base_address;
    i2c_t i2c;
} adau1761_codec_t;

void adau1761_codec_init();

#endif //EMBEDDEDAUDIO_ADAU1761_CONTROL_H
