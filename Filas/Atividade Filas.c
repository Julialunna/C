#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define SUCESSO 0
#define TAMLETRAS 3+1
#define TAMNUMEROS 4

struct lista {
	char letras[TAMLETRAS];
	int num;
	struct lista* prox;
};
typedef struct lista Lista;

struct filal {
	Lista* ini;
	Lista* fim;
};

typedef struct fila Fila;
typedef struct filal FilaL;

void fila_imprime_l(FilaL* f) {
	Lista* q;
	int i;

	for (q = f->ini; q != NULL; q = q->prox) {
		printf("%s %d\n", q->letras, q->num);
	}
}


int fila_vazia_l(FilaL* f) {
	return (f->ini == NULL);
}

FilaL* fila_cria_l() {
	FilaL* f = (FilaL*)malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL* f, char letras[4], int numeros) {

	Lista* n = (Lista*)malloc(sizeof(Lista));
	int i;
	for (i = 0; i < TAMLETRAS; i++) {
		n->letras[i] = letras[i];
	}
	n->num=numeros;
	n->prox = NULL;

	if (f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;

}

void fila_libera_l(FilaL* f) {
	Lista* q = f->ini;
	while (q != NULL) {
		Lista* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

char* fila_retira_l(FilaL* f) {
	Lista* t;
	char* v;
	if (fila_vazia_l(f)) {
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->letras;
	f->ini = t->prox;
	if (f->ini == NULL) f->fim = NULL;
	free(t);
	return v;
}

void retira_carro(FilaL* f) {
	Lista* q;
	Lista* d;
	Lista* s;
	Lista* t;
	FilaL* fila2;
	fila2 = fila_cria_l();
	char letras[TAMLETRAS];
	char letras2[TAMLETRAS];
	int numeros, i;

	printf("Digite a placa do carro a ser retirado:");
	fgets(letras, TAMLETRAS, stdin);
	getchar();
	printf("Digite a sequencia de numeros da placa:");
	scanf("%d", &numeros);
	getchar();

	for (q = f->ini; q != NULL; q = q->prox) {
		if (strcmp(letras, q->letras) == 0 && numeros == q->num) {
			d = q;
			if (d == f->ini) {
				printf("ENTREI NO IF");
				fila_retira_l(f);
				break;
			}
			for (s = f->ini; s != d; s = s->prox) {
				fila_insere_l(fila2, s->letras, s->num);
			}
			
			while(f->ini != d){
			    fila_retira_l(f);
			} 
			
				fila_retira_l(f);
				break;
			
		}
	}

	for (t = fila2->ini; t != NULL; t = t->prox) {
		fila_insere_l(f, t->letras, t->num);
	}

	do {
		fila_retira_l(fila2);
	} while (fila2->fim !=NULL);

	printf("ESTADO ATUAL:\n");
	fila_imprime_l(f);
	
}

int main(int argc, char** argv) {

	filal* fila;
	fila = fila_cria_l();
	int comando = 0;
	char letras[TAMLETRAS];
	int numeros, i;

	do {
		printf("O que deseja fazer?\n1-Adicionar carros\n2-Retirar carro\n3-Encerrar programa");
		scanf("%d", &comando);
		getchar();
		switch (comando) {
		case 1:
				printf("Digite a sequencia de letras da placa:");
				fgets(letras, TAMLETRAS, stdin);
				getchar();
				printf("Digite a sequencia de numeros da placa:");
				scanf("%d", &numeros);
				getchar();
				fila_insere_l(fila, letras, numeros);
				break;

		case 2:
			retira_carro(fila);
			break;

		case 4:
			fila_retira_l(fila);
			fila_imprime_l(fila);
		}

	} while (comando != 3);

	fila_imprime_l(fila);
	fila_libera_l(fila);
	return SUCESSO;
}