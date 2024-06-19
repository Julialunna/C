#include <stdio.h>
#define SUCESSO 0
#define NOTADE100 100
#define NOTADE50 50
#define NOTADE20 20
#define NOTADE10 10
#define NOTADE5 5
#define NOTADE2 2
#define NOTADE1 1

//função que converte celsius em fahrenheit


int main(int argc, char** argv[]){
    int valor;

    scanf("%d", &valor);

    if(valor>=NOTADE100){
        printf("100: %d\n", valor/NOTADE100);
        valor=valor%NOTADE100;
    }else{
        printf("100: 0\n");
    }
    if(valor>=NOTADE50){
        printf("50: %d\n", valor/NOTADE50);
        valor=valor%NOTADE50;
    }else{
        printf("50: 0\n");
    }
    if(valor>=NOTADE20){
        printf("20: %d\n", valor/NOTADE20);
        valor=valor%NOTADE20;
    }else{
        printf("20: 0\n");
    }
    if(valor>=NOTADE10){
        printf("10: %d\n", valor/NOTADE10);
        valor=valor%NOTADE10;
    }else{
        printf("10: 0\n");
    }
    if(valor>=NOTADE5){
        printf("5: %d\n", valor/NOTADE5);
        valor=valor%NOTADE5;
    }else{
        printf("5: 0\n");
    }
    if(valor>=NOTADE2){
        printf("2: %d\n", valor/NOTADE2);
        valor=valor%NOTADE2;
    }else{
        printf("2: 0\n");
    }
    if(valor>=NOTADE1){
        printf("1: %d\n", valor/NOTADE1);
        valor=valor%NOTADE1;
    }else{
        printf("1: 0\n");
    }

    return SUCESSO;
}