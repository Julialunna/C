#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define SUCESSO 0
#define NAO_TEM -1




void busca_em_largura(int** grafo, int vertices, int inicio) {
	Fila* q;
	char* c;
	int* d;
	int* antecessor;
	int usando = 0;
	int i, distancia = 0, posicao_vet=0, j;

	c = (char*)malloc(sizeof(char) * vertices);
	d = (int*)malloc(sizeof(int) * vertices);
	antecessor = (int*)malloc(sizeof(int) * vertices);
	antecessor[inicio] = NAO_TEM;

	q = fila_cria_vet();
	fila_insere_vet(q, inicio);
	d[inicio] = 0;
	distancia = d[inicio];
	c[inicio] = 'g';

	while (!fila_vazia_vet(q)) {
		posicao_vet = q->ini;
		usando = q->vet[posicao_vet];
		distancia = d[usando];
		
		for (i = 0; i < vertices; i++) {
			if (grafo[usando][i]==1) {
				antecessor[i] = usando;
				c[i] = 'g';
				d[i] = distancia + 1;
				fila_insere_vet(q, i);
			}
		}

		c[usando] = 'b';
		fila_retira_vet(q);
		for (j = 0; j < vertices; j++) {
			printf("vetores\n");
			printf("%d antecessor: %d distancia: %d cor: %c\n", j, antecessor[j], d[j], c[j]);
		}
	
	}
	free(antecessor);
	free(c);
	free(d);
}

int main(int argc, char** argv) {

	int** grafo;
	int* grau;
	int linhas = 0, colunas = 0, vertices = 0, i, j, controle = 0, inicio=0;

	printf("Qual o numero de vertices do grafo");
	scanf("%d", &vertices);
	getchar();

	linhas = vertices;
	colunas = vertices;

	grafo = (int**)malloc(sizeof(int*) * linhas);

	for (i = 0; i < linhas; i++) {
		grafo[i] = (int*)malloc(sizeof(int) * colunas);
	}

	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			if (i != j) {
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
			else {
				grafo[i][j] = 0;
			}
		}
	}

	printf("qual o vertice de inicio?");
	scanf("%d", &inicio);
	busca_em_largura(grafo, vertices, inicio);
	return SUCESSO;

}


	
