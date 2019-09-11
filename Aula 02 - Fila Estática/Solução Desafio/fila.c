#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

Fila* cria_fila() {
	Fila *f = (Fila*)malloc(sizeof(Fila));
	f->indice_fim = f->indice_inicio = 0;
}
void libera_fila(Fila *f) {
	free(f);
}
int esta_cheia(Fila *f) {
	return (f->indice_fim == MAX);
}
int esta_vazia(Fila *f) {
	return (f->indice_inicio == f->indice_fim);
}
int enfileirar(Fila *f, Nodo valor) {
	if (esta_cheia(f)) {
		printf("Nao foi possivel enfileirar %d. Fila esta cheia!\n", valor);
		return 0;
	}
	f->vet[f->indice_fim++] = valor;
	return 1;
}
int desenfileirar(Fila *f, Nodo* valor) {
	if (esta_vazia(f)) {
		printf("Nao foi possivel desenfileirar. Fila vazia!\n");
		return 0;
	}
	*valor = f->vet[f->indice_inicio++];
	return 1;
}

void imprimir(Fila *f) {
	printf("Imprimindo fila:\n");
	for (int i = f->indice_inicio; i < f->indice_fim; i++) {
		printf("(%d, %d)", f->vet[i].row, f->vet[i].col);
	}
}