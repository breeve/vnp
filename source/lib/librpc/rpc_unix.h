#ifndef __RPC_UNIX__
#define __RPC_UNIX__

connect_t * connect_alloc_unix();

int connect_open_unix_path(char *path);

#endif