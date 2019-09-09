#ifndef _PILHA_H_
#define _PILHA_H_
#define MAX 100

typedef struct pilha {
	int topo;
	int vet[MAX];
}Pilha;

Pilha *cria_pilha();
void libera_pilha(Pilha *p);
int push(Pilha *p, int valor);
int pop(Pilha *p, int *valor);
int get_tamanho(Pilha *p);
int esta_vazia(Pilha *p);
int esta_cheia(Pilha *p);

#endif