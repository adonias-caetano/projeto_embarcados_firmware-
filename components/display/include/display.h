#ifndef DISPLAY_H
#define DISPLAY_H

#include "config_system.h"

void display_init();
void display_update(sensor_data_t *sensor, system_state_t *state);

#endif
