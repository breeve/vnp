#include <stdio.h>
#include <string.h>
#include "base/log.h"

static char * g_appname = "default";

void log_app_init(char * appname)
{
	g_appname = strdup(appname);
	printf("app:%s log init success\n", g_appname);
}

void log_info(char *mode, char *msg)
{
	printf("[%s] INFO %s\n", mode, msg);
}

void log_error(char *mode, char *msg)
{
	printf("[%s] ERROR %s\n", mode, msg);
}