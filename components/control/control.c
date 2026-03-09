#include "control.h"

void control_init(){}

void control_update(sensor_data_t *sensor, system_state_t *state)
{
    if(!state->control_enabled) return;

    if(sensor->temperature < state->temp_setpoint)
        state->actuator_on = true;
    else
        state->actuator_on = false;
}