#ifndef _FILA_H_
#define _FILA_H_

typedef struct node {
    struct node * next;
    int info;
}Node;

typedef struct fila{
    Node *start;
    Node *end;
    int len;
}Queue;

Queue *create_queue();
void destroy_queue(Queue *f);
void print_queue(Queue *f);
int is_empty(Queue *f);
void enqueue(Queue * f, int v);
int dequeue(Queue *f, int *v);

#endif