# client

```c
// C langure

typedef connect_type_ {
  UNIX,
  TCP,
  UDP
} connect_type_t;

typedef connect_ {
  connect_type_t type;
  int (*open)();
  int (*send)();
  int recv();
  int connect();
  int wait();
  int close();
} connect_t;

static connect_t

connect_t * connect_unix(char * unix_path);
connect_t * connect_tcp(char * server, int port);

typdef rpc_client_ {
  connect_t * connect;
  void * parser;
  char * inbuf;
  char * outbuf;
} rpc_client_t;


```

