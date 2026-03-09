#include "config_system.h"
#include "sdkconfig.h"

void config_system_load_defaults(system_state_t *state)
{
    state->temp_setpoint = CONFIG_DEFAULT_TEMP_SETPOINT;
    state->control_enabled = CONFIG_DEFAULT_CONTROL_ENABLED;
    state->logging_enabled = CONFIG_DEFAULT_LOGGING_ENABLED;
    state->actuator_on = false;
}