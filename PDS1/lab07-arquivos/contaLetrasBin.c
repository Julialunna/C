#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SUCESSO 0
#define TAMANHO_MAX_NOME 50
int main(int argc, char*argv[]){
    FILE *arquivoEntrada;
    char nomeArquivo[50];
    unsigned int quantLetras=0, escrito=0;
    char letraArquivo;
    char entrada[100];


    scanf("%s", nomeArquivo);
    arquivoEntrada=fopen(nomeArquivo, "rb");
    
    if(arquivoEntrada==NULL){
        //printf("Erro na abertura do arquivo");
        exit(1);
    }
    while(1){
        letraArquivo=fgetc(arquivoEntrada);
        //printf("%c", letraArquivo);
        if(feof(arquivoEntrada)){
            break;
        }
        if(letraArquivo=='a'){
            quantLetras++;
        }
    }
    printf("%d\n", quantLetras);
    fclose(arquivoEntrada);
    return SUCESSO;
}
    /*escrito=fwrite(entrada, sizeof(char), strlen(entrada), arquivoEntrada);
    printf("%d %s", escrito, entrada);
    rewind(arquivoEntrada);*/