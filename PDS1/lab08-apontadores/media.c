#include <stdio.h>

#include <math.h>
#include <stdlib.h>
#define SUCESSO 0

void media(double vet[], int n, int *i){
    int j, indiceMenorDiferenca;
    double media, menorDiferenca;
    for(j=0;j<n;j++){
        media+=vet[j];
    }
        //printf("b %lf\n", media);
    media=media/n;
    //printf("b %lf\n", media);
    menorDiferenca=vet[0];
    //printf("media: %lf\n", media);
    for(j=0;j<n;j++){
        //printf("%lf %lf\n", fabs(vet[j]-media), fabs(menorDiferenca-media));
        if(fabs(vet[j]-media)<fabs(menorDiferenca-media)){
            //printf("a\n");
            menorDiferenca=vet[j];
            indiceMenorDiferenca=j;
        }
    }
    *i=indiceMenorDiferenca;

}
int main(int argc, char**argv[]){
    int tamanhoVetor, j, i;
    double vetor[50];
    scanf("%d", &tamanhoVetor);
    //vetor= (double *) malloc(tamanhoVetor *sizeof(double));
    for(j=0;j<tamanhoVetor;j++){
        scanf("%lf", &vetor[j]);
    }
    /*for(j=0;j<tamanhoVetor;j++){
        printf("%lf\n", vetor[j]);
    }*/
    media(vetor, tamanhoVetor, &i);
    printf("%d\n", i);
    return SUCESSO;
}