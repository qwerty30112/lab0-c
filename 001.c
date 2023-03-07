//
// Created by air on 2023/3/1.
//

#include "queue.h"
typedef struct list_head list_head;
typedef struct Node{
    char *x;
    list_head list;
} my_data;
void a001(struct list_head *head)
{
    int len = 0;
    struct list_head *li;

    my_data *a;

    //const my_data *ptr= list_entry(a,struct Node,list);
    const struct Node *ptr = list_entry(&a->list, struct Node, list);

    list_for_each (li, head) {
        len++;
    }
}