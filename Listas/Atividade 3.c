#include<stdio.h>
#include <stdlib.h>
#include "listas.h"


int main(int argc, char** argv) {
	int i, numdepessoas = 0, numdepassos = 0;
	Lista* l;

	l = lst_cria();

	printf("Digite o numero de pessoas:");
	scanf("%d", &numdepessoas);
	printf("Digite o numero de passos:");
	scanf("%d", &numdepassos);

	for (i = 1; i < numdepessoas + 1; i++) {
		l = lst_insere(l, i);
	}
	l = lcirc_transforma(l);
	l = problema_Josephus(l, numdepassos);
	free(l);
}