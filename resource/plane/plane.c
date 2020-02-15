#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <sys/queue.h>

#define DEAD_ALIVE (1)

typedef enum PLANE_STATUS_ {
    ALIVE = 1,
    DEAD,

    MAX_PLANE_STATUS
} PLANE_STATUS_T;

typedef enum PLANE_TYPE_ {
    BAD_PLANE = 1,
    SELF_PLANE,
    BALL,

    MAX_PLANE_TYPE
} PLANE_TYPE_T;

typedef void (*print_win_t) (int y, int x);

typedef struct plane_ {
    int type;
    int y;
    int x;
    int alive;
    PLANE_STATUS_T status;
    print_win_t print_win[MAX_PLANE_STATUS];

    LIST_ENTRY(plane_) node;
} plane_t;


LIST_HEAD(listhead_plane_bad, plane_) g_plane_bad = LIST_HEAD_INITIALIZER(head);
LIST_HEAD(listhead_ball, plane_) g_plane_ball = LIST_HEAD_INITIALIZER(head);
plane_t * g_plane_self = NULL;

void plane_bad(int y, int x)
{
    mvaddstr(y,   x, " |._.| ");
    mvaddstr(y+1, x, "-|...|-");
    mvaddstr(y+2, x, "  |.|  ");
    mvaddstr(y+3, x, "   V   ");
}


void plane_self(int y, int x)
{
    mvaddstr(y,   x, "   ^   ");
    mvaddstr(y+1, x, "  .H.  ");
    mvaddstr(y+2, x, ".--+--.");
    mvaddstr(y+3, x, "  |^|  ");
}

void plane_boom(int y, int x)
{
    mvaddstr(y,   x, ".     .");
    mvaddstr(y+1, x, " ..#.. ");
    mvaddstr(y+2, x, " ..#.. ");
    mvaddstr(y+3, x, ".     .");   
}

void plane_ball(int y, int x)
{
    mvaddstr(y, x, ".");
}

void new_box(int y, int x, int y_len, int x_len)
{
    int i = 0;
    for ( ; i < x_len; i++) {
	mvaddch(y, x+i, '*');
    }

    for (i = 0; i < y_len; i++) {
	mvaddch(y+i, x, '*');
    }

    for (i = 0; i < y_len; i++) {
	mvaddch(y+i, x+x_len-1, '*');
    }

    for (i = 0; i < x_len; i++) {
	mvaddch(y+y_len, x+i, '*');
    }
}

plane_t * alloc_plane(int y, int x, PLANE_TYPE_T type)
{
    plane_t *plane = (plane_t*)malloc(sizeof(plane_t));
    if (plane == NULL) {
        return NULL;
    }

    plane->type = type;
    plane->y = y;
    plane->x = x;
    plane->status = ALIVE;

    if (type == BAD_PLANE) {
        plane->print_win[ALIVE] = plane_bad;
    } else if (type == SELF_PLANE) {
        plane->print_win[ALIVE] = plane_self;
    } else if (type == BALL) {
        plane->print_win[ALIVE] = plane_ball;
    }
    plane->print_win[DEAD] = plane_boom;

    return plane;
}

void delete_plane(plane_t * plane)
{
    LIST_REMOVE(plane, node);
    free(plane);
}

void add_plane(plane_t * plane)
{
    LIST_INSERT_HEAD(&g_plane_bad, plane, node);
}

int get_char()
{
    fd_set rfds;
    struct timeval tv;
    int ch = 0;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 0;
    tv.tv_usec = 0; //设置等待超时时间

    //检测键盘是否有输入
    if (select(1, &rfds, NULL, NULL, &tv) > 0)
    {
        ch = getch(); 
    }

    return ch;
}

int is_hit(int y, int x, plane_t * plane)
{
    if (x >= plane->x && x <= plane->x+7
        && y >= plane->y && y <= plane->y+4) {
        return 1;
    }

    return 0;
}

void new_plane_bad()
{
    int y = 2;
    int x = random()%COLS - 7;

    plane_t * plane = alloc_plane(y, x, BAD_PLANE);
    if (plane != NULL) {
        add_plane(plane);
    }
}

void out_plane_bad()
{
    plane_t * p = NULL;
    plane_t * p_tmp = NULL;
    LIST_FOREACH_SAFE(p, &g_plane_bad, node, p_tmp) {
        p->print_win[p->type](p->y, p->x);
        if (p->type == DEAD) {
            p->alive--;
            if (p->alive == 0) {
                delete_plane(p);    
            }
        }
    }
}

