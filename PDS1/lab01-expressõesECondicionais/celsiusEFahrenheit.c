#include <stdio.h>
#define SUCESSO 0

//função que converte celsius em fahrenheit
float calculaFahrenheit(float celsius){
    return (celsius*1.8+32);
}

int main(int argc, char** argv[]){
    float celsius, fahrenheit;

    scanf("%f", &celsius);

    fahrenheit = calculaFahrenheit(celsius);
    
    printf("%.0f", fahrenheit);
    return SUCESSO;
}