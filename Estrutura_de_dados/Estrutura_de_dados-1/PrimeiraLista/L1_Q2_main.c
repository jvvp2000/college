#include <stdio.h>
#include <stdlib.h>
#include "L1_Q2_func.c"

void main(){
	
	MainN* list1=CreateEmptyList();		//Criar um conjunto vazio.
	
	InsertElement(list1,15);			//Inserir um elemento no conjunto.
	
	InsertElement(list1,28);
	
	InsertElement(list1,54);
	
	RemoveLastElement(list1);			//Remover um elemento no conjunto.

	CheckNumber(list1,28);				//Testar se um numero pertence ao conjunto.
	
	SmallestValue(list1);				//Menor valor do conjunto.

	MainN* list2=CreateEmptyList();	

	InsertElement(list2,88);

	InsertElement(list2,63);

	MainN* list3=CreateEmptyList();	

	Concatenate(list1,list2,list3);		//Uniao de dois conjuntos.

	CheckEquality(list1,list2);			//Testar se os dois conjuntos sao iguais.

	CheckEmpty(list1);					//Testar se o conjunto e vazio.
	
}
