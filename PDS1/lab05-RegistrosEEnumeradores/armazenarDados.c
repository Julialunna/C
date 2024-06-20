#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define TAMANHO_MAXIMO_PESSOAS 5
#define TAMANHO_MAXIMO_NOME 50
#define NAO_SUCESSO -1
typedef struct enderecoDados{
    char rua[TAMANHO_MAXIMO_NOME];
    unsigned int numero;
    char estado[TAMANHO_MAXIMO_NOME];
}enderecoDados;
typedef struct dados{
    char nome[TAMANHO_MAXIMO_NOME];
    unsigned int idade;
    float salario;
    enderecoDados endereco;
}dados;
void inicializaVetor(dados vetorDados[TAMANHO_MAXIMO_PESSOAS]){
    int i;
    for(i=0;i<TAMANHO_MAXIMO_PESSOAS;i++){
        strcpy(vetorDados[i].nome, "");
        vetorDados[i].idade=0;
        vetorDados[i].salario=0.0;
    }
}
int confirmaSeTemEspaco(dados vetorDados[TAMANHO_MAXIMO_PESSOAS]){
    int i;
    for(i=0;i<TAMANHO_MAXIMO_PESSOAS;i++){
        if(strcmp(vetorDados[i].nome, "")==0){
            return i;
        }
    }
    return -1;
}
int achaRegistro(dados vetorDados[TAMANHO_MAXIMO_PESSOAS], char nomeRegistro[TAMANHO_MAXIMO_NOME]){
    int i;
    for(i=0;i<TAMANHO_MAXIMO_PESSOAS;i++){
        if(strcmp(vetorDados[i].nome, nomeRegistro)==0){ 
            return i;
        }
    }
    return NAO_SUCESSO;
}
void guardaPessoa(dados dadosDeEntrada, dados dadosFinal){
    strcpy(dadosFinal.nome, dadosDeEntrada.nome);
            dadosFinal.idade=dadosDeEntrada.idade;
            dadosFinal.salario=dadosDeEntrada.salario;
            strcpy(dadosFinal.endereco.rua, dadosDeEntrada.endereco.rua);
            dadosFinal.endereco.numero=dadosDeEntrada.endereco.numero;
            strcpy(dadosFinal.endereco.estado, dadosDeEntrada.endereco.estado);

}
int main(int argc, char** argv[]){
    char comando[10];
    dados dadosPessoas[TAMANHO_MAXIMO_PESSOAS], dadosEntrada;
    int resultadoEspaco, indiceRegistro;


    inicializaVetor(dadosPessoas);
    do{
        setbuf(stdin, NULL);
        fgets(comando, TAMANHO_MAXIMO_NOME, stdin);
        setbuf(stdin, NULL);
        if(strcmp(comando, "inserir\n")==0){
            scanf("%s %d %f %s %d %s", dadosEntrada.nome, &dadosEntrada.idade, &dadosEntrada.salario, dadosEntrada.endereco.rua, &dadosEntrada.endereco.numero, dadosEntrada.endereco.estado);
            resultadoEspaco=confirmaSeTemEspaco(dadosPessoas);
           if(resultadoEspaco==-1){
            printf("Espaco insuficiente\n");
           }else{

            strcpy(dadosPessoas[resultadoEspaco].nome, dadosEntrada.nome);
            dadosPessoas[resultadoEspaco].idade=dadosEntrada.idade;
            dadosPessoas[resultadoEspaco].salario=dadosEntrada.salario;
            strcpy(dadosPessoas[resultadoEspaco].endereco.rua, dadosEntrada.endereco.rua);
            dadosPessoas[resultadoEspaco].endereco.numero=dadosEntrada.endereco.numero;
            strcpy(dadosPessoas[resultadoEspaco].endereco.estado, dadosEntrada.endereco.estado);

            printf("Registro %s %d %.2f %s %d %s inserido\n",  dadosPessoas[resultadoEspaco].nome, dadosPessoas[resultadoEspaco].idade, dadosPessoas[resultadoEspaco].salario, dadosPessoas[resultadoEspaco].endereco.rua, dadosPessoas[resultadoEspaco].endereco.numero, dadosPessoas[resultadoEspaco].endereco.estado);
           }
        }else if(strcmp(comando, "mostrar\n")==0){
            scanf("%s", dadosEntrada.nome);
            indiceRegistro = achaRegistro(dadosPessoas, dadosEntrada.nome);
            if(indiceRegistro==NAO_SUCESSO){
                printf("Registro ausente\n");
            }else{
                
                printf("Registro %s %d %.2f %s %d %s\n",  dadosPessoas[indiceRegistro].nome, dadosPessoas[indiceRegistro].idade, dadosPessoas[indiceRegistro].salario, dadosPessoas[indiceRegistro].endereco.rua, dadosPessoas[indiceRegistro].endereco.numero, dadosPessoas[indiceRegistro].endereco.estado);
            }
        }else if(strcmp(comando, "alterar\n")==0){
            scanf("%s %d %f %s %d %s", dadosEntrada.nome, &dadosEntrada.idade, &dadosEntrada.salario, dadosEntrada.endereco.rua, &dadosEntrada.endereco.numero, dadosEntrada.endereco.estado);

            indiceRegistro = achaRegistro(dadosPessoas, dadosEntrada.nome);
            if(indiceRegistro==NAO_SUCESSO){
                printf("Registro ausente para alteracao\n");
            }else{
                strcpy(dadosPessoas[indiceRegistro].nome, dadosEntrada.nome);
                dadosPessoas[indiceRegistro].idade=dadosEntrada.idade;
                dadosPessoas[indiceRegistro].salario=dadosEntrada.salario;
                strcpy(dadosPessoas[indiceRegistro].endereco.rua, dadosEntrada.endereco.rua);
                dadosPessoas[indiceRegistro].endereco.numero=dadosEntrada.endereco.numero;
                strcpy(dadosPessoas[indiceRegistro].endereco.estado, dadosEntrada.endereco.estado);

                printf("Registro %s %d %.2f %s %d %s alterado\n",  dadosPessoas[indiceRegistro].nome, dadosPessoas[indiceRegistro].idade, dadosPessoas[indiceRegistro].salario, dadosPessoas[indiceRegistro].endereco.rua, dadosPessoas[indiceRegistro].endereco.numero, dadosPessoas[indiceRegistro].endereco.estado);
            }
            
        }
    }while(strcmp(comando, "inserir\n")==0||strcmp(comando, "mostrar\n")==0||strcmp(comando, "alterar\n")==0);
     
    return SUCESSO;
}