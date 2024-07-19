#include <stdio.h>
#include<stdlib.h>
#define SUCESSO 0
#define TAMANHO_NOME_LOCAL 100
enum Mes {
        invalido,
        janeiro,
        fevereiro, 
        marco,
        abril,
        maio,
        junho,
        julho, 
        agosto,
        setembro,
        outubro,
        novembro,
        dezembro
};
typedef struct Data{
    int dia;
    enum Mes mes;
    int ano;
}Data;

typedef struct Evento{
    char nome[TAMANHO_NOME_LOCAL];
    char local[TAMANHO_NOME_LOCAL];
    Data data;
}Evento;

void cadastrar_eventos(Evento agenda[], int n){
    int i, mesEntrada;
    for(i=0;i<n;i++){
        scanf("%s %s %d %d %d", agenda[i].nome, agenda[i].local, &agenda[i].data.dia, &mesEntrada, &agenda[i].data.ano);
        agenda[i].data.mes=(enum Mes)mesEntrada;
    }
}

void imprimir_eventos(Evento agenda[], Data d, int n){
    int achou=0, i;
    for(i=0;i<n;i++){
        if((agenda[i].data.dia==d.dia)&&(agenda[i].data.mes==d.mes)&&(agenda[i].data.ano==d.ano)){
            achou=1;
            printf("%s %s\n", agenda[i].nome, agenda[i].local);
        }
    }
    if(achou==0){
        printf("Nenhum evento encontrado!\n");
    }
}

int main(int argc, char*argv[]){
    int quantRegistros, mesEntrada;
    Evento *eventos;
    Data dataEntrada;
    scanf("%d", &quantRegistros);
    eventos=(Evento*)malloc(quantRegistros*(sizeof(Evento)));
    cadastrar_eventos(eventos, quantRegistros);
    scanf("%d %d %d", &dataEntrada.dia, &mesEntrada, &dataEntrada.ano);
    dataEntrada.mes = (enum Mes)mesEntrada;
    imprimir_eventos(eventos, dataEntrada, quantRegistros);
    return SUCESSO;
}