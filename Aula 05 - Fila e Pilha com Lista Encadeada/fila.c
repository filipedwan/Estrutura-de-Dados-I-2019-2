#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

Queue* create_queue() {
    Queue *f = (Queue *) malloc(sizeof(Queue));
    f->start = f->end = NULL;
    f->len = 0;
    return f;
}
void destroy_queue(Queue *f) {
    Node *ant, *p;
    p = f->start;
    while (p!=NULL) {
        ant = p;
        p = p->next;
        free(ant);
    }
    free(f);
}
void print_queue(Queue *f) {
    for (Node *p=f->start; p!=NULL;p=p->next)
        printf("%d ", p->info);
    printf("\n");
}

int is_empty(Queue *f) {
    return (f->len == 0);
}

/*
For the sake of simplicity, in the following function 
I'm not ckecking whether the allocation of the 
node is successful. If you want to do that, just check
if the new node is not equal to NULL. Is so, you can proceed 
with  the insertion process.
*/
void enqueue(Queue *f, int v) {
    Node *new = (Node *) malloc(sizeof(Node));
    new->info = v;
    new->next = NULL;//as it is a queue, the node is always inserted in the end.

    if (is_empty(f))
        f->start = new;
    else
        f->end->next = new;
    
    f->end = new;//update the end with the new node
    f->len++;
}

int dequeue(Queue *f, int *v) {
    if (!is_empty(f)) {
        Node *aux = f->start;
        *v = aux->info;
        if (f->len==1)//only um element within the queue
            f->start = f->end = NULL;
        else            
            f->start = f->start->next;                 
        free(aux);
        f->len--;
        return 1;
    }
    return 0;
}