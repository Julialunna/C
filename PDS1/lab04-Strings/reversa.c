#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SUCESSO 0

int main(int argc, char**argv[]){
    char stringEntrada[30], temp;
    int i=0;
    fgets(stringEntrada, 30, stdin);

    for(i=0;i<strlen(stringEntrada)/2;i++){
        temp=stringEntrada[i];
        stringEntrada[i]=stringEntrada[strlen(stringEntrada)-2-i];
        stringEntrada[strlen(stringEntrada)-2-i]=temp;
    }
    printf("%s\n", stringEntrada);

    return SUCESSO;
}