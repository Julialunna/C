#include <stdio.h>
#define SUCESSO 0

int main(int argc, char**argv[]){
    int multiplos2=0, multiplos3=0, multiplos5=0, multiplos235=0, x, controle=1;

    scanf("%d", &x);

//while com condicionais que verificam a divisibilidade de cada número por 2,3,5 e os 3 ao mesmo tempo
    while(controle<=x){
        if(controle % 2 ==0){
            multiplos2++;
        }
        if(controle % 3 ==0){
            multiplos3++;
        }
        if(controle % 5 ==0){
            multiplos5++;
        }
        if((controle % 2 ==0) && (controle % 3 ==0) && (controle % 5 ==0)){
            multiplos235++;
        }
        controle++;
    }

    //impressão dos resultados
    printf("Múltiplos de 2: %d\n", multiplos2);
    printf("Múltiplos de 3: %d\n", multiplos3);
    printf("Múltiplos de 5: %d\n", multiplos5);
    printf("Múltiplos de todos: %d\n", multiplos235);
    return SUCESSO;
}