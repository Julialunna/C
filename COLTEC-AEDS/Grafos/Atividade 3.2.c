#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

#define SUCESSO 0


void testa_conexoes(Lista** grafo, int vertices) {
	int i, j, controle=0;
	Lista* p;

	for (i = 0; i < vertices; i++) {
		controle=0;
		for (j = 0; j < vertices; j++) {
			for (p = grafo[i]; p != NULL; p = p->prox) {
				if (i != j) {
					if (p->info == j) {
						break;
					}
					else if (p->info != j && p->prox==NULL) {
						printf("Falha de conexão entre vertice %d e vertice %d\n", i, j);
					}
				}
			}
		}
	}
}

int main(int argc, char** argv) {
	int i, j, vertices = 0, controle = 0, grau = 0;
	Lista** grafo;

	printf("qual o numero de vertices do seu grafo nao orientado");
	scanf("%d", &vertices);

	grafo = (Lista**)malloc(sizeof(Lista*) * vertices);

	for (i = 0; i < vertices; i++) {
		grafo[i] = lst_cria();
		for (j = 0; j < vertices; j++) {
			printf("O vertice: %d eh adjacente ao vertice %d?", i, j);
			scanf("%d", &controle);
			getchar();
			if (controle == 1) {
				grafo[i] = lst_insere(grafo[i], j);
			}
			else if (controle == 0) {
				continue;
			}
		}
	}

	for (i = 0; i < vertices; i++) {
		printf("vertice %d\n", i);
		lst_imprime(grafo[i]);
	}

	testa_conexoes(grafo, vertices);

	return SUCESSO;
}
