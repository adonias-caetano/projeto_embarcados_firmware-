#include "serial_cmd.h"
#include "storage.h"
#include <stdio.h>
#include <string.h>

static sensor_data_t *sensor;
static system_state_t *state;

void serial_cmd_init(sensor_data_t *s, system_state_t *st)
{
    sensor = s;
    state = st;
}

void process_cmd(char *cmd)
{
    if(strcmp(cmd,"readlog")==0)
        storage_read();

    if(strcmp(cmd,"control on")==0)
        state->control_enabled = true;

    if(strcmp(cmd,"control off")==0)
        state->control_enabled = false;

    if(strcmp(cmd,"log on")==0)
        state->logging_enabled = true;

    if(strcmp(cmd,"log off")==0)
        state->logging_enabled = false;
}