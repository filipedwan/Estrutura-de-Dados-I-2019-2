#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

Pilha *cria_pilha() {
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->topo = 0;
	return p;
}
void libera_pilha(Pilha *p) {
	free(p);
}
int push(Pilha *p, int valor) {
	if (!esta_cheia(p)) {
		p->vet[p->topo++] = valor;
		return 1;
	}
	return 0;
}

int pop(Pilha *p, int *valor) {
	if (!esta_vazia(p)) {
		*valor = p->vet[--p->topo];
		return 1;
	}
	return 0;
}
int get_tamanho(Pilha *p) {
	return p->topo;
}
int esta_vazia(Pilha *p) {
	return (p->topo == 0);
}
int esta_cheia(Pilha *p) {
	return (p->topo == MAX);
}