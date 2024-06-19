#include <stdio.h>
#define TAMANHO_VETOR 10
#define SUCESSO 0

int main(int argc, char** argv[]){
	int fibonacci[TAMANHO_VETOR], n=0, i;
	
	//inicializa todas as casas do vetor com -1
	for(i=0;i<TAMANHO_VETOR;i++){
		fibonacci[i]=-1;
	}

	
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	
		
	//looping que recebe o valor de n até que n seja -1
	do{
		scanf("%d", &n);
		if(n<0){
			break;
		}
		//caso o valor de fibonacci[n] nçao seja -1 quer dizer que em algum momento ele já foi calculado
		if(fibonacci[n]!=-1){
			printf("%d\n", fibonacci[n]);
		}else{ 
			//caso não tenha sido esse for calcula 
			for(i=2;i<=n;i++){
				fibonacci[i]= fibonacci[i-1]+fibonacci[i-2];
			}
			printf("%d\n", fibonacci[n]);
		}
	}while(n>=0);

	return SUCESSO;
}
