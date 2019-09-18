#ifndef _FILA_PRIORIDADES_H_
#define _FILA_PRIORIDADES_H_

#define MAX 100

typedef struct heap {
    int length;
    int heap_size;
    int VET[100];
} Heap;

int parent(int pos);
int left(int pos);
int right(int pos);
Heap *heap_create();
void build_max_heap(Heap *f, int *vet, int len);
void heap_destroy(Heap *f);
void max_heapify(Heap *f, int pos);
int heap_maximum(Heap *f);
int heap_extract_maximum(Heap *f);
int heap_increase_key(Heap *f, int pos, int key);
void heap_insert(Heap *f, int key);

#endif