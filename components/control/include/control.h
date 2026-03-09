#ifndef CONTROL_H
#define CONTROL_H

#include "config_system.h"

void control_init();
void control_update(sensor_data_t *sensor, system_state_t *state);

#endif
