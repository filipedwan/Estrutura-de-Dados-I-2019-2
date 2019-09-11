#include"fila.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void inicializa_matrizes();
void destruir_matrizes();
void cria_labirinto_aleatorio();
int posicao_valida(int , int );
void BFS(Nodo);
int verifica_ouro(int , int);

int **visitados;
int **maze;
int qnt_de_ouro;
int N, M;

int main() {
	
	int n, m;

	printf("Entre com o tamanho do labirindo (NXM)");
	scanf("%d %d", &n, &m);
	N = n;
	M = m;

	inicializa_matrizes();
	cria_labirinto_aleatorio();
	Nodo inicio;
	inicio.row = inicio.col = 0;
	BFS(inicio);

	printf("Quantidade de outro encontrada: %d\n", qnt_de_ouro);
	destruir_matrizes();
	return 0;
}

int posicao_valida(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M)
		return 0;
	if (visitados[row][col])
		return 0;
	if (maze[row][col] == -1)
		return 0;
	return 1;
}

int verifica_ouro(int i, int j) {
	if (maze[i][j]) {
		qnt_de_ouro++;
		printf("-------------------------------------------------\n", i, j);
		printf("Ouro encontrado na posicao (%d, %d)\n", i, j);
		printf("-------------------------------------------------\n", i, j);
	}
}

void BFS(Nodo inicio) {
	Fila *f = cria_fila();
	enfileirar(f, inicio);
	Nodo curr;
	Nodo aux;
	while (!esta_vazia(f)) {
		desenfileirar(f, &curr);
		verifica_ouro(curr.row, curr.col);
		for (int i = curr.row - 1; i <= curr.row + 1; i++) {
			for (int j = curr.col - 1; j <= curr.col + 1; j++) {
				if (curr.row == i && curr.col == j)
					continue;
				if (posicao_valida(i, j)) {
					visitados[i][j] = 1;
					aux.row = i;
					aux.col = j;
					enfileirar(f, aux);
				}
			}
		}
		visitados[curr.row][curr.col] = 1;
	}
}

void inicializa_matrizes() {
	
	visitados = (int **)malloc(N*sizeof(int *));
	maze = (int **)malloc(N*sizeof(int *));
	for (int i = 0; i < N; i++) {
		*(visitados + i) = (int *)calloc(M, sizeof(int));
		*(maze + i) = (int *)calloc(M, sizeof(int));
	}
}

void destruir_matrizes() {	
	visitados = (int **)malloc(N*sizeof(int *));
	maze = (int **)malloc(N*sizeof(int *));
	for (int i = 0; i < N; i++) {
		free(visitados[i]);
		free(maze[i]);
	}
	free(visitados);
	free(maze);
}

void imprime_linha() {
	for (int i = 0; i < M * 3 + M / 2; i++)
		printf("%c", 95);
	printf("\n\n");

}

void cria_labirinto_aleatorio() {
	printf("\nLABIRINTO:\n");
	imprime_linha();
	//srand((unsigned) time);
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		printf("| ");
		for (int j = 0; j < M; j++) {
			maze[i][j] = rand() % 3;
			if (maze[i][j] == 2) {
				maze[i][j] = -1;
				printf("%d ", maze[i][j]);
			}else {
				printf(" %d ", maze[i][j]);
			}
			
		}
		printf(" |\n");
	}
	imprime_linha();
}
