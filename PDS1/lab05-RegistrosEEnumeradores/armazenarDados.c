#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define TAMANHO_MAXIMO_PESSOAS 4
#define TAMANHO_MAXIMO_NOME 50
typedef struct dados{
    char nome[TAMANHO_MAXIMO_NOME];
    unsigned int idade;
    float salario;
}dados;
int main(int argc, char** argv[]){
    char comando[10];
    dados dadosPessoas[4];
    do{
        scanf("%s", &comando);
        if(strcmp(comando, "inserir")==0){
           
        }else if(strcmp(comando, "mostrar")==0){
            
        }
    }while(strcmp(comando, "inserir")==0||strcmp(comando, "mostrar")==0);
    
    
    return SUCESSO;
}
