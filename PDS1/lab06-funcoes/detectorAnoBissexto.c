#include <stdio.h>
#define SUCESSO 0

int detectaAnoBissexto(int ano){
     if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char *argv[]) {
    int ano, resultado;
    while (scanf("%d", &ano) != EOF) {
        resultado = detectaAnoBissexto(ano);
        printf("%d\n", resultado);
    }
    return SUCESSO;
}
