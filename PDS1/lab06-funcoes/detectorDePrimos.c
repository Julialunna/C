#include <stdio.h>
#define SUCESSO 0;

int descobrePrimo(unsigned int num){
    int i;
    if(num<2){
        return -1;
    }else if(num ==2){
        return 1;
    }{
        for(i=2;i<num/2;i++){
            
            if(num%i==0){
                return 0;
            }else{
                continue;
            }
        }
    }
    return 1;
}
int main(int argc, char**argv[]){
    unsigned int num, ehPrimo=-2;
    do{
        scanf("%d", &num);
        ehPrimo=descobrePrimo(num);
        printf("%d\n", ehPrimo);
    }while(1);
    return SUCESSO;
}