#define MAX 10

typedef struct fila {
	int vet[MAX];
	int inicio;
	int fim;
}Fila;

Fila * criaFila();

int estaVazia(Fila* f);

int estaCheia(Fila* f);

void enqueue(Fila* f, int valor);

int dequeue(Fila* f);

void libera(Fila *f);

void imprimeFila(Fila *f);