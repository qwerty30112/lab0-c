#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Notice: sometimes, Cppcheck would find the potential NULL pointer bugs,
 * but some of them cannot occur. You can suppress them by adding the
 * following line.
 *   cppcheck-suppress nullPointer
 */

typedef struct list_head list_head;



/* Create an empty queue */
struct list_head *q_new()
{
    list_head *head= malloc(sizeof (list_head));
    head->next=head->prev=head;
    return head;
}

/* Free all storage used by queue */
void q_free(struct list_head *l) {}

/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    if(head==NULL) return false;
    element_t *node= malloc(sizeof (element_t));
    node->value= strdup(s);
    if(head->next==head){
        head->next=head->prev=&node->list;
        node->list.next=node->list.prev=head;
    }else{
        list_head *next=head->next;
        head->next=&node->list;
        next->prev=&node->list;
        node->list.next=next;
        node->list.prev=head;

    }
    return true;
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    if(head==NULL) return false;
    int len= strlen(s);
    element_t *node= malloc(sizeof (element_t));
    node->value= malloc(len+1);
    strcpy(node->value,s);
    node->list.next=head;
    list_head *pre=head->prev;
    head->prev=&node->list;
    if(head->next==head){
        head->next=&node->list;
        node->list.prev=head;
    }else{
        pre->next=&node->list;
        node->list.prev=pre;
    }
    return true;
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{

    if(head==NULL && head->next==head) return NULL;
    long offset=(long)&((element_t*)0)->list;
    element_t *node=(element_t*)((char*)(head->next)-offset);
//    element_t *element=__extension__({
//        const __typeof__(((element_t *) 0)->list) *__pmember = ((head)->next);
//        (element_t *) ((char *) __pmember - __builtin_offsetof(element_t, list));
//    });
//    printf("%p\n",element);
    //list_del(&node->list);
    if(node->list.next==head){
        head->next=head->prev=head;
    }else{
        head->next=node->list.next;
        list_head *next=node->list.next;
        next->prev=head;
    }
    if(sp==NULL || bufsize==0) return node;
    strncpy(sp,node->value,bufsize);
    sp[bufsize-1]=0;
    //return NULL;
    return node;
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    return NULL;
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    if (!head)
        return 0;

    int len = 0;
    struct list_head *li;

    list_for_each (li, head){
        len++;
    }
    return len;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending order */
void q_sort(struct list_head *head) {}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending order */
int q_merge(struct list_head *head)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
