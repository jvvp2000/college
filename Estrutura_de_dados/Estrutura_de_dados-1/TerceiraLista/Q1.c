#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "BST_ADT.h"

//TERMINAR - ACRESCENTAR TXT

typedef struct User {
	char* name;
  	int*  phoneNumber;
} USER;

int compareNodesPhoneNumbers (void* user1, void* user2) {

  	int key1 = *((int*)  ((USER*)user1)->phoneNumber);
  	int key2 = *((int*)  ((USER*)user2)->phoneNumber);

  
	if (key1 < key2) {
    	return -1;
  	}
  	if (key1 == key2) {
    	return 0;
  	}
  	return +1;
}



void printUserBST (void* user) {
	printf("Name: %s \t Phone Number: %d\n", *((char*)(((USER*)user)->name)), *((int*)(((USER*)user)->phoneNumber)));
}


void insertUser       (BST_TREE* RootPointer, int phone, char* name) {  

  	USER* userNode = (USER*) malloc (sizeof(USER));
	char* nameElem = (char*) malloc (sizeof(char));
  	int* phoneElem = (int*) malloc (sizeof(int));
  
  	if (!userNode) {
    	printf("Memory Overflow in add\n"),
    	exit(100);
  	} 
  	strcpy(nameElem, name);
  	*phoneElem = phone;
  	userNode->name = nameElem;
  	userNode->phoneNumber = phoneElem;
  	BST_Insert (RootPointer, userNode);
}


//void autoFillUserTree1   (BST_TREE* RootPointer) {
// 
//  	insertUser (RootPointer, "e", 5);
//  	insertUser (RootPointer, "c", 3);
//  	insertUser (RootPointer, "b", 2);
//		insertUser (RootPointer, "a", 1);
// 		insertUser (RootPointer, "d", 4);
// 	 	insertUser (RootPointer, "f", 6);
//  	insertUser (RootPointer, "g", 7);
//  	insertUser (RootPointer, "i", 9);
//  	insertUser (RootPointer, "h", 8);
//  	insertUser (RootPointer, "j", 10);
//  
//}
//
//void autoFillUserTree2   (BST_TREE* RootPointer)  {
// 
//  	insertUser (RootPointer, "h", 8);
//  	//ESQUERDA
//  	insertUser (RootPointer, "f", 6);
//  	insertUser (RootPointer, "g", 7);
//  	insertUser (RootPointer, "b", 2);
//  	insertUser (RootPointer, "a", 1);
//  	insertUser (RootPointer, "d", 4);
//  	insertUser (RootPointer, "c", 3);
//  	insertUser (RootPointer, "e", 5);
//  	//DIREITA
//  	insertUser (RootPointer, "i", 9);
//  	insertUser (RootPointer, "m", 13);
//  	insertUser (RootPointer, "k", 11);
//  	insertUser (RootPointer, "j", 10);
//  	insertUser (RootPointer, "l", 12);
//  	insertUser (RootPointer, "n", 14);
//  
//  
//}

void autoFillUserTree    (BST_TREE* RootPointer, int choice) {
  	switch (choice) {
    	case 1: autoFillTree1(RootPointer); break;
    	case 2: autoFillTree2(RootPointer); break;
  	}
}

void manualFillUserTree  (BST_TREE* RootPointer) {
  	int num=0;
  	char name[100];
  	printf("Digite o numero e, depois, o telefone;\n");
  	printf("Digite \"break\" para parar.\n");

  	do {
    	printf("\nDigite o nome de usuario: ");
    	scanf("%s", name);
    	if (strcmp(name, "break")==0) {
      		printf("\nDigite o telefone: ");
      		scanf("%d", &num);
      		insertUser(RootPointer, name, num);
    	} else {
      		printf("Acabou. Voltando\n");
    }
  	} while (strcmp(name, "break")==0);
}

void fillUserTree (BST_TREE* RootPointer, int isManual) {
  int choice=1;
  (isManual)?manualFillTree(RootPointer):autoFillTree(RootPointer,choice);
}

void printTree (BST_TREE* RootPointer) {

  printf("A arvore (%X) contem os usuarios:\n", RootPointer->root);
  BST_Traverse (RootPointer, printUserBST);
  printf("\n");
}

void removeUser (BST_TREE* RootPointer) {
  char name[100];
  printf("\n\n Digite o nome que gostaria de remover: ");
  scanf("%d", name);
  BST_Delete (RootPointer, (NODE*) checkUserTraversing (RootPointer, name));
}

void matches (void* nodeName) { //WIP
  	printf("Still WIP, don't bother\n\n");
}

void checkUserTraversing (BST_TREE* RootPointer, char* name) { 
  	BST_Traverse (RootPointer, matches); 
}


void checkUser (BST_TREE* RootPointer) { 
  	char name[100];
  	printf("\n\n Type the name you want to be checked: ");
  	scanf("%d", name);
  	checkUserTraversing (RootPointer, name);
}

void menu (BST_TREE* RootPointer) {
  
  	int choice=-1;
  	do {

    	printf("-> MENU <-\n\n");
    	printf("(Digite \"0\" para parar)\n");
    	printf("Digite \t para\n");
    	printf("1)\t digite um nome para saber se esta na arvore\n");
    	printf("2)\t inserir um novo usuario\n");
    	printf("3)\t remover um usuario existente digitando seu nome\n");
    	printf("4)\t mostrar a arvore\n");
    	scanf("%d", &choice);

    while ((choice>4)||(choice<0)) {
      	printf("Ai nao tem como!\t");
      	scanf("%d", &choice);
    }

    switch (choice) {
      	case 0: printf("Fechando menu\n\n"); break;

      	case 1: checkUser           (RootPointer);  break;
      	case 2: manualFillUserTree  (RootPointer);  break;
      	case 3: removeUser          (RootPointer);  break;
      	case 4: printTree           (RootPointer);  break;

      	default:printf("Ai nao da :(\n");    break;
    }
	} while (choice!=0);
}
