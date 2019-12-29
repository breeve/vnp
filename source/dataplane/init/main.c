#include <stdio.h>
#include "device.h"
#include "base/dhash.h"

int main() {
    dhash_create();
    device_init();

    while (1);

    return 0;
}
