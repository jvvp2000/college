#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../TAD-pilha/pilhatad.h"



void  printString      (char* string) {  
  printf(">%s<\n", string);
}

void  selectString     (int choice, char* string) {   

  switch (choice) {
    case 1:   strcpy(string,      "A diva em Argel alegra-me a vida.");                    break;
    case 2:   strcpy(string,      "A base do teto desaba.");         break;
    case 3:   strcpy(string,      "Adias a data da saida.");                    break;
    case 4:   strcpy(string,      "Socorram-me, subi no onibus em Marrocos.");  break;
    default:  strcpy(string,      ""); break;
  }

}

bool  isBetween        (int n, int min, int max) {
  return ((min <= n) && (n <= max));
}

bool  isAlpha          (int n) {
  return (isBetween(n,65,90)||isBetween(n,97,122));
}

void  cleanSpecialChar (char* s) {    
  int i;
  for (i=0; i<=(int) strlen(s);i++) {  
   
    if (!(isBetween(s[i],65,90)||isBetween(s[i],97,122)||s[i]=='\0')) {
      s[i] = ' ';
    }
  }
  printf("Limpando caracteres nao essenciais:\t");
  printString(s);
}

int   alphaSize        (char* s) {
  int i, cont=0;
  for (i=0; i<=(int) strlen(s);i++) {  
    if (isAlpha(s[i])) {
      cont++;
    }
  }
  return cont;
}

int   spaceCount       (char* s) {
  int i, cont=0;
  for (i=0; i<=(int) strlen(s);i++) {  
    if (s[i]==' ') {
      cont++;
    }
  }
  return cont;
}

void  swap             (int* a, int* b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void  spacelessSwap    (char* s) {            
  
  int i=0, j, spaces=spaceCount(s);
  do {
  
       
    if (s[i]==' ') {
      for (j=i; j<(int) strlen(s);j++) {
      
     
        s[j]    = s[j] + s[j+1];
        s[j+1]  = s[j] - s[j+1];
        s[j]    = s[j] - s[j+1];

    
      }
      spaces--;
      i--;
    }
    i++;
  } while (spaces!=0);


  printf("Tirando os espacos:\t\t\t");
  printString(s);
}

void  turnLower        (char* s) {             
  int i;
  for (i=0;i<(int) strlen(s);i++) {
    if (isBetween(s[i],65,90)) {
      s[i] += 32;
    }
  }
  printf("Transformando em LowCase:\t\t");
  printString(s);
}

void  cleanString      (char* limpa, char* original) {   
  
  strcpy(limpa, original);
  
  printf("\n\n\nOriginal:\t\t\t\t");
  printString(limpa);

  cleanSpecialChar(limpa);        
  turnLower(limpa);             
  spacelessSwap(limpa);          

}

void  pushInt          (STACK* pilha, int dec) { 
  

  int* dataPtr;
  dataPtr =(int*) malloc (sizeof(int));

 
  *dataPtr = dec;


  pushStack(pilha, (void*) dataPtr);
 
}

int   popInt           (STACK* pilha) { 
  void* aux;
  aux = popStack(pilha);

  int* intPtr = (int*) aux;  


 
  return *intPtr;
}

void  empilha          (STACK* pilha, char* s) { 
  int i;
  for (i=0;i<(int) strlen(s);i++) {
    pushInt(pilha, s[i]);
    
  }
}

void  desempilha       (STACK* pilha, char* s) {
 

  int i=0;
  do {
   
    s[i]=popInt(pilha);
    s[i+1]='\0';
    i++;
  } while (!emptyStack(pilha));

  printf("Depois de desempilhar:\t\t\t");
  printString (s);

}

void  invertString     (char* limpa, char* invertida) {
  STACK* pilha = createStack();
  empilha     (pilha, limpa);
  desempilha  (pilha, invertida);


}

int   sameSize         (char* limpa, char* invertida) {
  
  if (strlen(limpa)==strlen(invertida)) {
    return 1;
  }
  printf("(strlen(limpa)=%d) != (strlen(invertida)=%d)", strlen(limpa), strlen(invertida));
  return 0;
}

int   sameCharacters   (char* limpa, char* invertida) {
  int i;
  for (i=0; i<(int) strlen(limpa); i++) {
   
    if (limpa[i]!=invertida[i]) {
      printf("(%c) != (%c)\n", limpa[i], invertida[i]);
      return 0;
    }
  }
  return 1;
}

int   palindromeCheck  (char* limpa, char* invertida) {
  
  if (sameSize(limpa, invertida)) {
    if (sameCharacters(limpa, invertida)) {
      return 1;
    }
  }
  return 0;
}

void  isPalindrome     (char* original, char* limpa, char* invertida) {

 
  if (palindromeCheck(limpa, invertida)) {
    printf("\n\"%s\" e um palindromo\n\n", original);
  } else {
    printf("\n\"%s\" nao e um palindromo\n\n", original);
  }
}

int main () {
  int size=50, choice;
  char stringOriginal[size], stringLimpa[size] , stringInvertida[size];

  
  
  for (choice=1; choice <5; choice ++) {
    selectString    (choice,      stringOriginal);        
    cleanString     (stringLimpa, stringOriginal);         
    invertString    (stringLimpa, stringInvertida);
    isPalindrome    (stringOriginal, stringLimpa, stringInvertida);
  }
}
