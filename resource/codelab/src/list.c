// man LIST_HEAD

#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

typedef struct entry_
{
    int val;

    LIST_ENTRY(entry_) node;
}entry_t;

int main()
{
    LIST_HEAD(listhead, entry_) head = LIST_HEAD_INITIALIZER(head);


    entry_t entry1;
    entry1.val = 1;
    LIST_INSERT_HEAD(&head, &entry1, node);

    entry_t entry2;
    entry2.val = 2;
    LIST_INSERT_HEAD(&head, &entry2, node);


    entry_t entry3;
    entry3.val = 3;
    LIST_INSERT_HEAD(&head, &entry3, node);



    entry_t * p = NULL;
    entry_t * p_tmp = NULL;

    LIST_FOREACH(p, &head, node) {
        printf("%d\n", p->val);
    }

    LIST_FOREACH_SAFE(p, &head, node, p_tmp) {
        printf("%d\n", p->val);
        LIST_REMOVE(p, node);
    }

    LIST_INSERT_HEAD(&head, &entry3, node);

    LIST_FOREACH(p, &head, node) {
        printf("%d\n", p->val);
    }

    return 0;
}