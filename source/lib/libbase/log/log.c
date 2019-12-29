#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "base/log.h"

#define LOG_BUFF_MAX (1024)

static char * s_appname = "default";
static char s_log_buff[LOG_BUFF_MAX] = {'\0'};
static char s_log_format[LOG_BUFF_MAX] = {'\0'};

char * level_2_str(log_level level)
{
    switch(level) {
        case INFO_LEVEL:
            return "INFO";
        case ERROR_LEVEL:
            return "ERROR";
        default:
            return "unknow";
    }

    return "unknow";
}

void log_out(const char *mode,
    const char * file, int file_len,
    const char * func, int func_len,
    long line, log_level level, 
    const char * format, ...)
{
    va_list args;
    memset(s_log_buff, 0, sizeof(s_log_buff));
    memset(s_log_format, 0, sizeof(s_log_format));

    va_start(args, format);

    snprintf(s_log_format, sizeof(s_log_format), "[%s] [%s] %s", mode, level_2_str(level), format);

    vsnprintf(s_log_buff, LOG_BUFF_MAX-1, s_log_format, args);

    printf("%s", s_log_buff);

    va_end(args);
}

void log_app_init(char * appname)
{
    s_appname = strdup(appname);
    log_info("log", "%s log init success\n", s_appname);
}