#include <stdio.h>
#define TAMANHO_MAX_VETOR 10
#define SUCESSO 0

int main(int argc, char** argv[]){
    int vetorRecebido[TAMANHO_MAX_VETOR], vetorInverso[TAMANHO_MAX_VETOR], i;
    
    for(i=0;i<TAMANHO_MAX_VETOR;i++){
        scanf("%d", &vetorRecebido[i]);
    }

    for(i=0;i<TAMANHO_MAX_VETOR;i++){
        vetorInverso[(TAMANHO_MAX_VETOR-1)-i]=vetorRecebido[i];
    }

    for(i=0;i<TAMANHO_MAX_VETOR;i++){
        printf("%d\n", vetorInverso[i]);
    }
    return SUCESSO;
}