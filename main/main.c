#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "config_system.h"
#include "sensors.h"
#include "control.h"
#include "display.h"
#include "storage.h"
#include "serial_cmd.h"

sensor_data_t sensor_data;
system_state_t system_state;

void sensor_task(void *arg)
{
    while(1)
    {
        sensors_read(&sensor_data);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void control_task(void *arg)
{
    while(1)
    {
        control_update(&sensor_data,&system_state);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void display_task(void *arg)
{
    while(1)
    {
        display_update(&sensor_data,&system_state);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void log_task(void *arg)
{
    while(1)
    {
        if(system_state.logging_enabled)
            storage_append(&sensor_data,&system_state);

        vTaskDelay(pdMS_TO_TICKS(CONFIG_LOG_INTERVAL_MS));
    }
}

void app_main()
{
    config_system_load_defaults(&system_state);

    sensors_init();
    control_init();
    display_init();
    storage_init();
    serial_cmd_init(&sensor_data,&system_state);

    xTaskCreate(sensor_task,"sensor_task",4096,NULL,5,NULL);
    xTaskCreate(control_task,"control_task",4096,NULL,5,NULL);
    xTaskCreate(display_task,"display_task",4096,NULL,4,NULL);
    xTaskCreate(log_task,"log_task",4096,NULL,3,NULL);
}
