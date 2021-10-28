#include<stdio.h>
#include <stdlib.h>
#include "L1_Q1_func.h"

int main(){
						  
	float raio;
	float altura;

	printf("Digite o raio do Cilindro:");
	scanf("%f",&raio);

	printf("Digite a altura do Cilindro:");
	scanf("%f",&altura);

    Cilindro* cil=construirCilindro(raio,altura);
 
	float areaC=areaCilindro(cil);
	float vol=volumeCilindro(cil);
				
	printf("\n Area do  Cilindro: %.3f \n",areaC);
    printf("\n Volume do  Cilindro: %.3f \n",vol);
	
	freeClilindro(cil);

}
