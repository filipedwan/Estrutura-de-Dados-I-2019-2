#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

List* create_list() {
    List *lista = (List *) malloc(sizeof(List));
    lista->head = NULL;
    lista->len = 0;
    return lista;
}
void list_insert(List *L, int v) {
    Nodo *new = (Nodo*) malloc(sizeof(Nodo));
    L->len++;
    new->info = v;
    new->next = L->head;
    L->head = new;
}

int is_empty(List *L) {
    return (L->head == NULL);
}

void nodos_list_destroy(Nodo *head) {
    if (head!=NULL) {
        nodos_list_destroy(head->next);
        free(head);
    }
}

void list_destroy_iterativo(List *L) {
    Nodo *p, *ant;
    p = L->head;
    while (p!=NULL) {
        ant = p;
        p = p->next;
        free(ant);
    }
    free(L);
}

void list_destroy(List *L) {
    nodos_list_destroy(L->head);
    free(L);
}

Nodo* search(List *L, int key);
void list_print(List *L);
void list_remove(List *L, int v);
