#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0
#define DIFERENTES 1
#define IGUAIS 0
#define NAO_COMP 9

int main(int argc, char** argv) {
	Lista* l;
	Lista* l2;
	Lista* save1;
	Lista* save2;
	int info = 0, comp = 9;

	l = lst_cria();
	l2 = lst_cria();

	printf("-----COMPARADOR DE LISTAS-----\n");
	printf("Uso: para deixar de adicionar numeros na lista digite 0\n");

	do {

		printf("Digite o valor a ser adicionado na lista 1:\n");
		scanf("%d", &info);
		getchar();

		l = lst_insere(l, info);

	} while (info != 0);

	do {

		printf("Digite o valor a ser adicionado na lista 2:\n");
		scanf("%d", &info);
		getchar();

		l2 = lst_insere(l2, info);

	} while (info != 0);

	comp = compara_lsts(l, l2);

	if (comp == IGUAIS) {
		printf("As listas sao iguais.");
	}
	else if (comp == DIFERENTES) {
		printf("As listas nao sao iguais.");
	}
	else if (comp == NAO_COMP) {
		printf("A comparacao nao foi feita");
	}
	else {
		printf("ERRO");
	}

	lst_libera(l);
	lst_libera(l2);
	return SUCESSO;
}