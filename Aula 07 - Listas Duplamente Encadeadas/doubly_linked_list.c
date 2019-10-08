#include<stdio.h>
#include<stdlib.h>
#include"doubly_linked_list.h"

DoublyList* create_list() {
    DoublyList *L = (DoublyList *) malloc(sizeof(DoublyList));
    L->start = L->last = NULL;
    L->len = 0;
}

int list_insert_begin(DoublyList *L, int v) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (new!=NULL) {        
        new->info = v;        
        if (is_empty(L))
            L->last = new;
        else
            L->start->prev = new;//link new node backward
        /* 
        * As the new node is inserted at the beggening of the list,
        * then its prev will be NULL and it will be the head of the list.
        * In addition, we need to link the new node with the list.
        * To do so, we make the 'next' fild of the new node points to 
        * the head of the list.
        */
        new->next = L->start; //link new node forward
        new->prev = NULL;
        L->start = new;
        L->len++;
        return 1;
    }    
    return 0;
}

int list_insert_end(DoublyList *L, int v) {
    if(is_empty(L))
        return list_insert_begin(L, v);
    Node *new = (Node *) malloc(sizeof(Node));
    if (new!=NULL) {
        new->info = v;
        new->prev = L->last;
        new->next = NULL;
        L->last->next = new;
        L->last = new;
        L->len++;
        return 1;
    }
    return 0;
}

void list_destroy(DoublyList *L) {
    Node *p, *aux;
    p = L->start;
    while (p!=NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);
}

int is_empty(DoublyList *L) {
    return (L->len==0);
}

Node* search(DoublyList *L, int key) {
    for(Node *p = L->start; p!=NULL; p=p->next)
        if (p->info==key)
            return p;
    return NULL;
}

void list_print(DoublyList *L) {
    for(Node *p = L->start; p!=NULL; p=p->next)
        printf("%d ", p->info);
    printf("\n");
}

int list_remove(DoublyList *L, int v) {
    Node *p = search(L, v);
    if (p==NULL)
        return 0;
    if (p==L->start)   
        L->start = p->next;
    else
        p->prev->next = p->next;
    if (p==L->last)    
        L->last = p->prev;
    else
        p->next->prev = p->prev;    
    free(p);
    L->len--;
    return 1;
}