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
void inicializaVetor(dados vetorDados[TAMANHO_MAXIMO_PESSOAS]){
    int i;
    for(i=0;i<TAMANHO_MAXIMO_PESSOAS;i++){
        strcpy(vetorDados[i].nome, "");
        vetorDados[i].idade=0;
        vetorDados[i].salario=0.0;
    }
}
int confirmaSeTemEspaco(dados vetorDados[TAMANHO_MAXIMO_PESSOAS]){
    int i;
    for(i=0;i<TAMANHO_MAXIMO_PESSOAS;i++){
        if(strcmp(vetorDados[i].nome, "")==0){
            return i;
        }
    }
    return -1;
}
int achaRegistro(dados vetorDados[TAMANHO_MAXIMO_PESSOAS], char nomeRegistro[TAMANHO_MAXIMO_NOME]){
    int i;
    for(i=0;i<TAMANHO_MAXIMO_PESSOAS;i++){
        if(strcmp(vetorDados[i].nome, nomeRegistro)==0){
            
            printf("Registro %s %d %.2f\n", vetorDados[i].nome, vetorDados[i].idade, vetorDados[i].salario);
            return SUCESSO;
        }
    }
    printf("Registro ausente\n");
    return SUCESSO;
}
int main(int argc, char** argv[]){
    char comando[10], nomeEntrada[TAMANHO_MAXIMO_NOME];
    dados dadosPessoas[4];
    int resultadoEspaco, idadeEntrada;
    float salarioEntrada;

    inicializaVetor(dadosPessoas);
    do{
        setbuf(stdin, NULL);
        fgets(comando, TAMANHO_MAXIMO_NOME, stdin);
        setbuf(stdin, NULL);
        if(strcmp(comando, "inserir\n")==0){
            scanf("%s %d %f", nomeEntrada, &idadeEntrada, &salarioEntrada);
            resultadoEspaco=confirmaSeTemEspaco(dadosPessoas);
           if(resultadoEspaco==-1){
            printf("Espaco insuficiente\n");
           }else{

            strcpy(dadosPessoas[resultadoEspaco].nome, nomeEntrada);
            dadosPessoas[resultadoEspaco].idade=idadeEntrada;
            dadosPessoas[resultadoEspaco].salario=salarioEntrada;

            printf("Registro %s %d %.2f inserido\n",  dadosPessoas[resultadoEspaco].nome, dadosPessoas[resultadoEspaco].idade, dadosPessoas[resultadoEspaco].salario);
           }
        }else if(strcmp(comando, "mostrar\n")==0){
            scanf("%s", nomeEntrada);
            achaRegistro(dadosPessoas, nomeEntrada);
        }
    }while(strcmp(comando, "inserir\n")==0||strcmp(comando, "mostrar\n")==0);
    
    
    return SUCESSO;
}
