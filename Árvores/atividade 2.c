#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

#define SUCESSO 0

Arv* insere_ordenado(char valor, Arv* a) {
	if (a == NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = valor;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if (a->info > valor) {
		a->esq = insere_ordenado(valor, a->esq);
	}
	else {
		a->dir = insere_ordenado(valor, a->dir);
	}
	return a;
}

int main(int argc, char** argv) {
	Arv* a;
	char info;
	int folhas = 0, filho = 0, filhos = 0;

	a = arv_criavazia();

	printf("Digite a raiz da arvore e depois os elementos:\nDigite * para parar\n");
	scanf("%c", &info);
	getchar();
	a = insere_ordenado(info, a);
	do {
		scanf("%c", &info);
		getchar();
		if (info != '*') {
			a = insere_ordenado(info, a);
		}
	} while (info != '*');

	arv_imprime_simetrica(a);

	return SUCESSO;
}