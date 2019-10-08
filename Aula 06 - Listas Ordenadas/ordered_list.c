#include<stdio.h>
#include<stdlib.h>
#include"ordered_list.h"

List* create_list() {
    List *lista = (List *) malloc(sizeof(List));
    lista->head = NULL;
    lista->len = 0;
    return lista;
}
void list_insert(List *L, int v) {
    //creating and contextualizing Node
    Node *new = (Node*) malloc(sizeof(Node));
    L->len++;
    new->info = v;
    //process of finding position to insert the new node
    Node *ant = NULL;
    Node *p = L->head;
    
    while (p!=NULL && p->info < new->info) {
        ant = p;
        p = p->next;
    }
    if (ant == NULL) //insert new as the first item
        L->head = new;
    else
        ant->next = new;
    new->next = p;
}

int is_empty(List *L) {
    return (L->head == NULL);
}

/*
* nodos_list_destroy não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
void nodos_list_destroy(Node *head) {
    if (head!=NULL) {
        nodos_list_destroy(head->next);
        free(head);
    }
}

void list_destroy(List *L) {
    nodos_list_destroy(L->head);
    free(L);
}

Node* search(List *L, int key) {
    for(Node *p = L->head; p!=NULL; p=p->next)
        if (p->info==key)
            return p;
    return NULL;
}

void list_print(List *L) {
    for(Node *p = L->head; p!=NULL; p=p->next)
        printf("%d ", p->info);
    printf("\n");
}

void list_remove(List *L, int v) {
    Node *p, *ant;
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
