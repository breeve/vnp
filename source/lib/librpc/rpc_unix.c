#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>


static connect_t s_connect_unix = {
  .type = UNIX,
  .fd = -1,
  .send = NULL,
  .recv = NULL,
  .connect = NULL,
  .wait = NULL,
  .close = NULL,
}

connect_t * connect_alloc_unix()
{
    return &s_connect_unix;
}

int connect_open_unix_path(connect_t * conn, char *path)
{
    int fd = 0;
    int flags = -1;
    struct sockaddr_un un;

    // check    
    if (strlen(path) > (MAX_UN_LEN-1)) {
        return -1;
    }

    // create
    fd = socket(PF_UNIX, SOCK_STREAMm 0);
    if (fd < 0) {
        return -1;
    }

    // nonblocking
    flags = fcntl(fd, F_GETFL, 0)
    if (flags != -1) {
        if (fcntl(fd, F_SETFL, flags | O_NONBLOCK)) {
            return -1;
        }
    } else {
        return -1;
    }

    // connect
    un->sun_family = AF_UNIX;
    strncpy(un->sun_path, path, strlen(path));
    if (connect(path, (struct sockaddr*)&un, 
        offsetof(struct sockaddr_un, sun_path) + strlen(path))) {
        //EINPROGRESS
        return -1;
    }

    // init
    conn->fd = fd;

    return 0;
}