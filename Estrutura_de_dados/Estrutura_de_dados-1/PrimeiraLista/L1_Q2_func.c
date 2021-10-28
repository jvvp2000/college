#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	
	int intValue;
	
	struct Node* next;

}N;

typedef struct MainNode{
	
	int listLength;
	N* first;
	N* last;

}MainN;

MainN* 	CreateEmptyList(){												//Criar uma lista vazia.

	MainN* ponteiro = (MainN*) malloc (sizeof(MainN));

	ponteiro->first=NULL;
	ponteiro->last=NULL;
	ponteiro->listLength=0;

	return ponteiro;

}

void ShowList (MainN* mainponteiro){						//Mostrar lista

	int loopCounter;

	N* nodeponteiro=mainponteiro->first;

	printf("(");

	for(loopCounter=0;loopCounter<mainponteiro->listLength;loopCounter++){
		
		printf("%d", nodeponteiro->intValue);

		if(loopCounter!=(mainponteiro->listLength-1)){
	
			printf("/");

		}

		nodeponteiro=nodeponteiro->next;

	}
	
	printf(")\n");

}

void InsertElement (MainN* mainponteiro, int numberToInsert){	//Inserir um elemento no conjunto.
	
	int isANewValue=1;
	int loopCounter;

	N* nodeponteiro=mainponteiro->first;

	for(loopCounter=0;loopCounter<mainponteiro->listLength;loopCounter++){
	
		if(nodeponteiro->intValue==numberToInsert){
		
			isANewValue=0;
	
		}
	
		nodeponteiro=nodeponteiro->next;

	}

	if(isANewValue){

		struct Node* NewElem = (N*) malloc (sizeof(N));

		NewElem->intValue=numberToInsert;
		NewElem->next=NULL;

		if (mainponteiro->listLength==0){

			mainponteiro->listLength=1;
			mainponteiro->first=NewElem;
			mainponteiro->last=NewElem;

		}

		else{

			mainponteiro->listLength++;
			mainponteiro->last->next=NewElem;
			mainponteiro->last=NewElem;

		}

		printf("Digite um elemento: %d. Lista:\t", numberToInsert);

		ShowList(mainponteiro);
			
	}else{
	
		printf("O valor %d ja existe.\n", numberToInsert);

	}

}

void RemoveLastElement (MainN* mainponteiro){						//Remover um elemento do conjunto.
	
	if(mainponteiro->listLength>0){

		free(mainponteiro->last);
	
		mainponteiro->listLength--;
		
		int loopCounter;
		
		N* nodeponteiro=mainponteiro->first;
		
		for (loopCounter=1;loopCounter<mainponteiro->listLength;loopCounter++){
		
			nodeponteiro=nodeponteiro->next;
	
		}
	
		nodeponteiro->next=NULL;
	
		mainponteiro->last=nodeponteiro;

	}else{
	
		printf("Nao tem como remover.\n");

	}

}
			
void CheckNumberIndex (MainN* mainponteiro, int numberToCheck){	//Testar se um numero pertence ao conjunto.

	int loopCounter;

	N* nodeponteiro=mainponteiro->first;

	printf("Achei! Esta no indice: ");

	for(loopCounter=0;loopCounter<mainponteiro->listLength;loopCounter++){
	
		if(nodeponteiro->intValue==numberToCheck){	
		
			printf("%d\n", loopCounter);
	
		}
	
		nodeponteiro=nodeponteiro->next;
	}

}

void CheckNumber (MainN* mainponteiro, int numberToCheck){	//Testar se um numero pertence ao conjunto.

	int loopCounter, checkCounter=0;

	N* nodeponteiro=mainponteiro->first;
	
	for(loopCounter=0;loopCounter<mainponteiro->listLength;loopCounter++){
	
		if(nodeponteiro->intValue==numberToCheck){
	
			checkCounter+=1;
	
		}
	
		nodeponteiro=nodeponteiro->next;

	}
	
	if (checkCounter == 0){

		printf("%d nao foi achado na lista...\n", numberToCheck);

	}else if (checkCounter>0){

		printf("%d foi achado na lista... ", numberToCheck);
		CheckNumberIndex(mainponteiro, numberToCheck);

	}else{
	
		printf("Ai complica cumpade \n");
	
	}

}

void SmallestValue (MainN* mainponteiro){						//Menor valor do conjunto.

	N* nodeponteiro=mainponteiro->first;

	int loopCounter, smallest=nodeponteiro->intValue ;

	for(loopCounter=0;loopCounter<mainponteiro->listLength;loopCounter++){
		
		if(nodeponteiro->intValue<smallest){
	
			smallest=nodeponteiro->intValue;
	
		}
		
		nodeponteiro=nodeponteiro->next;
	}

	printf("Menor valor da lista: %d\n", smallest);

}

