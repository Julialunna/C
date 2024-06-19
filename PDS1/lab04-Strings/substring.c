#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SUCESSO 0

int main(int argc, char**argv[]){
    char S1[30], S2[30];
    int i=0,j=0, resultado=0;
    fgets(S1, 30,stdin);
    fgets(S2, 30,stdin);
    printf("%s a", S2);
    for (i=0;i<=strlen(S1)-strlen(S2);i++){
        if(S1[i]==S2[0]){
            for(j=1;j<strlen(S2)-1;j++){
                if(S1[i+j]==S2[j]){
                    resultado=1;
                    continue;
                }else{
                    resultado=0;
                }
            }
        }
    }
    if(resultado ==1){
        printf("É substring");
    }else{
        printf("Não é substring");
    }
    return SUCESSO;
}