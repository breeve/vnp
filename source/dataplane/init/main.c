#include <stdio.h>
#include "device.h"
#include "base/dhash.h"
#include "base/log.h"

int main() {
	int ret = -1;

	log_app_init("dataplane");

	ret = device_init();
	if (ret != 0) {
		log_error("init", "device init error\n");
		return -1;
	}
    
    //dhash_create();

    while (1);

    return 0;
}
