#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SUCESSO 0
#define TAMANHO_TIPO 50

typedef struct Iris{
    double comprimentoSepala; 
    double larguraSepala;
    double comprimentoPetala;
    double larguraPetala;
    char tipo [TAMANHO_TIPO];

}Iris;

void classificar(Iris nao_identificada, Iris registros_identificados[], int n){
    int i, menorDistanciaIndice;
    double *resultados, menorDistancia;
    resultados=(double*)malloc(n *sizeof(double));
    for(i=0;i<n;i++){
        resultados[i]=sqrt(pow((registros_identificados[i].comprimentoSepala-nao_identificada.comprimentoSepala),2)+pow((registros_identificados[i].larguraSepala-nao_identificada.larguraSepala),2)+pow((registros_identificados[i].comprimentoPetala-nao_identificada.comprimentoPetala),2)+pow((registros_identificados[i].larguraPetala-nao_identificada.larguraPetala),2));
    }
    menorDistancia=resultados[0];
    for(i=0;i<n;i++){
        if(resultados[i]<menorDistancia){
            menorDistanciaIndice=i;
            menorDistancia=resultados[i];
        }
    }
    printf("%s\n", registros_identificados[menorDistanciaIndice].tipo);
}
int main(int argc, char*argv[]){
    int quantRegistros, i;
    Iris *registros_identificados, nao_identificada;

    scanf("%d", &quantRegistros);
    registros_identificados=(Iris*)malloc(quantRegistros*sizeof(Iris));

    for(i=0;i<quantRegistros;i++){
        scanf("%lf %lf %lf %lf %s", &registros_identificados[i].comprimentoSepala, &registros_identificados[i].larguraSepala, &registros_identificados[i].comprimentoPetala, &registros_identificados[i].larguraPetala, registros_identificados[i].tipo);
    }
    
   scanf("%lf %lf %lf %lf", &nao_identificada.comprimentoSepala, &nao_identificada.larguraSepala, &nao_identificada.comprimentoPetala, &nao_identificada.larguraPetala);
   /*for(i=0;i<quantRegistros;i++){
        printf("%lf %lf %lf %lf %s\n", registros_identificados[i].comprimentoSepala, registros_identificados[i].larguraSepala, registros_identificados[i].comprimentoPetala, registros_identificados[i].larguraPetala, registros_identificados[i].tipo);
    }
    printf("%lf %lf %lf %lf\n", nao_identificada.comprimentoSepala, nao_identificada.larguraSepala, nao_identificada.comprimentoPetala, nao_identificada.larguraPetala);
    */
    classificar(nao_identificada, registros_identificados, quantRegistros);
    return SUCESSO;
}
