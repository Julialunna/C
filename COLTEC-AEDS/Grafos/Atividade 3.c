#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

#define SUCESSO 0
#define INSUCESSO 1

int percorre(Lista* l, int p, Lista** grafo, int vertices, int teste) {
	Lista* controle;
	Lista* controle2;

	for (controle2 = l; controle2 != NULL; controle2 = controle2->prox){
		if (controle2->info == p) {
			printf("foi possivel ter comunicacao entre esses servidores\n");
			return SUCESSO;
		}

		if (teste < vertices) {
			for (controle = grafo[l->info]; controle != NULL; controle = controle->prox) {
				teste++;;
				percorre(controle, p, grafo, vertices, teste);
			}
		}
		else {
			printf("nao foi possivel ter comunicacao entre esses servidores\n");
			return INSUCESSO;
		}
	}	
	
}

int main(int argc, char** argv) {
	int i, j, vertices = 0, controle = 0, grau = 0, controle2=0, teste=0;
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
		for (j = 0; j < vertices; j++) {
			if (i != j) {
				printf("caminho entre %d e %d", i, j);
				controle2 = percorre(grafo[i], j, grafo, vertices, teste);
			}
		}
	}
	for (i = 0; i < vertices; i++) {
		lst_libera(grafo[i]);
	}
	free(grafo);
	return SUCESSO;
}