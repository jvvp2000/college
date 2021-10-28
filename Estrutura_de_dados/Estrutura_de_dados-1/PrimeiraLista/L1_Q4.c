#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Clientes{
	char codigo[6];
	char nome[30];
	char endereco[40];
	char telefone[11];
	char data_prim[8];
	char data_ult[8];
	char valor_ult[9];
		
} clientes; 
	
	
int main(){

	int opt=0;

voltar:	

	printf ("Escolha uma das opcoes: \n 1. Inserir dados \n 2. Consultar dados \n 3. Excluir dados \n \n");
	scanf ("%d", &opt);
	
	switch(opt){
		
	case 1:{
	
		int opt1=0;
		int cod_pes=0, info_pes=0;
	
		printf ("Voce escolheu - Inserir dados \n \n Escolha uma dentre as seguintes opcoes: \n 1. Inserir um dado de uma pessoa \n 2. Inserir uma pessoa \n 3. Voltar para o menu anterior \n \n");		
		scanf ("%d", &opt1);
		
		switch(opt1){
			case 1:{
											
				printf ("Voce escolheu - Inserir um dado de uma pessoa \n \n Digite o codigo da pessoa que deseja inserir um dado:  \t");
				scanf ("%d", &cod_pes);
				
				
				
								
				break;
			}
			case 2:{
				
				int cod;
				
				printf ("Voce escolheu - Inserir uma pessoa \n \n Preencha as seguintes informacoes:");
				scanf ("%d", &info_pes);

				break;
			}
			case 3:{
				
				goto voltar;
				
				break;
			}
			default:{

				printf ("Ai nao");

				break;
			}
				
		}
		
		break;

	}
	case 2:{

		int opt2=0;
		int cod=0;
				
		printf ("Voce escolheu - Consultar dados \n \n Escolha uma das seguintes opcoes: \n 1. Consultar dados \n 2. Voltar para o menu anterior \n");	
		scanf ("%d", &opt2);
		
		switch(opt2){
		
			case 1:{
							
				printf ("Voce escolheu - Consultar dados \n \n Digite o codigo da pessoa que deseja  consultar: \t");	
				scanf ("%d", &cod);
				
				break;
			}
			case 2:{
				
				goto voltar;
				
				break;
			}
			default:{

				printf ("Ai voce me quebra meu parceiro");

				break;
		
			}
		
		}

		break;

	}

	case 3:{
	
		int opt3=0;
		int cod=0;
		
		printf ("Voce escolheu - Excluir dados \n \n Escolha uma das seguintes opcoes: \n 1. Excluir um dado de uma pessoa \n 2. Excluir uma pessoa \n 3. Voltar para o menu anterior \n");	
		scanf ("%d", &opt3);
		
		switch(opt3){
							
			case 1:{
												
				printf ("Voce escolheu - Excluir um dado de uma pessoa \n \n Digite o codigo da pessoa que deseja  excluir: \n");	
				scanf ("%d", &cod);
				
				break;
			}
			case 2:{
				
				printf ("Voce escolheu - Excluir uma pessoa \n \n Digite o codigo da pessoa que deseja excluir: \t");
				scanf ("%d", &cod);
				
				break;
			}
			case 3:{
				
				goto voltar;
				
				break;
			}
			default:{

				printf ("Ai voce me quebra meu parceiro");

				break;
		
			}
	
		break;
		}
			
	}
	default:{

		printf ("Ai voce me quebra meu parceiro");

		break;
		
	}

}
		
}
