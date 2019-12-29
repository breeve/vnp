//
// Created by 张锋 on 2019/12/28.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base/log.h"
#include "device.h"

int device_init()
{
    log_info("device", "device init success\n");
    return 0;
}

dp_device_t * device_create(DP_DEVICE_TYPE_T type, char *name)
{
    dp_device_t * device = (dp_device_t*)malloc(sizeof(dp_device_t));
    if (device == NULL) {
        log_error("device", "create fail error");
        return NULL;
    }
    memset(device, 0, sizeof(dp_device_t));

    if (strlen(name) > (DP_PORT_NAME-1)) {
        free(device);
        log_error("device", "%s exceed %d", name, DP_PORT_NAME);
        return NULL;
    }
    strncmp(device->name, name, strlen(name));

    log_info("device", "%s create success", name);

    return device;
}