void update_plane_bad()
{
    plane_t * p = NULL;
    plane_t * p_tmp = NULL;
    LIST_FOREACH_SAFE(p, &g_plane_bad, node, p_tmp) {
        p->y++;

        if (p->y == LINES) {
            delete_plane(p);
            continue;
        }

        if (p->type == DEAD) {
            p->y--;
        }
    }
}

int ball_plane_dead(plane_t * plane)
{
    plane_t * p = NULL;
    plane_t * p_tmp = NULL;
    LIST_FOREACH_SAFE(p, &g_plane_ball, node, p_tmp) {
        if (   is_hit(p->y, p->x, plane)
            || is_hit(p->y+4, p->x, plane)
            || is_hit(p->y, p->x+7, plane)
            || is_hit(p->y+4, p->x+7, plane)) {
            return 1;
        }
    }

    return 0;
}

void check_plane_dead()
{
    plane_t * p = NULL;
    plane_t * p_tmp = NULL;
    LIST_FOREACH_SAFE(p, &g_plane_bad, node, p_tmp) {
        if (   is_hit(p->y, p->x, g_plane_self)
            || is_hit(p->y+4, p->x, g_plane_self)
            || is_hit(p->y, p->x+7, g_plane_self)
            || is_hit(p->y+4, p->x+7, g_plane_self)
            || ball_plane_dead(p)) {

            p->alive = DEAD_ALIVE;
            p->type = DEAD;
            continue;
        }
    }
}

void new_ball()
{
    plane_t * ball = alloc_plane(g_plane_self->y, g_plane_self->x+3, BALL);
    if (ball) {
        LIST_INSERT_HEAD(&g_plane_ball, ball, node);
    }
}

void update_ball()
{
    plane_t * p = NULL;
    plane_t * p_tmp = NULL;
    LIST_FOREACH_SAFE(p, &g_plane_ball, node, p_tmp) {
        p->y--;
        if (p->y == 1) {
            delete_plane(p);
            continue;
        }
    }
}

void out_ball()
{
    plane_t * p = NULL;
    plane_t * p_tmp = NULL;
    LIST_FOREACH_SAFE(p, &g_plane_ball, node, p_tmp) {
        p->print_win[ALIVE](p->y, p->x);
    }   
}

int main(int argc, char *argv[])
{
    int LEVEL = atoi(argv[1]);

    WINDOW * main_win = NULL;
    main_win = initscr();

    int ch = 0;
    int main_win_y = 1;
    int main_win_x = 0;
    int main_win_y_len = LINES-2;
    int main_win_x_len = COLS;

    cbreak();
    nonl();
    noecho();
    intrflush(main_win, false);
    keypad(main_win, true);

    g_plane_self = alloc_plane(LINES-5, 1, SELF_PLANE);
    // init
    new_plane_bad();

    int _x = LEVEL;
    while (1) {
        clear();
        printw("round:%d y:%d x:%d\n", _x, g_plane_self->y, g_plane_self->x);
        

        // contorl
        ch = get_char();
        switch (ch) {
            case KEY_UP:
                g_plane_self->y--;
                if (g_plane_self->y == 1) {
                    g_plane_self->y++;
                }
                break;
            case KEY_DOWN:
                g_plane_self->y++;
                if (g_plane_self->y == LINES-4) {
                    g_plane_self->y--;
                }
                break;
            case KEY_LEFT:
                g_plane_self->x--;
                if (g_plane_self->x == 0) {
                    g_plane_self->x++;
                }
                break;
            case KEY_RIGHT:
                g_plane_self->x++;
                if (g_plane_self->x == COLS-7) {
                    g_plane_self->x--;
                }
                break;
            default:
                break;
        }
        
        // new bad plane
        if (_x == LEVEL * 5) {
            new_plane_bad();
            _x = 0;
        }

        // new ball
        if (_x%100 == 0) {
            new_ball();
            update_ball();
        }

        // updata bad plane
        if (_x%LEVEL == 0) {
            update_plane_bad();
        }

        // check dead
        check_plane_dead();

        // out bad plane
        out_plane_bad();

        // out ball
        out_ball();

        // out sel plane
        g_plane_self->print_win[ALIVE](g_plane_self->y, g_plane_self->x);


        new_box(main_win_y, main_win_x, main_win_y_len, main_win_x_len);
        move(0, 0);
        refresh();
        _x++;
    }

    endwin();
    return 0;
}

