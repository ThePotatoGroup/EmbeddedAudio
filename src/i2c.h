//
// Created by Bryce Cater on 3/25/16.
//

#ifndef EMBEDDEDAUDIO_I2C_H
#define EMBEDDEDAUDIO_I2C_H

#include "zedboard_freertos.h"

typedef struct i2c
{
    XIicPs i2c;
} i2c_t;

void i2c_init(i2c_t* pI2c, unsigned int device_id, unsigned int clock_speed);
void i2c_send();
int i2c_read();

#endif //EMBEDDEDAUDIO_I2C_H
