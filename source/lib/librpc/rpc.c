#include "rpc.h"
#include "rpc_unix.h"

connect_t * connect_alloc(connect_type_t type)
{
  switch(type) {
    case UNIX:
      return connect_alloc_unix();
    default:
      return NULL;
  }

  return NULL;
}

int connect_open_unix(connect_t * conn, char * path)
{
  return connect_open_unix_path(conn, path);
}

int connect_open_tcp(char * ip, int port)
{
  return 0;
}