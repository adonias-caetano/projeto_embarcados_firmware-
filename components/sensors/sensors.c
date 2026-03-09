#include "sensors.h"
#include <stdlib.h>

void sensors_init()
{
}

void sensors_read(sensor_data_t *data)
{
    data->temperature = 25 + rand()%5;
    data->humidity = 60 + rand()%10;
    data->light = rand()%2000;
}