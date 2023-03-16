# 1 "001.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 400 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "001.c" 2




# 1 "./queue.h" 1
# 10 "./queue.h"
# 1 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stdbool.h" 1 3
# 11 "./queue.h" 2
# 1 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stddef.h" 1 3
# 35 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stddef.h" 3
typedef long int ptrdiff_t;
# 46 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stddef.h" 3
typedef long unsigned int size_t;
# 74 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stddef.h" 3
typedef int wchar_t;
# 102 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stddef.h" 3
# 1 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/__stddef_max_align_t.h" 1 3
# 16 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/__stddef_max_align_t.h" 3
typedef long double max_align_t;
# 103 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stddef.h" 2 3
# 12 "./queue.h" 2

# 1 "./harness.h" 1



# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/setjmp.h" 1 3 4
# 26 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/setjmp.h" 3 4
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 1 3 4
# 666 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 3 4
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h" 1 3 4
# 667 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2 3 4
# 732 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 3 4
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h" 1 3 4
# 733 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2 3 4
# 27 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/setjmp.h" 2 3 4
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 1 3 4
# 165 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 3 4
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h" 1 3 4
# 166 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 2 3 4
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h" 1 3 4
# 167 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 2 3 4
# 28 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/setjmp.h" 2 3 4
# 79 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/setjmp.h" 3 4
typedef int jmp_buf[((14 + 8 + 2) * 2)];
typedef int sigjmp_buf[((14 + 8 + 2) * 2) + 1];






extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int) __attribute__((__noreturn__));


int _setjmp(jmp_buf);
void _longjmp(jmp_buf, int) __attribute__((__noreturn__));
int sigsetjmp(sigjmp_buf, int);
void siglongjmp(sigjmp_buf, int) __attribute__((__noreturn__));



void longjmperror(void);
# 5 "./harness.h" 2
# 1 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stdarg.h" 1 3
# 14 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stdarg.h" 3
typedef __builtin_va_list va_list;
# 32 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 6 "./harness.h" 2







void *test_malloc(size_t size);
void *test_calloc(size_t nmemb, size_t size);
void test_free(void *p);
char *test_strdup(const char *s);
# 14 "./queue.h" 2
# 1 "./list.h" 1








# 1 "/Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include/stddef.h" 1 3
# 10 "./list.h" 2
# 35 "./list.h"
struct list_head {
    struct list_head *prev;
    struct list_head *next;
};
# 82 "./list.h"
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
# 134 "./list.h"
static inline void list_del(struct list_head *node)
{
    struct list_head *next = node->next;
    struct list_head *prev = node->prev;

    next->prev = prev;
    prev->next = next;





}
# 155 "./list.h"
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
# 193 "./list.h"
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
# 219 "./list.h"
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
# 248 "./list.h"
static inline void list_splice_init(struct list_head *list,
                                    struct list_head *head)
{
    list_splice(list, head);
    INIT_LIST_HEAD(list);
}
# 267 "./list.h"
static inline void list_splice_tail_init(struct list_head *list,
                                         struct list_head *head)
{
    list_splice_tail(list, head);
    INIT_LIST_HEAD(list);
}
# 286 "./list.h"
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
# 317 "./list.h"
static inline void list_move(struct list_head *node, struct list_head *head)
{
    list_del(node);
    list_add(node, head);
}
# 330 "./list.h"
static inline void list_move_tail(struct list_head *node,
                                  struct list_head *head)
{
    list_del(node);
    list_add_tail(node, head);
}
# 15 "./queue.h" 2








typedef struct {
    char *value;
    struct list_head list;
} element_t;
# 35 "./queue.h"
typedef struct {
    struct list_head *q;
    struct list_head chain;
    int size;
    int id;
} queue_contex_t;
# 49 "./queue.h"
struct list_head *q_new();





void q_free(struct list_head *head);
# 67 "./queue.h"
_Bool q_insert_head(struct list_head *head, char *s);
# 79 "./queue.h"
_Bool q_insert_tail(struct list_head *head, char *s);
# 99 "./queue.h"
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize);
# 109 "./queue.h"
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize);







static inline void q_release_element(element_t *e)
{
    test_free(e->value);
    test_free(e);
}







int q_size(struct list_head *head);
# 144 "./queue.h"
_Bool q_delete_mid(struct list_head *head);
# 156 "./queue.h"
_Bool q_delete_dup(struct list_head *head);
# 165 "./queue.h"
void q_swap(struct list_head *head);
# 176 "./queue.h"
void q_reverse(struct list_head *head);
# 191 "./queue.h"
void q_reverseK(struct list_head *head, int k);
# 200 "./queue.h"
void q_sort(struct list_head *head);
# 215 "./queue.h"
int q_descend(struct list_head *head);
# 234 "./queue.h"
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

    element_t *element=__extension__({ const __typeof__(((element_t *) 0)->list) *__pmember = ((head)->next); (element_t *) ((char *) __pmember - __builtin_offsetof(element_t, list)); });
    element->list.next;


    const struct Node *ptr = __extension__({ const __typeof__(((struct Node *) 0)->list) *__pmember = (&a->list); (struct Node *) ((char *) __pmember - __builtin_offsetof(struct Node, list)); });

    for (li = (head)->next; li != (head); li = li->next) {
        len++;
    }
}
