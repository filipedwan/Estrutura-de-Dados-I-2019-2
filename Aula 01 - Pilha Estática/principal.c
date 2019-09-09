#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
	int valor;
	Pilha *p = cria_pilha();
	push(p, 10);
	push(p, 20);
	push(p, 30);

	pop(p, &valor);
	printf("%d\n", valor);

	pop(p, &valor);
	printf("%d\n", valor);

	libera_pilha(p);

	return 0;
}