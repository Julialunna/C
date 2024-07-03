#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define TAMANHO_MAX_NOME 50
int main(int argc, char*argv[]){
    FILE *arquivoEntrada;
    const char *nomeArquivo= argv[1];
    int quantLetras=0;
    char letraArquivo;
    arquivoEntrada=fopen(nomeArquivo, "rb");
    
    if(arquivoEntrada==NULL){
        //printf("Erro na abertura do arquivo");
        exit(1);
    }
    while(1){
        letraArquivo=fgetc(arquivoEntrada);
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