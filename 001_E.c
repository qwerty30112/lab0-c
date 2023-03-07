# 1 "001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "001.c"




# 1 "queue.h" 1
# 10 "queue.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stdbool.h" 1 3 4
# 11 "queue.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 1 3 4
# 143 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 3 4

# 143 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 209 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 321 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 3 4
typedef int wchar_t;
# 415 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 426 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 3 4
} max_align_t;
# 12 "queue.h" 2

# 1 "harness.h" 1



# 1 "/usr/include/setjmp.h" 1 3 4
# 25 "/usr/include/setjmp.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 461 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 452 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 453 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 454 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 462 "/usr/include/features.h" 2 3 4
# 485 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 486 "/usr/include/features.h" 2 3 4
# 26 "/usr/include/setjmp.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/setjmp.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/setjmp.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/setjmp.h" 2 3 4




typedef long int __jmp_buf[8];
# 30 "/usr/include/setjmp.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 1 3 4




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 31 "/usr/include/setjmp.h" 2 3 4


struct __jmp_buf_tag
  {




    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };


typedef struct __jmp_buf_tag jmp_buf[1];



extern int setjmp (jmp_buf __env) __attribute__ ((__nothrow__));




extern int __sigsetjmp (struct __jmp_buf_tag __env[1], int __savemask) __attribute__ ((__nothrow__));



extern int _setjmp (struct __jmp_buf_tag __env[1]) __attribute__ ((__nothrow__));
# 67 "/usr/include/setjmp.h" 3 4
extern void longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));





extern void _longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));







typedef struct __jmp_buf_tag sigjmp_buf[1];
# 93 "/usr/include/setjmp.h" 3 4
extern void siglongjmp (sigjmp_buf __env, int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
# 103 "/usr/include/setjmp.h" 3 4

# 5 "harness.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 99 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 6 "harness.h" 2








# 13 "harness.h"
void *test_malloc(size_t size);
void *test_calloc(size_t nmemb, size_t size);
void test_free(void *p);
char *test_strdup(const char *s);
# 14 "queue.h" 2
# 1 "list.h" 1


       





# 1 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 1 3 4
# 10 "list.h" 2
# 35 "list.h"
struct list_head {
    struct list_head *prev;
    struct list_head *next;
};
# 82 "list.h"
static inline void INIT_LIST_HEAD(struct list_head *head)
{
    head->next = head;
    head->prev = head;
}






static inline void list_add(struct list_head *node, struct list_head *head)
{
    struct list_head *next = head->next;

    next->prev = node;
    node->next = next;
    node->prev = head;
    head->next = node;
}






static inline void list_add_tail(struct list_head *node, struct list_head *head)
{
    struct list_head *prev = head->prev;

    prev->next = node;
    node->next = head;
    node->prev = prev;
    head->prev = node;
}
# 134 "list.h"
static inline void list_del(struct list_head *node)
{
    struct list_head *next = node->next;
    struct list_head *prev = node->prev;

    next->prev = prev;
    prev->next = next;





}
# 155 "list.h"
static inline void list_del_init(struct list_head *node)
{
    list_del(node);
    INIT_LIST_HEAD(node);
}







static inline int list_empty(const struct list_head *head)
{
    return (head->next == head);
}







static inline int list_is_singular(const struct list_head *head)
{
    return (!list_empty(head) && head->prev == head->next);
}
# 193 "list.h"
static inline void list_splice(struct list_head *list, struct list_head *head)
{
    struct list_head *head_first = head->next;
    struct list_head *list_first = list->next;
    struct list_head *list_last = list->prev;

    if (list_empty(list))
        return;

    head->next = list_first;
    list_first->prev = head;

    list_last->next = head_first;
    head_first->prev = list_last;
}
# 219 "list.h"
static inline void list_splice_tail(struct list_head *list,
                                    struct list_head *head)
{
    struct list_head *head_last = head->prev;
    struct list_head *list_first = list->next;
    struct list_head *list_last = list->prev;

    if (list_empty(list))
        return;

    head->prev = list_last;
    list_last->next = head;

    list_first->prev = head_last;
    head_last->next = list_first;
}
# 248 "list.h"
static inline void list_splice_init(struct list_head *list,
                                    struct list_head *head)
{
    list_splice(list, head);
    INIT_LIST_HEAD(list);
}
# 267 "list.h"
static inline void list_splice_tail_init(struct list_head *list,
                                         struct list_head *head)
{
    list_splice_tail(list, head);
    INIT_LIST_HEAD(list);
}
# 286 "list.h"
static inline void list_cut_position(struct list_head *head_to,
                                     struct list_head *head_from,
                                     struct list_head *node)
{
    struct list_head *head_from_first = head_from->next;

    if (list_empty(head_from))
        return;

    if (head_from == node) {
        INIT_LIST_HEAD(head_to);
        return;
    }

    head_from->next = node->next;
    head_from->next->prev = head_from;

    head_to->prev = node;
    node->next = head_to;
    head_to->next = head_from_first;
    head_to->next->prev = head_to;
}
# 317 "list.h"
static inline void list_move(struct list_head *node, struct list_head *head)
{
    list_del(node);
    list_add(node, head);
}
# 330 "list.h"
static inline void list_move_tail(struct list_head *node,
                                  struct list_head *head)
{
    list_del(node);
    list_add_tail(node, head);
}
# 15 "queue.h" 2
# 23 "queue.h"
typedef struct {
    char *value;
    struct list_head list;
} element_t;
# 35 "queue.h"
typedef struct {
    struct list_head *q;
    struct list_head chain;
    int size;
    int id;
} queue_contex_t;
# 49 "queue.h"
struct list_head *q_new();





void q_free(struct list_head *head);
# 67 "queue.h"

# 67 "queue.h" 3 4
_Bool 
# 67 "queue.h"
    q_insert_head(struct list_head *head, char *s);
# 79 "queue.h"

# 79 "queue.h" 3 4
_Bool 
# 79 "queue.h"
    q_insert_tail(struct list_head *head, char *s);
# 99 "queue.h"
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize);
# 109 "queue.h"
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize);







static inline void q_release_element(element_t *e)
{
    test_free(e->value);
    test_free(e);
}







int q_size(struct list_head *head);
# 144 "queue.h"

# 144 "queue.h" 3 4
_Bool 
# 144 "queue.h"
    q_delete_mid(struct list_head *head);
# 156 "queue.h"

# 156 "queue.h" 3 4
_Bool 
# 156 "queue.h"
    q_delete_dup(struct list_head *head);
# 165 "queue.h"
void q_swap(struct list_head *head);
# 176 "queue.h"
void q_reverse(struct list_head *head);
# 191 "queue.h"
void q_reverseK(struct list_head *head, int k);
# 200 "queue.h"
void q_sort(struct list_head *head);
# 215 "queue.h"
int q_descend(struct list_head *head);
# 234 "queue.h"
int q_merge(struct list_head *head);
# 6 "001.c" 2
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


    const struct Node *ptr = __extension__({ const __typeof__(((struct Node *) 0)->list) *__pmember = (&a->list); (struct Node *) ((char *) __pmember - 
# 19 "001.c" 3 4
                            __builtin_offsetof (
# 19 "001.c"
                            struct Node
# 19 "001.c" 3 4
                            , 
# 19 "001.c"
                            list
# 19 "001.c" 3 4
                            )
# 19 "001.c"
                            ); });

    for (li = (head)->next; li != (head); li = li->next) {
        len++;
    }
}
