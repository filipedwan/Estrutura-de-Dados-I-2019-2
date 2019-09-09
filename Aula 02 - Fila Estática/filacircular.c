#include <stdio.h>
#include <stdlib.h>
#include "filacircular.h"

Fila * criaFila() {
	Fila * f = (Fila *) malloc(sizeof(Fila));
	f->tamanho = f->fim = f->inicio = 0;
	return f;
}

int estaVazia(Fila* f) {
	return (f->tamanho == 0);
}

int estaCheia(Fila* f) {
	return (f->tamanho == MAX);
}

void enqueue(Fila* f, int valor) {
	if (!estaCheia(f)) {
		f->vet[f->fim++] = valor;
		if (f->fim == MAX) {
			f->fim = 0;
		}
		f->tamanho++;
	}
	else printf("A fila esta cheia\n");
}

int dequeue(Fila* f) {
	if (!estaVazia(f)) {
		int aux = f->vet[f->inicio++];
		if (f->inicio == MAX)
			f->inicio = 0;
		f->tamanho--;
		return aux;
	}
	else {
		printf("A fila esta vazia\n");
		return 0;
	}
}

void libera(Fila *f) {
	free(f);
	f = NULL;
}

void imprimeFila(Fila *f) {
	int i = f->inicio;
	int cont = 0;

	while (cont < f->tamanho) {
		printf("%d ", f->vet[i++]);
		if (i == MAX) i = 0;
		cont++;
	}
}
