#ifndef SENSORS_H
#define SENSORS_H

#include "config_system.h"

void sensors_init();
void sensors_read(sensor_data_t *data);

#endif
