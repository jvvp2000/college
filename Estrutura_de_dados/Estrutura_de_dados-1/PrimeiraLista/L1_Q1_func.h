#include "L1_Q1.c"

typedef struct cilindro Cilindro;
Cilindro* construirCilindro(float raio, float altura);
/*Construi o Cilindro  */

float areaCilindroB(Cilindro* cil);

/*Calcula e mostra a area da base do cilindro  */

float areaCilindroL(Cilindro* cil);

/*Calcula e mostra a area lateral do cilindro  */

float areaCilindro(Cilindro* cil);

/*Calcula e mostra a area da total do cilindro  */

float volumeCilindro(Cilindro* cil);

/*Calcula e mostra o volume do cilindro  */

void apagarClilindro(Cilindro* cil);

/*libera o espaco alocado */
