//
// Created by Bryce Cater on 3/25/16.
//

#include "i2c.h"


void i2c_init(i2c_t* pI2c, unsigned int device_id, unsigned int clock_speed)
{
    XIicPs_Config *Config;

    Config = XIicPs_LookupConfig(device_id);
    XIicPs_CfgInitialize(&(pI2c->i2c), Config, Config->BaseAddress);
    XIicPs_SetSClk(&(pI2c->i2c), clock_speed);
}

