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

/*
* list_destroy_iterativo não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
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

/*
* nodos_list_destroy não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
void nodos_list_destroy(Nodo *head) {
    if (head!=NULL) {
        nodos_list_destroy(head->next);
        free(head);
    }
}

void list_destroy(List *L) {
    nodos_list_destroy(L->head);
    free(L);
}

Nodo* search(List *L, int key) {
    for(Nodo *p = L->head; p!=NULL; p=p->next)
        if (p->info==key)
            return p;
    return NULL;
}

/*
* search_nodo não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
Nodo* search_nodo(Nodo* head, int key) {
    if (head==NULL)
        return head;
    if (head->info==key)
        return head;
    search_nodo(head->next, key);
}

/*
* search_recursivo não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
Nodo* search_recursivo(List *L, int key) {
    return search_nodo(L->head, key);
}

void list_print(List *L) {
    for(Nodo *p = L->head; p!=NULL; p=p->next)
        printf("%d ", p->info);
    printf("\n");
}

void list_remove(List *L, int v) {
    Nodo *p, *ant;
    p = L->head;
    ant = NULL;
    while (p!=NULL && p->info!=v) {
        ant = p;
        p = p->next;
    }
    if (p==NULL)//node not found
        return;
    if (ant==NULL) //v was found and it is the first node of the list
        L->head = p->next;
    else//v was found and it is not the first node of the list
        ant->next = p->next;
    L->len--;
    free(p);
}

/*
* remove_recursive não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
int removed = 0;//if removed==1 then decrement the lenght of the list
Nodo * remove_recursive(Nodo *head, int v) {
    Nodo *aux;
    if (head!=NULL) {
        if (head->info==v) {
            aux = head;
            head = head->next;
            free(aux);
            removed = 1;
            }
        else 
            head->next = remove_recursive(head->next, v);
    }
    return head;
}

/*
* list_remove_recursive não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
void list_remove_recursive(List *L, int v) {
    L->head = remove_recursive(L->head, v);
    if (removed)
        L->len--;
}
