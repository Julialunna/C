#include <stdio.h>
#define SUCESSO 0

int ehPrimo(int p){
    int i;
    if(p==2){
        return 1;
    }else if(p==1){
        return 0;
    }
    for(i=2;i<p/2;i++){
        //printf("ehprimo %d %d\n", p, i);
        if(p%i==0){
            return 0;
        }
    }
    return 1;
}

void primos(int m, int *p1, int *p2){
    int i, resultado;
    for(i=1;i<m;i++){
        if(ehPrimo(i)==1){
            *p1=i;
        }
    }
    i=m;
    do{
        i++;
    }while(ehPrimo(i)==0);
    *p2=i;
}
int main(int argc, char**argv[]){
    int m, p1, p2;
    scanf("%d", &m);
    primos(m, &p1, &p2);
    printf("%d\n", p1);
    printf("%d\n", p2);
    return SUCESSO;
}
