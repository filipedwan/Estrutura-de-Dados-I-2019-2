#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main() {
    printf("--------------------\n");
    Queue *f = create_queue();
    
    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);
    enqueue(f, 40);
    print_queue(f);
    int x;
    dequeue(f, &x);
    printf("Removed value: %d\n", x);

    printf("Print after deletion:\n");
    print_queue(f);

    destroy_queue(f);
    printf("--------------------\n");
    return 0;
}