#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct list
{
    struct list *prev;
    struct list *next;
};

struct node
{
    int data;
    struct list head;
};

#define list_entry(ptr, type, member)  ({       \
        const typeof(((type *)0)->member) *_mptr = (ptr);   \
        (type *)( (char *)_mptr - offsetof(type, member));})

void list_init(struct list *head)
{
    head->prev = head;
    head->next = head;
}

void list_insert(struct list *head, struct list *in)
{
    in->next = head->next;
    head->next->prev = in;
    head->next = in;
    in->prev = head;
}

void list_del(struct list *in)
{
    in->next->prev = in->prev;
    in->prev->next = in->next;
}

void list_print(struct list *head)
{
    struct list *cur = head;
    while (cur->next != head)
    {
        cur = cur->next;
        printf("%d ", list_entry(cur, struct node, head)->data);
    }

    printf("\n");
}

struct node* create_node(int val)
{
    struct node *nd = malloc(sizeof(struct node));
    nd->data = val;
    list_init(&nd->head);
    return nd;
}

void free_node(struct list *head)
{
    free(list_entry(head, struct node, head));
}

int main()
{
    struct list head;
    list_init(&head);
    struct node *nd;
    struct list *cur;
    const int num = 10;
    for (int i = 0; i < num; ++i)
    {
        nd = create_node(i+1);
        list_insert(&head, &nd->head);
    }

    list_print(&head);

    for (int i = 0; i < num/2; ++i)
    {
        cur = head.next;
        list_del(head.next);
        free_node(cur);
        list_print(&head);

        cur = head.prev;
        list_del(head.prev);
        free_node(cur);
        list_print(&head);
    }

    return 0;
}
