#include <stdio.h>
#define SUCESSO 0

int descobrePrimo(unsigned long long num) {
    unsigned long long i;
    if (num < 2) {
        return -1;
    } else if (num == 2) {
        return 1;
    } else {
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    unsigned long long num;
    int ehPrimo;
    while (scanf("%llu", &num) != EOF) {
        ehPrimo = descobrePrimo(num);
        printf("%d\n", ehPrimo);
    }
    
    return SUCESSO;
}
