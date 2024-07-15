#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO_NOME_ARQUIVO 30
#define TAMANHO_NOME_PRODUTO 100
#define TAMANHO_ESTADO 20
#define SUCESSO 0
typedef struct Produto{
    int codigo;
    char nome[TAMANHO_NOME_PRODUTO];
    int quantidade;
    double preco;
    char estado[TAMANHO_ESTADO];
}Produto;
void imprimeProdutos(Produto* produtos, int quant){
    int i;
    for(i=0;i<quant;i++){
        printf("%d\n%s%d\n%.2lf\n%s", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].estado);
    }
}
//garante que todas as strings de estado tenham uma  quabra de linha
void garanteQubraDeLinha(char string[TAMANHO_ESTADO]){
    int i;
    if(string[strlen(string)-1]!='\n'){
        string[strlen(string)]='\n';
        string[strlen(string)+1]='\0';
    }
}
//função que lê do arquivo de entrada os produtos em estoque e guarda no array produtos
void LeProdutosDoArquivo(Produto* produtos, int quantidadeProdutos, FILE* arquivo){
    int i;
    char linha[TAMANHO_NOME_ARQUIVO];
    for(i=0;i<quantidadeProdutos;i++){
        fscanf(arquivo, "%d\n", &produtos[i].codigo);
        fgets(produtos[i].nome, TAMANHO_NOME_PRODUTO, arquivo);
        fscanf(arquivo, "%d\n", &produtos[i].quantidade);
        fgets(linha, TAMANHO_NOME_ARQUIVO, arquivo);
        produtos[i].preco=atof(linha);
        fgets(produtos[i].estado, TAMANHO_ESTADO, arquivo);
        garanteQubraDeLinha(produtos[i].estado);

    }
    //imprimeArquivo(produtos, quantidadeProdutos);
}
//Ordena o vetor de produtos alfabeticamente antes de imprimir no arquivo de saída
void ordenacaoAlfabetica(Produto* produtos, int quantidadeProdutos){
    int i, j;
    Produto temp;
    for(i=0;i<quantidadeProdutos-1;i++){
        for (j=0;j<quantidadeProdutos-i-1;j++){
            if(strcmp(produtos[j].nome, produtos[j+1].nome)>0){
                temp=produtos[j];
                produtos[j]=produtos[j+1];
                produtos[j+1]=temp;
            }
        }
    }

}
//função que abre arquivo de saída e imprime os produtos em ordem alfabética 
void geraRelatorioDeEstoque(Produto* produtos, int quantidadeProdutos, char nomeRelatorio[TAMANHO_NOME_ARQUIVO]){
    FILE *arquivoRelatorio;
    int i;
    arquivoRelatorio=fopen(nomeRelatorio, "w");;
    if(arquivoRelatorio==NULL){
        exit(1);
    }

    ordenacaoAlfabetica(produtos, quantidadeProdutos);
    //fprintf(arquivoRelatorio,"%d\n", quantidadeProdutos);
    for(i=0;i<quantidadeProdutos;i++){
        fprintf(arquivoRelatorio,"%d\n", produtos[i].codigo);
        fputs(produtos[i].nome, arquivoRelatorio);
        fprintf(arquivoRelatorio,"%d\n", produtos[i].quantidade);
        fprintf(arquivoRelatorio,"%.2lf\n", produtos[i].preco);
        fputs(produtos[i].estado, arquivoRelatorio);
    }
}

int pesquisaPorCodigo(Produto* produtos, int codigo, int quantidadeProdutos){
    int i;
    for(i=0;i<quantidadeProdutos;i++){
        if(produtos[i].codigo==codigo){
            return i;
        }
    }
    return -1;
}

int descobreAqueleComMenorQuantidade(Produto* produtos,int quantidadeProdutos){
    imprimeProdutos(produtos, quantidadeProdutos);
    int i, indiceDoMenorQuantidade;
    indiceDoMenorQuantidade=0;
    for(i=0;i<quantidadeProdutos;i++){
        if(produtos[i].quantidade<produtos[indiceDoMenorQuantidade].quantidade){
            indiceDoMenorQuantidade=i;
        }
    }
    return indiceDoMenorQuantidade;
}

