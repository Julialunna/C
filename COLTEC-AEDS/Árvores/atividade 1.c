#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#define SUCESSO 0

Arv* arv_cria_esq_null(char valor, Arv* dir) {
	Arv* raiz = (Arv*)malloc(sizeof(Arv));
	raiz->info = valor;
	raiz->esq = NULL;
	raiz->dir = dir;
	return raiz;
}

Arv* arv_cria_dir_esq_null(char valor) {
	Arv* raiz = (Arv*)malloc(sizeof(Arv));
	raiz->info = valor;
	raiz->esq = NULL;
	raiz->dir = NULL;
	return raiz;
}

int main(int argc, char** argv) {
	Arv* A;
	Arv* B;
	Arv* C;
	Arv* D;
	Arv* E;
	char infoa='a', infob='b', infoc='c', infod='d', infoe='e';
	int quant = 0, i, j;

	A = arv_cria_dir_esq_null(infoa);
	D = arv_cria_dir_esq_null(infod);
	B = arv_cria_esq_null(infob, A);
	E = arv_cria_esq_null(infoe, D);
	C = arv_cria(infoc, B, E);

	arv_imprime_preordem(C);
	arv_imprime_simetrica(C);
	arv_imprime_posordem(C);

	return SUCESSO;
}
