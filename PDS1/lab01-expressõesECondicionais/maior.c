#include <stdio.h>
#define SUCESSO 0

//função que define qual o maior número
float encontraMaior(int num1, int num2, int num3){
    if(num1>=num2 && num1>=num3){
        return num1;
    }else if(num2>=num1 && num2>=num3){
        return num2;
    }else if(num3>=num1 && num3>=num2){
        return num3;
    }
}

int main(int argc, char** argv[]){
    int num1, num2, num3, maior;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    maior= encontraMaior(num1, num2, num3);
    
    printf("%d", maior);
    return SUCESSO;
}