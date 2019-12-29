#include <stdio.h>

#include "base/dhash.h"
#include "base/log.h"

#include "device.h"
#include "vswitch.h"

int main() {
	int ret = -1;

	log_app_init("dataplane");

	/* device init */
	ret = device_init();
	if (ret != 0) {
		log_error("init", "device init error");
		return -1;
	}

    /* vswitch init */
    ret = vswitch_init();
    if (ret != 0) {
        log_error("init", "vswitch init error");
        return -1;
    }

    while (1);

    return 0;
}