void	Concatenate			(MainN* mainponteiro1, MainN* mainponteiro2, MainN* mainponteiro3){		//Uniao de dois conjuntos.
	
	int loopCounter;
	
	N* nodeponteiro;
	
	nodeponteiro=mainponteiro1->first;
	
	for(loopCounter=0;loopCounter<mainponteiro1->listLength;loopCounter++){
	
		InsertElement(mainponteiro3, nodeponteiro->intValue);
		nodeponteiro=nodeponteiro->next;

	}
	
	nodeponteiro=mainponteiro2->first;
	
	for(loopCounter=0;loopCounter<mainponteiro2->listLength;loopCounter++){
	
		InsertElement(mainponteiro3, nodeponteiro->intValue);
		nodeponteiro=nodeponteiro->next;
	
	}
	
}

void CheckEquality (MainN* mainponteiro1, MainN* mainponteiro2){	//Testar se os dois conjuntos sao iguais.
	
	if (mainponteiro1->listLength==mainponteiro2->listLength){
		
		int loopCounter1, loopCounter2, hasSameElement1=0, hasSameElement2=0;
	
		N* nodeponteiro1;
		N* nodeponteiro2;
		
		nodeponteiro1=mainponteiro1->first;
		nodeponteiro2=mainponteiro2->first;
		
		for(loopCounter1=1;loopCounter1<=mainponteiro1->listLength;loopCounter1++){
		
			for(loopCounter2=1;loopCounter2<=mainponteiro2->listLength;loopCounter2++){

				if(nodeponteiro1->intValue==nodeponteiro2->intValue){
				
					hasSameElement1+=1;
				
					break;
			
				}
			
				nodeponteiro2=nodeponteiro2->next;
		
			}
		
			nodeponteiro2=mainponteiro2->first;
			nodeponteiro1=nodeponteiro1->next;
		
		}
			
		nodeponteiro1=mainponteiro1->first;
		nodeponteiro2=mainponteiro2->first;
		
		for(loopCounter2=1;loopCounter2<=mainponteiro2->listLength;loopCounter2++){
			
			for(loopCounter1=1;loopCounter1<=mainponteiro1->listLength;loopCounter1++){

				if(nodeponteiro1->intValue==nodeponteiro2->intValue){
					
					hasSameElement2+=1;
					
					break;
				
				}
			
				nodeponteiro1=nodeponteiro1->next;
			
			}
			
			if(hasSameElement2==loopCounter2){
		
			nodeponteiro1=mainponteiro1->first;
			nodeponteiro2=nodeponteiro2->next;
	
		}
		
		if((hasSameElement1==hasSameElement2)&&((hasSameElement1>0)&&(hasSameElement2>0))){
		
			printf("As listas sao iguais!\n");
	
		}else{
		
			printf("As listas sao diferentes!\n");
		
		}
	
	}

	}else{
	
		mainponteiro1->listLength++;
		mainponteiro2->listLength++;
		printf("As listas nao sao iguais. Tamanhos diferentes = (%d, %d)\n", mainponteiro1->listLength, mainponteiro2->listLength);
	
	}

}
void CheckEmpty (MainN* mainponteiro){						//Testar se o conjunto e vazio.

	if (mainponteiro->listLength==0){
	
		printf("Contem 0 elementos (%d), ",mainponteiro->listLength);
	
		if (mainponteiro->first==NULL){
		
			printf("Sem primeiro (%X), ", mainponteiro->first);
		
			if (mainponteiro->last==NULL){
		
				printf("Sem ultimo (%X), ",mainponteiro->last);
				printf("A lista (%X) esta vazia. \n", mainponteiro);
		
			}else{
			
				printf("Lista (%X) tem um ultimo elemento (%X), entao nao esta vazia.\n", mainponteiro, mainponteiro->last);
		
			}
	
		}else{
			
			printf("Lista (%X) tem um primeiro elemento (%X), entao nao esta vazia.\n", mainponteiro, mainponteiro->first);
	
		}	

	}else{
	
		printf("Lista (%X) tem tamnho (%d), entao nao esta vazia.\n", mainponteiro, mainponteiro->listLength);
	
	}	

}
void Clean (MainN* mainponteiro){
	
	printf("Limpando lista %X gente boa!\n", mainponteiro);

	int loopCounter;

	N* nodeponteiro=mainponteiro->first;
	N* lastNodeponteiro;

	for(loopCounter=1;loopCounter<mainponteiro->listLength;loopCounter++){

		lastNodeponteiro=nodeponteiro;
	
		nodeponteiro=nodeponteiro->next;
		
		free(lastNodeponteiro);
	
	}

	free(mainponteiro);
	free(nodeponteiro);
	free(lastNodeponteiro);
	
	printf("Limpada\n");

}

void RunList(MainN* mainponteiro){

	int loopCounter;

	N* nodeponteiro=mainponteiro->first;

	for(loopCounter=0;loopCounter<mainponteiro->listLength;loopCounter++){
		
		nodeponteiro=nodeponteiro->next;
		
	}
}


