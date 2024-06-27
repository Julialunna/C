//01 01 2020 deveria dar 260 e no teste da 261
#include <stdio.h>
#define SUCESSO 0
#define DATA_DIA 17
#define DATA_MES 09
#define DATA_ANO 2020
#define DATA_DIAS_JA_PASSADOS 261
int contaDias(int dia, int mes, int ano){
    int i, resultado=0, diasPassados=0;
    int meses[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(i=ano;i<DATA_ANO;i++){
        if(((i+1) % 4 == 0 && (i+1) % 100 != 0) || ((i+1) % 400 == 0)){
            //printf("366%d\n", i+1);
            resultado+=366;
        }else{
            //printf("365%d\n", i+1);
            resultado+=365;
        }
    }
    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        meses[1]=29;
        resultado++;
    }

    for(i=0;i<mes-1;i++){
        diasPassados+=meses[i];
    }
    diasPassados+=dia;
    //printf("a%d b%d\n", diasPassados, resultado);

    if(diasPassados<DATA_DIAS_JA_PASSADOS){
        //printf("menor");
        resultado=resultado+(DATA_DIAS_JA_PASSADOS-diasPassados);
    }else{
        //printf("maior");
        resultado=resultado-(diasPassados-DATA_DIAS_JA_PASSADOS);
    }

    return resultado;
}


int main(){
    int dia, mes, ano, numDias;
    while(scanf("%d %d %d", &dia, &mes, &ano)!=EOF){
    numDias=contaDias(dia, mes, ano);
    printf("%d\n", numDias);
    }
    return SUCESSO;

}