#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "BST_ADT.h"

 
int   compareInt (void* num1, void* num2);
void  printBST   (void* num1);

void  insertInt     (BST_TREE* RootPointer, int num);
void  autoFillTree1 (BST_TREE* RootPointer);
void  autoFillTree2 (BST_TREE* RootPointer);
void  autoFillTree  (BST_TREE* RootPointer, int choice);
void  manualFillTree(BST_TREE* RootPointer);
void  fillTree      (BST_TREE* RootPointer, int isManual);
void  printTree     (BST_TREE* RootPointer);
int   bigger        (int Left, int Right);
int   _longestBranch (NODE* Tree);
int   SolveBinaryTreeBalanceFactor (BST_TREE* RootPointer, NODE* treeRoot);
void  BinaryTreeBalanceFactor (BST_TREE* tree);
void  q2 ();

int main () {
  q2();
}


int compareInt (void* num1, void* num2) {
  int key1 = *((int*) num1);
  int key2 = *((int*) num2);

  if (key1 < key2) {
    return -1;
  }
  if (key1 == key2) {
    return 0;
  }
  return +1;
}

void printBST (void* num1) {
  printf("%4d\n", *(int*)num1);
  return; 
}


void insertInt       (BST_TREE* RootPointer, int num) {
  
  int* x = (int*) malloc (sizeof(int));
 
  if (!x) {
    printf("Memory Overflow\n"),
    exit(100);
  } 
  *x = num;
  BST_Insert (RootPointer, x);
}

void autoFillTree1   (BST_TREE* RootPointer) {

  insertInt (RootPointer, 5);
  insertInt (RootPointer, 3);
  insertInt (RootPointer, 2);
  insertInt (RootPointer, 1);
  insertInt (RootPointer, 4);
  insertInt (RootPointer, 6);
  insertInt (RootPointer, 7);
  insertInt (RootPointer, 9);
  insertInt (RootPointer, 8);
  insertInt (RootPointer, 10);
  
}

void autoFillTree2   (BST_TREE* RootPointer)  {


  insertInt (RootPointer, 8);
  //ESQUERDA
  insertInt (RootPointer, 6);
  insertInt (RootPointer, 7);
  insertInt (RootPointer, 2);
  insertInt (RootPointer, 1);
  insertInt (RootPointer, 4);
  insertInt (RootPointer, 3);
  insertInt (RootPointer, 5);
  //DIREITA
  insertInt (RootPointer, 9);
  insertInt (RootPointer, 13);
  insertInt (RootPointer, 11);
  insertInt (RootPointer, 10);
  insertInt (RootPointer, 12);
  insertInt (RootPointer, 14);
  
  
}

void autoFillTree    (BST_TREE* RootPointer, int choice) {
  switch (choice) {
    case 1: autoFillTree1(RootPointer); break;
    case 2: autoFillTree2(RootPointer); break;
  }
}

void manualFillTree  (BST_TREE* RootPointer) {
  int num=0;

  printf("\n");
  printf("\n");

  do {
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num > -1) {
      insertInt(RootPointer, num);
    }
  } while (num > -1);
}

void fillTree (BST_TREE* RootPointer, int isManual) {
  int choice=1;
  (isManual)?manualFillTree(RootPointer):autoFillTree(RootPointer,choice);
}

void printTree(BST_TREE* tree) {

  printf("A arvore (%X) e\n", tree->root);
  BST_Traverse (tree, printBST);
  printf("\n");
}

int  bigger (int Left, int Right) {
  return ((Left>=Right)?Left:Right);
}

int  _longestBranch (NODE* rootPointer) {
  if (rootPointer == NULL) {
    return 0;
  }
  return bigger(_longestBranch(rootPointer->left), _longestBranch(rootPointer->right)) + 1;
}

int  SolveBinaryTreeBalanceFactor (BST_TREE* tree, NODE* treeRoot) { //WHY DO I NEED BST_TREE?
  
  return _longestBranch(tree->root->left) - _longestBranch(treeRoot->right);
}

void BinaryTreeBalanceFactor (BST_TREE* tree) {
  printf("O fator de balanco da arvore (%X) e %d\n", (int*) tree->root, SolveBinaryTreeBalanceFactor (tree, tree->root));
}

void q2 () {
  
  int isManual=0;
  BST_TREE* tree = BST_Create(compareInt);
  fillTree(tree, isManual);
  // printTree (tree);
  BinaryTreeBalanceFactor (tree);
  BST_Destroy (tree);

}

