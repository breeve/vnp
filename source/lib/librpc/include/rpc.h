#ifndef __RPC_H__
#define __RPC_H__

typedef connect_type_ {
  UNIX,
  TCP,
  UDP
} connect_type_t;

typedef connect_ {
  connect_type_t type;
  int fd;
  int (*send)();
  int (*recv)();
  int (*connect)();
  int (*wait)();
  int (*close)();
} connect_t;

typdef rpc_client_ {
  connect_t * connect;
  void * parser;
  char * inbuf;
  char * outbuf;
} rpc_client_t;

connect_t * connect_alloc(connect_type_t type);

int connect_open_unix(char * path);
int connect_open_tcp(char * ip, int port);

#endif