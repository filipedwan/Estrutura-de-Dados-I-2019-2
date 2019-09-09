#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila * criaFila() {
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->inicio = 0;
	f->fim = 0;
	return f;
}

int estaVazia(Fila* f) {
	return (f->fim == 0);
}

int estaCheia(Fila* f) {
	return (f->fim == MAX);
}

void enqueue(Fila* f, int valor) {
	if (!estaCheia(f))
		f->vet[f->fim++] = valor;
	else printf("A fila esta cheia\n");
}

int dequeue(Fila* f) {
	if (!estaVazia(f))
		return f->vet[f->inicio++];
	else {
		printf("A fila esta vazia\n");
		return 0;
	}
}

void libera(Fila *f) {
	free(f);
}

void imprimeFila(Fila *f) {
	for (int i = f->inicio; i < f->fim; i++)
		printf("%d ", f->vet[i]);
	printf("\n");
}