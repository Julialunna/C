#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define QUANTIDADE_PRODUTOS 8
#define TAMANHO_STRINGS 50

typedef struct produto{
    char nome[TAMANHO_STRINGS];
    char marca[TAMANHO_STRINGS];
    float preco;
}produto;
typedef struct marca{
    char nome[TAMANHO_STRINGS];
    float precoSoma;
    int quantidadeProdutos;
}marca;
void calculaMediaTotal(produto produtos[QUANTIDADE_PRODUTOS]){
    int i;
    float soma=0.0;
    for(i=0;i<QUANTIDADE_PRODUTOS;i++){
        soma=soma+produtos[i].preco;
    }
    printf("media total %.2f\n", soma/QUANTIDADE_PRODUTOS);
}
void inicializaMarcas(marca marcas[QUANTIDADE_PRODUTOS]){
    int i;
    for(i=0;i<QUANTIDADE_PRODUTOS;i++){
        strcpy(marcas[i].nome, " ");
    }
}
int encontraMarca(produto produtoCadastrado, marca marcas[QUANTIDADE_PRODUTOS]){
    int i;
    for(i=0;i<QUANTIDADE_PRODUTOS;i++){
        if(strcmp(produtoCadastrado.marca,marcas[i].nome)==0){
            marcas[i].quantidadeProdutos++;
            marcas[i].precoSoma+=produtoCadastrado.preco;
            //printf("b %s %f %d",  marcas[i].nome, marcas[i].precoSoma, marcas[i].quantidadeProdutos);
            return SUCESSO;
        }
    }
    for(i=0;i<QUANTIDADE_PRODUTOS;i++){
        if(strcmp(marcas[i].nome, " ")==0){
            strcpy(marcas[i].nome, produtoCadastrado.marca);
            marcas[i].precoSoma=produtoCadastrado.preco;
            marcas[i].quantidadeProdutos=1;
            //printf("c %s %f %d",  marcas[i].nome, marcas[i].precoSoma, marcas[i].quantidadeProdutos);
            return SUCESSO;
        }
    }
}
void produzResultados(produto produtos[QUANTIDADE_PRODUTOS], marca marcas[QUANTIDADE_PRODUTOS]){
    int i;
    for(i=0;i<QUANTIDADE_PRODUTOS;i++){
        if(strcmp(marcas[i].nome, " ")==0){
            break;
        }else{
            printf("%s %d\n", marcas[i].nome, marcas[i].quantidadeProdutos);
        }
    }
    calculaMediaTotal(produtos);
    for(i=0;i<QUANTIDADE_PRODUTOS;i++){
        if(strcmp(marcas[i].nome, " ")==0){
            break;
        }else{
            printf("media %s %.2f\n", marcas[i].nome, marcas[i].precoSoma/marcas[i].quantidadeProdutos);
        }
    }
}
int main(int argc, char**argv[]){
    int i;
    marca marcas[QUANTIDADE_PRODUTOS];
    produto produtosCadastrados[QUANTIDADE_PRODUTOS];
    inicializaMarcas(marcas);
    for(i=0;i<QUANTIDADE_PRODUTOS;i++){
        scanf("%s %s %f", produtosCadastrados[i].nome, produtosCadastrados[i].marca, &produtosCadastrados[i].preco);
        encontraMarca(produtosCadastrados[i], marcas);
    }
    produzResultados(produtosCadastrados, marcas);
    
    return SUCESSO;
}