#ifndef CONFIG_SYSTEM_H
#define CONFIG_SYSTEM_H

#include <stdbool.h>

typedef struct
{
    float temperature;
    float humidity;
    int light;
} sensor_data_t;

typedef struct
{
    float temp_setpoint;
    bool control_enabled;
    bool logging_enabled;
    bool actuator_on;
} system_state_t;

void config_system_load_defaults(system_state_t *state);

#endif
