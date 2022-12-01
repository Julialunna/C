#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

#define SUCESSO 0

int conta_grau(Lista* grafo) {
	Lista* p;
	int grau = 0;
	for (p = grafo; p != NULL; p = p->prox) {
		grau++;
	}
	return grau;
}

int main(int argc, char** argv) {
	int i, j, vertices=0, controle=0, grau=0;
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
				grafo[i]=lst_insere(grafo[i], j);
			}
			else if (controle == 0) {
				continue;
			}
		}
	}
	for (i = 0; i < vertices; i++) {
		grau = conta_grau(grafo[i]);
		printf("Grau vertice %d: %d\n", i, grau);
	}

	for (i = 0; i < vertices; i++) {
		lst_libera(grafo[i]);
	}
	free(grafo);
	return SUCESSO;

}