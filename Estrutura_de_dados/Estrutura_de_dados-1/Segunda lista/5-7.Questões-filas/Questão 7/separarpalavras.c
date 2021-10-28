#include<stdio.h>
#include<stdlib.h>

int main()
{	
	FILE *arq;
	arq = fopen("arquivo.txt", "r");
	
	if(arq == NULL){
		printf("Erro na abertura!\n");
		system("pause");
		exit(1); //aborta o programa
	}
	
	char c;
	int i;
	
	for(i=1; i<=10; i++){
		
	}
	
	printf("%c");
	
	int fclose(FILE *arq); //retorna zero no caso de sucesso no fechamento do arquivo
		
	system("pause");
	return 0;
}
