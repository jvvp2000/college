#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "../TAD-fila/fila.h"


bool  isBetween        (int n, int min, int max) {
  return ((min <= n) && (n <= max));
}

void  fillQueue     (QUEUE* queue, char* cExpression) {
  int i;  
  for (i=0; i<(int)strlen(cExpression);i++) {
    if (isBetween(cExpression[i],48,57)) {
      pushFilaInt(queue, cExpression[i]-48);
    } else {
      pushFilaInt(queue, cExpression[i]);
    }
   
  }
  printf("Fila cheia:\t");
  printQueue(queue, 'c');
  printf("\n");
}



int isOperator (int token) {
  return ((token=='+')||(token=='-')||(token=='*')||(token=='/'));  //boolean return
  
  
}

void fillPrefix (int manual, char* prefix) {
  if (manual) {
    strcpy(prefix, "Nao implementado ainda");
  } else {
    strcpy(prefix, "- + * 9 + 2 8 * + 4 8 6 3");
  }
  printf("\n\nSua expressao e: \"%s\"\n", prefix);
}

void  printString      (char* string) {  
  printf(">%s<\n", string);
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


 
}

void  cleanString      (char* limpa, char* original) {   
  
  strcpy(limpa, original);
  
  
  spacelessSwap (limpa);          

}

int   doOperation      (QUEUE* worm) {
  int a = popFilaInt(worm), b = popFilaInt(worm), c = popFilaInt(worm);
  switch (a) {
    case '+': return b+c;
    case '-': return b-c;
    case '*': return b*c;
    case '/': return b/c;
  }
  return 0;
}

void  worm2Temp         (QUEUE* worm, int* x, int* y, int* z) {

  *x = popFilaInt(worm);
  *y = popFilaInt(worm);
  *z = popFilaInt(worm);
      pushFilaInt(worm, *x);
      pushFilaInt(worm, *y);
      pushFilaInt(worm, *z);
}

void printWormQueue (QUEUE* worm, QUEUE* queue) {
  printf("Worm:\t");
  printQueue(worm, 'd');
  printf("\nFila:\t");
  printQueue(queue, 'd');
  printf("\n");
}

int   isValidOperation         (QUEUE* worm) {
  int a, b, c;
  worm2Temp (worm, &a, &b, &c);
  return (isOperator(a)&&(!isOperator(b))&&(!isOperator(c)));
}

void fillWorm (QUEUE* worm, QUEUE* queue) {
  int i;
  for (i=0; i<3; i++) {
    pushFilaInt(worm, popFilaInt(queue));
  }
}

void printCounters (int c, int tcm, int ce, int w) {
  printf("==>Contador: %d\tContadorTempo: %d\tContadorEnq: %d\tContadorWorm: %d\n", c, tcm, ce, w);
}

int wormEmpty (QUEUE* worm) {
  return (queueCount(worm)==0);
}

void debugPrinting (QUEUE* worm, QUEUE* queue, int cont, int tempCount) {
  
  printf("\n--------------- printing ---------------\n");
  printWormQueue(worm,queue);
  printCounters (cont, tempCount, queueCount(queue), queueCount(worm));
  printf("--------------- printing ---------------\n");
}

void advanceOnce ( QUEUE* worm, QUEUE* queue) {

  pushFilaInt(worm, popFilaInt(queue));

  pushFilaInt(queue, popFilaInt(worm));

}

void runQueue          (QUEUE* queue) {
  printf("RunningQueue.\n");
  int cont=0, temp, numOperations=0;
  int tempCount=queueCount(queue);
  QUEUE* worm = createQueue();
                                                      debugPrinting(worm, queue, cont, tempCount);
  if (queueCount(queue)==0) {
    printf("Vazia ");
  } else {
    while (tempCount>1) {    
      if (wormEmpty(worm)) {
        if ((tempCount-cont)>=3) {
          printf("3 de vez!\n");
                                                      debugPrinting(worm, queue, cont, tempCount);
          fillWorm(worm, queue);
          cont+=3;
                                                      debugPrinting(worm, queue, cont, tempCount);
        } else {
                                                      debugPrinting(worm, queue, cont, tempCount);
          printf("Fim da linha\n");
          while ((tempCount-cont)>0) {
                                                      debugPrinting(worm, queue, cont, tempCount);
            pushFilaInt(queue,popFilaInt(queue));
            cont++;
          }
          cont=0;
          tempCount-=numOperations*2;
          numOperations=0;
          printf("Contador e Temp resetados\n");
        }
      } else {
        printf("************%d****************\n", isValidOperation(worm));
        if (isValidOperation(worm)) {
          printf("Tirando\n");
                                                      debugPrinting(worm, queue, cont, tempCount);
          pushFilaInt(queue, doOperation(worm));
          numOperations++;
                                                      debugPrinting(worm, queue, cont, tempCount);
        } else {
          if ((tempCount-cont)>0) {
            printf("Cagando e andando:\n");
                                                      debugPrinting(worm, queue, cont, tempCount);
            advanceOnce(worm, queue);
            cont++;
                                                      debugPrinting(worm, queue, cont, tempCount);
          }
        }
      }
      printf("========================================\n");
    }
                                                      debugPrinting(worm, queue, cont, tempCount);
    printf("Fora do loop\n");
  }
  printf("\n");
}

void solvePrefix (char* cExpression) {
  QUEUE*  fila = createQueue();


  fillQueue (fila, cExpression);
  runQueue  (fila);


  destroyQueue  (fila);       
}

int main () {
  int     manual=0, SIZE=50;
  char    prefixExpression[SIZE], cleanedExpression[SIZE];

  fillPrefix    (manual,      prefixExpression);        
  cleanString   (cleanedExpression, prefixExpression);         
  solvePrefix   (cleanedExpression);
  printf("fim");
}
