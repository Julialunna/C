#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define TAMANHO_MAX_NOME 50
#define TAMANHO_MAX_TELEFONE 20
#define TAMANHO_COMANDO 10
#define TAMANHO_AGENDA 100

typedef struct pessoa {
    char nome[TAMANHO_MAX_NOME];
    int idade;
    char telefone[TAMANHO_MAX_TELEFONE];
} pessoa;

void imprimePessoas(pessoa pessoasAgenda[TAMANHO_AGENDA]){
    int i = 0;
    for(i=0;i<TAMANHO_AGENDA &&strcmp(pessoasAgenda[i].nome, "") != 0;i++){
        printf("%s %d %s\n", pessoasAgenda[i].nome, pessoasAgenda[i].idade, pessoasAgenda[i].telefone);

    }
}

int confereEspaco(pessoa pessoasAgenda[TAMANHO_AGENDA]){
    int i = 0;
    for (i = 0; i < TAMANHO_AGENDA; i++){
        if (strcmp(pessoasAgenda[i].nome, "") == 0){
            return i;
        }
    }
    return -1;
}

void inserirPessoa(pessoa pessoasAgenda[TAMANHO_AGENDA], char nomeArquivo[TAMANHO_MAX_NOME], FILE *arquivo) {
    pessoa pessoaLida;
    int indiceDisponivel;
    scanf("%49s %d %19s", pessoaLida.nome, &pessoaLida.idade, pessoaLida.telefone);
    indiceDisponivel = confereEspaco(pessoasAgenda);
    if (indiceDisponivel == -1){
        printf("Espaco insuficiente\n");
    } else {
        pessoasAgenda[indiceDisponivel] = pessoaLida;
        printf("Registro %s %d %s inserido\n", pessoasAgenda[indiceDisponivel].nome, pessoasAgenda[indiceDisponivel].idade, pessoasAgenda[indiceDisponivel].telefone);

        fseek(arquivo, sizeof(pessoa)*indiceDisponivel, SEEK_SET);
        fwrite(&pessoasAgenda[indiceDisponivel], sizeof(pessoa), 1, arquivo);
    }
}

int achaPessoa(pessoa pessoasAgenda[TAMANHO_AGENDA], char nome[TAMANHO_MAX_NOME]){
    int indice = 0;
    while (strcmp(pessoasAgenda[indice].nome, "") != 0) {
        if (strcmp(pessoasAgenda[indice].nome, nome) == 0){
            return indice;
        }
        indice++;
    }
    return -1;
}

void exibirPessoa(pessoa pessoasAgenda[TAMANHO_AGENDA], char nome[TAMANHO_MAX_NOME]){
    int indice = 0;
    indice = achaPessoa(pessoasAgenda, nome);
    if (indice != -1){
        printf("Registro %s %d %s exibido\n", pessoasAgenda[indice].nome, pessoasAgenda[indice].idade, pessoasAgenda[indice].telefone);
    } else {
        printf("Registro %s invalido\n", nome);
    }
}

void excluirPessoa(pessoa pessoasAgenda[TAMANHO_AGENDA], char nome[TAMANHO_MAX_NOME], FILE *arquivo, char nomeArquivo[TAMANHO_MAX_NOME]){
    int indice, i;
    pessoa pessoaTemporaria;
    indice = achaPessoa(pessoasAgenda, nome);
    if(indice==-1){
        printf("Registro %s invalido\n", nome);
    }else{
        printf("Registro %s %d %s excluido\n", pessoasAgenda[indice].nome, pessoasAgenda[indice].idade, pessoasAgenda[indice].telefone);

    }
    for(i=indice;strcmp(pessoasAgenda[i].nome, "")!=0;i++){
        pessoasAgenda[i]=pessoasAgenda[i+1];
        if (strcmp(pessoasAgenda[i+2].nome, "")==0||i+1==99){
             strcpy(pessoasAgenda[i+1].nome, "");
            pessoasAgenda[i+1].idade=0;
            strcpy(pessoasAgenda[i+1].telefone, "");
        }
    }
    //imprimePessoas(pessoasAgenda);
    indice = confereEspaco(pessoasAgenda);
    //printf("%d\n", indice);
    fseek(arquivo, 0, SEEK_SET);
    fwrite(pessoasAgenda, sizeof(pessoa), TAMANHO_AGENDA, arquivo);
}

void lerArquivo(pessoa pessoasAgenda[TAMANHO_AGENDA], FILE *arquivo) {
    int indice = 0;
    rewind(arquivo);
    for(indice=0;indice<TAMANHO_AGENDA;indice++){
        fread(&pessoasAgenda[indice], sizeof(pessoa), 1, arquivo) == 1;
    }

    //imprimePessoas(pessoasAgenda);
}

void inicializaVetor(pessoa pessoasAgenda[TAMANHO_AGENDA]){
    int i;
    for (i = 0; i < TAMANHO_AGENDA; i++){
        strcpy(pessoasAgenda[i].nome, "");
        pessoasAgenda[i].idade = 0;
        strcpy(pessoasAgenda[i].telefone, "");
    }
}

void alterarPessoa(pessoa pessoasAgenda[TAMANHO_AGENDA], char nomeArquivo[TAMANHO_MAX_NOME], FILE *arquivo){
    pessoa pessoaEntrada;
    int indice, quantRegistros = 0, i;
    scanf("%49s %d %19s", pessoaEntrada.nome, &pessoaEntrada.idade, pessoaEntrada.telefone);
    indice = achaPessoa(pessoasAgenda, pessoaEntrada.nome);
    if (indice == -1){
        printf("Registro ausente para alteracao\n");
    } else {
        pessoasAgenda[indice] = pessoaEntrada;
        for (i = 0; strcmp(pessoasAgenda[i].nome, "") != 0; i++){
            quantRegistros++;
        }
    
        arquivo = freopen(nomeArquivo, "w+b", arquivo);
        if (arquivo == NULL) {
            perror("Erro ao reabrir o arquivo");
            exit(1);
        }
        fwrite(pessoasAgenda, sizeof(pessoa), quantRegistros, arquivo);
    }
}

int main(int argc, char *argv[]) {
    pessoa pessoasAgenda[TAMANHO_AGENDA];
    char nomeArquivo[TAMANHO_MAX_NOME], comando[TAMANHO_COMANDO], nomePessoa[TAMANHO_MAX_NOME];
    FILE *arquivo;

    scanf("%49s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r+b");
    if (arquivo == NULL) {
        //printf("Erro na abertura do arquivo");
        exit(1);
    }

    inicializaVetor(pessoasAgenda);
    lerArquivo(pessoasAgenda, arquivo);

    while (scanf("%9s", comando) != EOF) {
        if (strcmp(comando, "Inserir") == 0) {
            inserirPessoa(pessoasAgenda, nomeArquivo, arquivo);
        } else if (strcmp(comando, "Exibir") == 0) {
            scanf("%49s", nomePessoa);
            exibirPessoa(pessoasAgenda, nomePessoa);
        } else if (strcmp(comando, "Alterar") == 0) {
            alterarPessoa(pessoasAgenda, nomeArquivo, arquivo);
        } else if (strcmp(comando, "Excluir") == 0) {
            scanf("%49s", nomePessoa);
            excluirPessoa(pessoasAgenda, nomePessoa, arquivo, nomeArquivo);
        }
    }

    fclose(arquivo);
    return SUCESSO;
}







