#ifndef STORAGE_H
#define STORAGE_H

#include "config_system.h"

void storage_init();
void storage_append(sensor_data_t *sensor, system_state_t *state);
void storage_read();

#endif
