# 可变参传递 
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define LOG_OUT_BUF_LEN (512)

char g_buf[LOG_OUT_BUF_LEN] = {0};

void log_out(const char * fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    vsnprintf(g_buf, LOG_OUT_BUF_LEN-1, fmt, ap);

    printf("%s\n", g_buf);

    va_end(ap);
}

#define log_error(errnum, fmt, ...)\
do {\
    log_out("error:%d"fmt, errnum, ##__VA_ARGS__); \
} while(0);

int main()
{
    log_error(1, "%s", "haha");

    return 0;
}

```