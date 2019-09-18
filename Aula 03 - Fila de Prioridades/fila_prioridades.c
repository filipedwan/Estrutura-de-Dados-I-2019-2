#include<stdio.h>
#include<stdlib.h>
#include"fila_prioridades.h"

int parent(int pos) {
    return (pos-1)/2;
}

int left(int pos) {
    return (pos*2 + 1);
}

int right(int pos) {
    return (pos*2 + 2);
}

Heap *heap_create() {
    Heap *f = (Heap *) malloc(sizeof(Heap));
    f->length = 0;
    f->heap_size = 0;
}

void build_max_heap(Heap *f, int *vet, int len) {
    f->length = f->heap_size = len;
    for (int i=0; i<len; i++)
        f->VET[i] = vet[i];

    for (int i=len/2; i>=0; i--) {
        max_heapify(f, i);
    }
}

void heap_destroy(Heap *f) {
    free(f);
}

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void max_heapify(Heap *f, int pos) {
    int l, r, largest;
    l = left(pos);
    r = right(pos);
    largest = pos;
    
    if ((l<f->heap_size) && (f->VET[largest] < f->VET[l]))
        largest = l;
    if ((r<f->heap_size) && (f->VET[largest] < f->VET[r]))
        largest = r;
    if (pos != largest) {
        troca(&f->VET[pos], &f->VET[largest]);
        max_heapify(f, largest);
    }
}

int heap_maximum(Heap *f) {
    if (f->heap_size > 0)
        return f->VET[0];
    return -1;//Código perigoso - deveria ser lançado um erro aqui
}

int heap_extract_maximum(Heap *f) {
    if (f->heap_size < 1)
        return -1;//Código perigoso - deveria ser lançado um erro aqui
    int max = f->VET[0];
    f->VET[0] = f->VET[f->heap_size-1];
    f->heap_size--;
    max_heapify(f, 0);
    return max;
}

int heap_increase_key(Heap *f, int pos, int key) {
    if (key < f->VET[pos])
        return -1;//Código perigoso - deveria ser lançado um erro aqui
    f->VET[pos] = key;
    while (pos>=0 && f->VET[parent(pos)] < f->VET[pos]) {
        troca(&f->VET[parent(pos)], &f->VET[pos]);
        pos = parent(pos);
    }
}

void heap_insert(Heap *f, int key) {
    if (f->heap_size <= MAX) {
        f->VET[f->heap_size] = -10000;
        f->heap_size++;
        heap_increase_key(f, f->heap_size-1, key);
    }
}
