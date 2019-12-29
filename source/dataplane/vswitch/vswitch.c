#include <stdio.h>
#include "device.h"
#include "base/log.h"

int vswitch_init()
{
    #if 0
	dp_device_t * switch_def = device_create(SWITCH, "switch_def");
    if (switch_def == NULL) {
        log_error("vswitch", "switch_def create fail");
        return -1;
    }
    #endif
    log_info("vswitch", "vswitch init success\n");

    return 0;
}