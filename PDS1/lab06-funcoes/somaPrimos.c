#include <stdio.h>
#define SUCESSO 0

int Primo(unsigned int num) {
    int i;
    if (num < 2) {
        return -1;
    } else if (num == 2) {
        return 1;
    } else {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}

unsigned long long int Soma_Primos(int quantPrimos) {
    unsigned long long int resultado = 0;
    unsigned int primo = 1;
    int i;

    for (i = 0; i < quantPrimos; i++) {
        do {
            primo++;
        } while (Primo(primo) != 1);
        resultado += primo;
    }
    return resultado;
}

int main(int argc, char *argv[]) {
    int quantPrimos;
    unsigned long long int resultado;
    while (scanf("%d", &quantPrimos) != EOF) {
        resultado = Soma_Primos(quantPrimos);
        printf("%llu\n", resultado);
    }
    return SUCESSO;
}
