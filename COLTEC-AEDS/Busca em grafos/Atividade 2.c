#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

#define SUCESSO 0

struct infos {
	int p;
	int u;
	int antecessor;
	char c;
};

int busca_de_fato(Lista** grafo, Lista* l, infos* busca, int* instante, int anterior) {
	
	*instante = *instante + 1;
	int atual = 0, i;
	atual = l->info;

	busca[l->info].p = *instante;
	busca[l->info].antecessor = anterior;
	busca[atual].c = 'g';

	l = grafo[atual];

	if (busca[l->info].c == 'w') {
		busca_de_fato(grafo, l, busca, instante, atual);
	}
	if (busca[l->info].c == 'g' || busca[l->info].c == 'b') {
		*instante=*instante+1;
		busca[atual].u = *instante;
		busca[atual].c = 'b';
	}
	
	return *instante;
}

void busca_em_profundidade(Lista** grafo, int vertices, int inicio) {
	Lista* p;
	infos* busca;
	int  i, anterior=0, resultado=0, instante2=0;
	int* instante;
	instante = &instante2;

	busca = (infos*)malloc(sizeof(infos) * vertices);
	
	for (i = 0; i < vertices; i++) {
		busca[i].c = 'w';
	}


	*instante = *instante + 1;
	busca[inicio].antecessor = -1;//struct busca da origem
	busca[inicio].p = *instante;//struct busca da origem
	busca[inicio].c = 'g';//struct busca da origem
	anterior = inicio;

	resultado = busca_de_fato(grafo, grafo[inicio], busca, instante, anterior);
	*instante = *instante + 1;

	busca[inicio].u = *instante; //struct busca da origem
	busca[inicio].c = 'b';//struct busca da origem

	for (i = 0; i < vertices; i++) {
		if (busca[i].c == 'w') {
			*instante = *instante + 1;
			inicio = i;
			anterior = inicio;
			busca[inicio].antecessor = -1;//struct busca da nova origem
			busca[inicio].p = *instante;//struct busca da nova origem

			resultado = busca_de_fato(grafo, grafo[inicio], busca, instante, anterior);
			
			*instante = *instante + 1;
			busca[inicio].u = *instante; //struct busca da nova origem
			busca[inicio].c = 'b';//struct busca da nova origem
		}
	}

	for (i = 0; i < vertices; i++) {
		printf("%d cor: %c primeiro: %d ultimo: %d antecessor:%d\n", i, busca[i].c, busca[i].p, busca[i].u, busca[i].antecessor);
	}
	
}

int main(int argc, char** argv) {
	int i, j, vertices = 0, controle = 0, grau = 0, inicio=0;
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


	printf("qual o vertice de inicio?");
	scanf("%d", &inicio);
	busca_em_profundidade(grafo, vertices, inicio);

	for (i = 0; i < vertices; i++) {
		lst_libera(grafo[i]);
	}

	free(grafo);
	return SUCESSO;

}