#include <stdio.h>
#define SUCESSO 0
#define TAMANHO_MAX_VETOR 40

int main(int argc, char**argv[]){
    int numAlunosAeds, numAlunosCalculo, matriculasAeds[TAMANHO_MAX_VETOR], matriculasCalculo[TAMANHO_MAX_VETOR], i, j;

    scanf("%d", &numAlunosAeds);
    for(i=0;i<numAlunosAeds;i++){
        scanf("%d", &matriculasAeds[i]);
    }

    scanf("%d", &numAlunosCalculo);
    for(i=0;i<numAlunosCalculo;i++){
        scanf("%d", &matriculasCalculo[i]);
    }

    for(i=0;i<numAlunosAeds;i++){
        for(j=0;j<numAlunosCalculo;j++){
            printf("aeds: %d calculo: %d \n", matriculasAeds[i], matriculasCalculo[j]);
            if(matriculasAeds[i]==matriculasCalculo[j]){
                printf("%d\n", matriculasCalculo[j]);
            }
        }
    }
    return SUCESSO;
}