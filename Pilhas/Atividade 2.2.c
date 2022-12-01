//Julia Almeida Luna e Lorena Ricoy Martins 203

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "pilhas.h"

#define SUCESSO 0
#define TAM_MAX_STRING 80
#define MAL_FORMADA 1

int testa_pilha(char p[TAM_MAX_STRING], int tam) {
	int i;
	pilha_vet* pilha;

	pilha = pilha_vet_cria();

	for (i = 0; i < tam - 1; i++) {
		if (p[i] == ')') {
			if (pilha_vet_vazia(pilha)) {
				return MAL_FORMADA;
			}
			else {
				pilha_vet_pop(pilha);
			}
		}
		else if (p[i] == '(') {
			pilha_vet_push(pilha, p[i]);
		}
	}
	pilha_vet_libera(pilha);
	return SUCESSO;
}

int main(int argc, char** argv) {

	char p[TAM_MAX_STRING];
	int i, tam=0, controle =0;


	printf("digite a sequencia de parenteses");
	scanf("%s", &p);

	getchar();

	tam = strlen(p);

	controle = testa_pilha(p, tam);
	if (controle == SUCESSO) {
		printf("pilha bem formada");
	}
	else if(controle==MAL_FORMADA ) {
		printf("pilha mal formada");
	}

	return SUCESSO;
}