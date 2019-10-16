#ifndef _DOUBLY_CIRCULAR_LINKED_LIST_H_
#define _DOUBLY_CIRCULAR_LINKED_LIST_H_

typedef struct node {
    int info;
    struct node *next;
    struct node *prev;
}Node;

typedef struct list {
    int len;
    Node *start;
    Node *last;
}DoublyList;

DoublyList* create_list();
int list_insert_begin(DoublyList *L, int v);
int list_insert_end(DoublyList *L, int v);
int is_empty(DoublyList *L);
void list_destroy(DoublyList *L);
Node* search(DoublyList *L, int key);
void list_print(DoublyList *L);
int list_remove(DoublyList *L, int v);

#endif