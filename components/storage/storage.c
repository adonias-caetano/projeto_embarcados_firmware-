#include "storage.h"
#include <stdio.h>
#include "esp_spiffs.h"

void storage_init()
{
    esp_vfs_spiffs_conf_t conf = {
        .base_path="/spiffs",
        .partition_label=NULL,
        .max_files=5,
        .format_if_mount_failed=true
    };

    esp_vfs_spiffs_register(&conf);
}

void storage_append(sensor_data_t *sensor, system_state_t *state)
{
    FILE *f = fopen("/spiffs/log.txt","a");

    fprintf(f,"%.2f,%.2f,%d\n",
            sensor->temperature,
            sensor->humidity,
            sensor->light);

    fclose(f);
}

void storage_read()
{
    FILE *f = fopen("/spiffs/log.txt","r");

    char line[64];

    while(fgets(line,sizeof(line),f))
        printf("%s",line);

    fclose(f);
}