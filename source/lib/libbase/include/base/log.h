#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef enum {
    INFO_LEVEL,
    ERROR_LEVEL,
} log_level; 

void log_app_init(char * appname);

void log_out(const char *mode,
    const char * file, int file_len,
    const char * func, int func_len,
    long line, log_level level, 
    const char * format, ...);

#define log_error(mode, ...) \
    log_out(mode, __FILE__, sizeof(__FILE__)-1, __func__, sizeof(__func__)-1, __LINE__, \
        ERROR_LEVEL, __VA_ARGS__)

#define log_info(mode, ...) \
    log_out(mode, __FILE__, sizeof(__FILE__)-1, __func__, sizeof(__func__)-1, __LINE__, \
        INFO_LEVEL, __VA_ARGS__)



#endif