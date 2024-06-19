#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define TAMANHO_MAXIMO_TABULEIRO 100
#define QUANTIDADE_DE_COORDENADAS 2
#define PERDEU 1
#define NAO_PERDEU 0
#define NAO_TERMINOU 2
#define TAMANHO_MAXIMO_LINHA 201
void imprimirMatriz(char tabuleiro[100][100], int tamanhoMatriz){
    int j, k;
        for(j=0;j<tamanhoMatriz;j++){ 
            for(k=0;k<tamanhoMatriz;k++){
                printf("%c ",tabuleiro[j][k]);
            }
            printf("\n");
        }
}
//função que guarda na matriz apenas os caracteres de interesse: x e b
void criaLinhaDoTabuleiro(char matriz[TAMANHO_MAXIMO_TABULEIRO][TAMANHO_MAXIMO_TABULEIRO], char linha[TAMANHO_MAXIMO_LINHA], int j){
    int k, indiceColuna=0;
    for(k=0;k<strlen(linha);k++){
            if(linha[k]=='x'|| linha[k]=='b'){
                matriz[j][indiceColuna]=linha[k];
                indiceColuna++;
            }
        }
}
int processaJogada(int coordenadasJogada[2], char tabuleiro[TAMANHO_MAXIMO_TABULEIRO][TAMANHO_MAXIMO_TABULEIRO], int tamanho){
    //confere se a casa não tem bomba
    if(tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]]=='b'){
      
        return PERDEU;
    }else{
        
        //caso não tenha bomba, define que a casa foi revelada
        tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]]='r';
        //if que confere se todas as casas ao redor não têm bomba
        if((tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]]!='b')
        &&(tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]+1]!='b')
        &&(tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]+1]!='b')
        &&(tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]]!='b')
        &&(tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]-1]!='b')
        &&(tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]-1]!='b')
        &&(tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]-1]!='b')
        &&(tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]+1]!='b')){
            
            if(tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]]=='x'){
                tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]]='r';
                
            }
            if(tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]+1]=='x'){
                tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]+1]='r';
               
            }
            if(tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]+1]=='x'){
                tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]+1]='r';

            }
            if(tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]]=='x'){
                tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]]='r';
            }if(tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]-1]=='x'){
                tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]-1]='r';
            }
            if(tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]-1]=='x'){
                tabuleiro[coordenadasJogada[0]][coordenadasJogada[1]-1]='r';
            }
            if(tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]-1]=='x'){
                tabuleiro[coordenadasJogada[0]+1][coordenadasJogada[1]-1]='r';
                
            }
            if(tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]+1]=='x'){
                tabuleiro[coordenadasJogada[0]-1][coordenadasJogada[1]+1]='r';
            }
        }
        return NAO_PERDEU;
    }

}
int confereSeTerminou(char tabuleiro[TAMANHO_MAXIMO_TABULEIRO][TAMANHO_MAXIMO_TABULEIRO], int tamanho){
    int i, j;
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            if(tabuleiro[i][j]=='x'){
                return NAO_TERMINOU;
            }
        }
    }
    return NAO_PERDEU;

}
int main(int argc, char** argv[]){
    int quantJogos, tamanhoTabuleiro, i, j, quantJogadas, coordenadasJogada[QUANTIDADE_DE_COORDENADAS], perdeu=0, numJogadas;
    char tabuleiro[TAMANHO_MAXIMO_TABULEIRO][TAMANHO_MAXIMO_TABULEIRO], linha[TAMANHO_MAXIMO_LINHA];

    scanf("%d", &quantJogos);
    //looping que cria a quantidade de jogos que o usuário pediu
    for(i=0;i<quantJogos;i++){
        perdeu=0;
        scanf("%d", &tamanhoTabuleiro);
        setbuf(stdin, NULL);
       for(j=0;j<tamanhoTabuleiro;j++){
        //lê-se duas vezes o numero de colunas da matriz, pois considera-se um espaço entre cada caractere e o \n no final 
        fgets(linha, TAMANHO_MAXIMO_LINHA, stdin);
        setbuf(stdin, NULL);
        criaLinhaDoTabuleiro(tabuleiro, linha, j);
       }
      
       scanf("%d", &numJogadas);
       for(j=0;j<numJogadas;j++){
        scanf("%d %d", &coordenadasJogada[0],&coordenadasJogada[1]);
        if(perdeu!=1){
        perdeu = processaJogada(coordenadasJogada, tabuleiro, tamanhoTabuleiro);
        }
       }
       if(perdeu!=PERDEU){
        perdeu=confereSeTerminou(tabuleiro, tamanhoTabuleiro);
       }
       
       if(perdeu==1){
        printf("PERDEU\n");
       }else if(perdeu ==2){
        printf("FALTOU TERMINAR\n");
       }else if(perdeu ==0){
        printf("GANHOU\n");
       }
       
        
    }

    return SUCESSO;
}


















