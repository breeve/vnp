#ifndef __LOG_H__
#define __LOG_H__

void log_app_init(char * appname);

void log_info(char *mode, char *msg);
void log_error(char *mode, char *msg);

#endif