Produto* retornaVetorComProdutosDoEstado(char estado[TAMANHO_ESTADO], Produto* produtos, int quantProdutos){
    int quantProdutosEstado=0, i, j=0, ultimoIndice=0;
    Produto* produtosDoEstado;
    //coloca um \n em estado, uma vez que as string de estado também possuem
    estado[strlen(estado)]='\n';
    estado[strlen(estado)+1]='\0';
    //descoberta da quantidade de produtos para alocar memoria
    for(i=0;i<quantProdutos;i++){
        if(strcmp(produtos[i].estado, estado)==0){
            quantProdutosEstado++;
        }
    }
    produtosDoEstado=(Produto*)malloc(quantProdutosEstado*sizeof(Produto));
    for(i=0;i<quantProdutosEstado;i++){
        for(j=ultimoIndice;j<quantProdutos;j++){
            if(strcmp(produtos[j].estado,estado)==0){
                produtosDoEstado[i]=produtos[j];
                ultimoIndice++;
                break;
            }
            ultimoIndice++;
        }
    }
    return produtosDoEstado;
}
//função que cria um vetor com os produtos de cada estado e ordena eles em odem afabética
void imprimeProdutosPorEstadoAlfabeticamente(char estado[TAMANHO_ESTADO], Produto* produtos, int quantProdutos){
    Produto* produtosDoEstado;

    ordenacaoAlfabetica(produtosDoEstado, quantProdutosEstado);
    imprimeProdutos(produtosDoEstado, quantProdutosEstado);
}

int main(int argc, char*argv[]){
    char nomeArquivo[TAMANHO_NOME_ARQUIVO];
    FILE *arquivoEstoque;
    int quantProdutos, indiceProdutoAchado;
    Produto *produtosEmEstoque;
    //recebendo parâmetros 
    strcpy(nomeArquivo, argv[1]);
    int comando = atoi(argv[2]);
    //abrindo arquivo 
    arquivoEstoque=fopen(nomeArquivo, "r");
    
    if(arquivoEstoque==NULL){
        exit(1);
    }
    //busca da quantidade de produtos em estoque e alocação de memoria
    fscanf(arquivoEstoque, "%d", &quantProdutos);
    produtosEmEstoque= (Produto*)malloc(quantProdutos *sizeof(Produto));
   
    LeProdutosDoArquivo(produtosEmEstoque, quantProdutos, arquivoEstoque);
    switch (comando){
    case 1: 
        geraRelatorioDeEstoque(produtosEmEstoque, quantProdutos, argv[3]);
        break; 
    case 2:
        indiceProdutoAchado=pesquisaPorCodigo(produtosEmEstoque, atoi(argv[3]), quantProdutos);
        if(indiceProdutoAchado==-1){
            printf("Nao existe esse produto no estoque");
        }else{
            printf("%d\n%s%d\n%.2lf\n%s", produtosEmEstoque[indiceProdutoAchado].codigo, produtosEmEstoque[indiceProdutoAchado].nome, produtosEmEstoque[indiceProdutoAchado].quantidade, produtosEmEstoque[indiceProdutoAchado].preco, produtosEmEstoque[indiceProdutoAchado].estado);
        }
        break;
    case 3:
        indiceProdutoAchado=descobreAqueleComMenorQuantidade(produtosEmEstoque, quantProdutos);
        printf("codigo:%d\nnome:%squantidade:%d\npreco:%.2lf\nestado:%s", produtosEmEstoque[indiceProdutoAchado].codigo, produtosEmEstoque[indiceProdutoAchado].nome, produtosEmEstoque[indiceProdutoAchado].quantidade, produtosEmEstoque[indiceProdutoAchado].preco, produtosEmEstoque[indiceProdutoAchado].estado);
        break;
    case 4:
        imprimeProdutosPorEstadoAlfabeticamente(argv[3], produtosEmEstoque, quantProdutos);
        break;
    case 5:

        break;
    default:
        break;
    }
    //printf("%s %d", nomeArquivo, comando);
    free(produtosEmEstoque);
    fclose(arquivoEstoque);
    return SUCESSO;
}
