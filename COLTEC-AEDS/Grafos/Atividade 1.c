#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

int main(int argc, char** argv) {

	int** grafo; 
	int* grau;
	int linhas = 0, colunas = 0, vertices=0, i, j, controle=0;

	printf("Qual o numero de vertices do grafo");
	scanf("%d", &vertices);
	getchar();

	linhas = vertices;
	colunas = vertices;

	grau = (int*)malloc(sizeof(int) * vertices);
	grafo = (int**)malloc(sizeof(int*) * linhas);

	for (i = 0; i < vertices; i++) {
		grau[i] = 0;
	}
	for (i = 0; i < linhas; i++){
		grafo[i] = (int*)malloc(sizeof(int) * colunas);
	}

	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			printf("O vertice: %d eh adjacente ao vertice %d?", i, j);
			scanf("%d", &controle);
			getchar();
			if (controle == 1) {
				grafo[i][j] = 1;
			}
			else if (controle == 0) {
				grafo[i][j] = 0;
			}
		}
	}

	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			if (grafo[i][j] == 1) {
				grau[i] = grau[i] + 1;
			}
			else if (grafo[i][j] == 0) {
				continue;
			}
		}
	}

	for (i = 0; i < vertices; i++) {
		printf("grau vertice %d: %d", i, grau[i]);
	}

	for (i = 0; i < linhas; i++) {
		free(grafo[i]);
	}
	return SUCESSO;
}
