#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
#define SUCESSO 0
#define TAM_MAX_STRING 80

int main(int argc, char** argv) {
	char p[TAM_MAX_STRING];
	int i;
	int x = 0, y = 0;
	pilha_vet *pilha;
	pilha = pilha_vet_cria();

		printf("digite a sequencia de parenteses");
		scanf("%s", &p);
		getchar();
		for (i = 0; p[i] != 0; i++) {
			pilha_vet_push(pilha, p[i]);
	    }

		pilha_vet_testa_sequencia(pilha);

	return SUCESSO;
}