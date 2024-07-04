#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define TAMANHO_MAX_NOME 50
#define TAMANHO_MAX_TELEFONE 20
#define TAMANHO_COMANDO 10
#define TAMANHO_AGENDA 5

typedef struct pessoa {
    char nome[TAMANHO_MAX_NOME];
    int idade;
    char telefone[TAMANHO_MAX_TELEFONE];
} pessoa;

/*void escreverArquivo(pessoa pessoasAgenda[TAMANHO_AGENDA], FILE *arquivo) {
    pessoa pessoaLida;
    scanf("%s %d %s", pessoaLida.nome, &pessoaLida.idade, pessoaLida.telefone);
    printf("%s %d %s\n", pessoaLida.nome, pessoaLida.idade, pessoaLida.telefone);
    fwrite(&pessoaLida, sizeof(pessoa), 1, arquivo);
}*/
int confereEspaco(pessoa pessoasAgenda[TAMANHO_AGENDA]){
    int i =0;
    for(i=0;i<TAMANHO_AGENDA;i++){
        if(strcmp(pessoasAgenda[i].nome, "")==0){
            return i;
        }
    }
    return -1;
}
void inserirPessoa(pessoa pessoasAgenda[TAMANHO_AGENDA]) {
    pessoa pessoaLida;
    int indiceDisponivel;
    scanf("%s %d %s", pessoaLida.nome, &pessoaLida.idade, pessoaLida.telefone);
    indiceDisponivel=confereEspaco(pessoasAgenda);
    if(indiceDisponivel==-1){
        printf("Espaco insuficiente");
    }else{
        pessoasAgenda[indiceDisponivel]=pessoaLida;
        printf("Registro %s %d %s inserido\n", pessoasAgenda[indiceDisponivel].nome, pessoasAgenda[indiceDisponivel].idade, pessoasAgenda[indiceDisponivel].telefone);
    }
}
void imprimePessoas(pessoa pessoasAgenda[TAMANHO_AGENDA], int indice){
    for (int i = 0; i < indice; i++) {
        printf("%s %d %s\n", pessoasAgenda[i].nome, pessoasAgenda[i].idade, pessoasAgenda[i].telefone);
    }
}
void lerArquivo(pessoa pessoasAgenda[TAMANHO_AGENDA], FILE *arquivo) {
    int indice = 0;
    rewind(arquivo); 
    while (fread(&pessoasAgenda[indice], sizeof(pessoa), 1, arquivo) == 1) {
        indice++;
    }
    imprimePessoas(pessoasAgenda, indice);
}
void inicializaVetor(pessoa pessoasAgenda[TAMANHO_AGENDA]){
    int i;
    for(i=0;i<TAMANHO_AGENDA;i++){
        strcpy(pessoasAgenda[i].nome, "");
        pessoasAgenda[i].idade=0;
         strcpy(pessoasAgenda[i].telefone, "");
    }
}


int main(int argc, char *argv[]) {
    pessoa pessoasAgenda[TAMANHO_AGENDA];
    char nomeArquivo[TAMANHO_MAX_NOME], comando[TAMANHO_COMANDO];
    FILE *arquivo;

    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r+b");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    inicializaVetor(pessoasAgenda);
    lerArquivo(pessoasAgenda, arquivo);

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "Inserir") == 0) {
            inserirPessoa(pessoasAgenda);
        } else if (strcmp(comando, "Exibir") == 0) {
            lerArquivo(pessoasAgenda, arquivo);
        } else if (strcmp(comando, "Alterar") == 0) {
            
        } else if (strcmp(comando, "Excluir") == 0) {

        }
    }

    fclose(arquivo);
    return SUCESSO;
}

