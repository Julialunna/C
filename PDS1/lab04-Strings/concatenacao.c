#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SUCESSO 0

int main(int argc, char**argv[]){
    char S1[40], S2[20];
    int i=0, tamanhoS1, tamanhoS2;
    fgets(S1, 20, stdin);
    fgets(S2, 20, stdin);
    
    S1[strlen(S1)-1]='\0';
    S2[strlen(S2)-1]='\0';
    strcat(S1, S2);
    printf("%s", S1);
    return SUCESSO;
}