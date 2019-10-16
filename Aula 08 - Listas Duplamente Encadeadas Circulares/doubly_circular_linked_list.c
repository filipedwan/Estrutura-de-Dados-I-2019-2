#include<stdio.h>
#include<stdlib.h>
#include"doubly_circular_linked_list.h"

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
            L->last = new->next = new->prev = new;
        else {
            new->next = L->start; //link new node forward
            L->start->prev = new;//link new node backward
            new->prev = L->last;
            L->last->next = new;
        }            
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
        L->last->next = new;
        new->prev = L->last;
        L->start->prev = new;
        new->next = L->start;
        L->last = new;
        L->len++;
        return 1;
    }
    return 0;
}

void list_destroy(DoublyList *L) {
    Node *p, *aux;
    p = L->start;
    for (int i=0; i<L->len; i++) {
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
    Node *p = L->start;
    for(int i =0; i<L->len; i++, p=p->next)
        if (p->info==key)
            return p;
    return NULL;
}

void list_print(DoublyList *L) {
    Node *p = L->start;
    for(int i=0; i<L->len; i++, p=p->next)
        printf("%d ", p->info);
    printf("\n");
}

int list_remove(DoublyList *L, int v) {
    Node *p = search(L, v);
    if (p==NULL)
        return 0;
    if (p==L->start) {
        L->start = p->next;
        //L->last->next = p;
        L->last->next = p->next;
    }
    else
        p->prev->next = p->next;
    if (p==L->last) {
        L->last = p->prev;
        L->start->prev = p->prev;
    }
    else
        p->next->prev = p->prev;    
    free(p);
    L->len--;
    return 1;
}