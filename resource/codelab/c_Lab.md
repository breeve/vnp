# 可变参传递
## code
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
## 解释
https://baike.baidu.com/item/va_list/8573665?fr=aladdin

#ifdef _M_ALPHA
typedef struct {
char *a0; /* pointer to first homed integer argument */
int offset; /* byte offset of next parameter */
} va_list;
#else
typedef char * va_list;
#endif
_M_ALPHA是指DEC ALPHA（Alpha AXP）架构。所以一般情况下va_list所定义变量为字符指针。
宏
INTSIZEOF 宏,获取类型占用的空间长度，最小占用长度为int的整数倍：
#define _INTSIZEOF(n) ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
VA_START宏，获取可变参数列表的第一个参数的地址（ap是类型为va_list的指针，v是可变参数最左边的参数）：
#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) )
VA_ARG宏，获取可变参数的当前参数，返回指定类型并将指针指向下一参数（t参数描述了当前参数的类型）：
#define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
VA_END宏，清空va_list可变参数列表：
#define va_end(ap) ( ap = (va_list)0 )
