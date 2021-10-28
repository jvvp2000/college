#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Termo{
  float coeficiente;
  int expoente;
  struct Termo *proximo;
};
typedef struct Termo* Polinomio;
 


struct Termo *AlocaTermo(){
  struct Termo *p;
  p = (struct Termo*)malloc(sizeof(struct Termo));
  if(p == NULL)
    exit(1);
  return p;
}

Polinomio CriaPolinomioNulo(){
  Polinomio p;
  p = AlocaTermo();
  p->coeficiente = 0.0;
  p->expoente = -1;
  p->proximo = p;
  return p;
}

void InsereTermo(Polinomio p, float coeficiente, int expoente){
  struct Termo *t, *at,*q;
  /* Aloca memória para o novo termo: */
  q = AlocaTermo();
  q->coeficiente = coeficiente;
  q->expoente = expoente;
  /* Busca a posição correta para inserir o novo termo,
     O novo termo será inserido entre os termos apontados 
     por at e t.
  */
  at = p;
  t = p->proximo;
  while(expoente < t->expoente){
    at = t;
    t = t->proximo;
  }
  q->proximo = t;
  at->proximo = q;
}

void ImprimePolinomio(Polinomio p){
  struct Termo *t;
   
  t = p->proximo;
  while(t != p){
    printf("%.2f*x^%d",t->coeficiente,t->expoente);
    t = t->proximo;
    if(t != p){
      if(t->coeficiente >= 0.0)
        printf(" + ");
      else
        printf(" ");
    }
  }
  printf("\n");
}

Polinomio CriaPolinomio(char expr[]){
  Polinomio p;
  int expoente,r,n,nn;
  float coeficiente,sinal = 1.0;
  char c;
 
  nn = 0;
  p = CriaPolinomioNulo();
  while(1){
    r = sscanf(expr+nn," %f * x ^ %d %n",&coeficiente, &expoente,&n);
    if(r == 0 || r == EOF) 
      break;
    nn += n;
 
    InsereTermo(p, sinal*coeficiente, expoente);
     
    r = sscanf(expr+nn,"%c %n",&c,&n);
    if(r == EOF || r == 0)
      break;
    nn += n;
 
    if(c == '-')
      sinal = -1.0;
    else
      sinal = 1.0;
  }
  return p;
}

Polinomio SomaPolinomios(Polinomio p,
                         Polinomio q){
  Polinomio r;
  struct Termo *pp, *qq, *rr;
  float cf;
 
  r = CriaPolinomioNulo();
  rr = r;
  pp = p->proximo;
  qq = q->proximo;
  while(pp->expoente > -1 || qq->expoente > -1){
    if(pp->expoente < qq->expoente){
      InsereTermo(rr, qq->coeficiente, qq->expoente);
      rr = rr->proximo;
      qq = qq->proximo;
    }
    else if(qq->expoente < pp->expoente){
      InsereTermo(rr, pp->coeficiente, pp->expoente);
      rr = rr->proximo;
      pp = pp->proximo;
    }
    else{ /* pp->expoente == qq->expoente */
      cf = pp->coeficiente + qq->coeficiente;
      if(cf != 0.0){
        InsereTermo(rr, cf, pp->expoente);
        rr = rr->proximo;
      }
      pp = pp->proximo;
      qq = qq->proximo;
    }
 
  }
  return r;
}

int main(){
  Polinomio p,q,r;
 
  p = CriaPolinomio("5.0*x^3 -4.0*x^1 + 2.0*x^0");  
  ImprimePolinomio(p);
 
  q = CriaPolinomio("  8.0*x^4 + 2.0*x^3 + 4.0*x^1");
  ImprimePolinomio(q);
 
  r = SomaPolinomios(p, q);
  ImprimePolinomio(r);
 
  return 0;
}


