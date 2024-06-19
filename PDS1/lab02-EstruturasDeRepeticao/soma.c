#include <stdio.h>
#define SUCESSO 0

int main(int argc, char**argv[]){
    int num, somaAteNum=0, i;

    scanf("%d", &num);
//looping que faz a soma dos núemros de um até num
    for(i=1;i<=num;i++){
        somaAteNum+=i;
    }
    printf("%d", somaAteNum);
    return SUCESSO;
}