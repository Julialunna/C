#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

#define SUCESSO 0

struct caracter {
	char info;
	int quantidade;
};

Arv* insere_ordenado(char valor, Arv* a) {
	if (a == NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = valor;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if (a->info >= valor) {
		a->esq = insere_ordenado(valor, a->esq);
	}
	else {
		a->dir = insere_ordenado(valor, a->dir);
	}
	return a;
}

void calcula_nos(Arv* a, int* quant) {
	if (!arv_vazia(a)) {
		*quant = *quant + 1;
		calcula_nos(a->esq, quant);
		calcula_nos(a->dir, quant);
	}
	
}

void ocorrencia_caracter(Arv* a, int quant, caracter * caracteres) {
	int i, j;

	if (!arv_vazia(a)) {
		for (i = 0; i < quant; i++) {
			if (a->info == caracteres[i].info) {
				caracteres[i].quantidade = caracteres[i].quantidade + 1;
				break;
			}
			else if (a->info != caracteres[i].info && caracteres[i].quantidade == 0){
				caracteres[i].info = a->info;
				caracteres[i].quantidade = caracteres[i].quantidade + 1;
				break;
			}
			else if (a->info != caracteres[i].info && caracteres[i].quantidade != 0) {
				continue;
			}
		}
		ocorrencia_caracter(a->esq, quant, caracteres);
		ocorrencia_caracter(a->dir, quant, caracteres);
	}

}

int main(int argc, char** argv) {
	Arv* a;
	char info;
	caracter* caracteres;
	int quant=0, i, j;
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

	calcula_nos(a, &quant);
	caracteres = (caracter*) malloc(quant * sizeof(caracter));
	for (i = 0; i < quant; i++) {
		caracteres[i].info = 0;
		caracteres[i].quantidade = 0;
	}

	ocorrencia_caracter(a, quant, caracteres);

	for (i = 0; i < quant; i++) {
		printf("%c", caracteres[i].info);
		for (j = 0; j < caracteres[i].quantidade; j++) {
			if (caracteres[i].info != 0) {
				if (j == caracteres[i].quantidade-1) {
					printf("*\n");
				}
				else {
					printf("*");
				}
			}
			else {
				continue;
			}	
		}
	}

	return SUCESSO;
}
