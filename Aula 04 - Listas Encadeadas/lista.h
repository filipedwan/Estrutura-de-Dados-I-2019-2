#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct nodo {
    int info;
    struct nodo *next;
}Nodo;

typedef struct list {
    Nodo *head;
    int len;
}List;

List* create_list();
void list_insert(List *L, int v);
int is_empty(List *L);
void list_destroy(List *L);
Nodo* search(List *L, int key);
void list_print(List *L);
void list_remove(List *L, int v);

#endif