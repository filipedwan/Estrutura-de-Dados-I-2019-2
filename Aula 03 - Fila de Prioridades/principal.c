#include<stdio.h>
#include<stdlib.h>
#include"fila_prioridades.h"

int main() {
    Heap* f = heap_create();

    int vet[] = {10, 40, 20, 15, 17, 2, 81};

    build_max_heap(f, vet, 7);
    printf("Max value: %d\n", heap_extract_maximum(f));

    printf("New Max value after extracting previus maximum: %d\n", heap_maximum(f));

    printf("\n-------------------\n");
    heap_increase_key(f, 3, 35);
    printf("Imprimindo VET do Heap\n");
    for(int i = 0; i<f->heap_size; i++)
        printf("%d ", f->VET[i]);
    printf("\n");
    printf("-------------------\n");

    heap_insert(f, 100);

    printf("New Max value after insertion: %d\n", heap_maximum(f));

    heap_destroy(f);
    return 0;
}