#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SUCESSO 0

int main(int argc, char**argv[]){
   char S[30], C1, C2;
   int i;
   fgets(S, 30, stdin);
   scanf("%c", &C1);
   setbuf(stdin, NULL);
   scanf("%c", &C2);
   for(i=0;i<strlen(S)-1;i++){
    if(S[i]==C1){
        S[i]=C2;
        break;
    }
   }
   printf("%s", S);
   return SUCESSO;
}