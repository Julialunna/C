#include <stdio.h>
#define SUCESSO 0

//função que define qual o maior número
float ehDivisivel(int x, int y, int z){
    if((x%y==0) && (x%z==0)){
        printf("O número é divisível");
    }else{
        printf("O número não é divisível");
    }
}

int main(int argc, char** argv[]){
    int x, y, z;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    ehDivisivel(x, y, z);
    return SUCESSO;
}