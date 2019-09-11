#define MAX 200

typedef struct nodo {
	int row;
	int col;
}Nodo;

typedef struct fila {
	int indice_inicio;
	int indice_fim;
	Nodo vet[MAX];
}Fila;

Fila* cria_fila();
void libera_fila(Fila *f);
int esta_cheia(Fila *f);
int esta_vazia(Fila *f);
int enfileirar(Fila *f, Nodo valor);
int desenfileirar(Fila *f, Nodo* valor);
void imprimir(Fila *f);