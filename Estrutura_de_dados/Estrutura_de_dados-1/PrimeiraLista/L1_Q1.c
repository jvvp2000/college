#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include "L1_Q1.h"

struct cilindro{

	float raioCilindro;
	float alturaCilindro;
	
};

Cilindro* construirCilindro(float raio, float altura){

	Cilindro* cil = (Cilindro*)malloc(sizeof(Cilindro));

	if(cil == NULL){
		
		printf("Ai complica \n");
		exit(1);
	
	}

	cil->raioCilindro = raio;
	cil->alturaCilindro= altura;
	return cil;

}

float areaCilindroB(Cilindro* cil){
	
    float raioCil=cil->raioCilindro;
	float areabase=raioCil*raioCil*M_PI;
	printf("\n Area da Base do Cilindro:%.3f \n",areabase);
	
	return areabase;
}

float areaCilindroL(Cilindro* cil){

	float alturaCil=cil->alturaCilindro;
	float raioCil=cil->raioCilindro;
	
   	float areaLateral=2*M_PI*alturaCil*raioCil;
  	printf("\n Area Lateral do Cilindro:%.3f \n",areaLateral);
  	
	return areaLateral;

}

float areaCilindro(Cilindro* cil){

	float area=2*areaCilindroB(cil)+areaCilindroL(cil);
	
	return area;

}

float volumeCilindro(Cilindro* cil){
	
	float raioCil=cil->raioCilindro;
	float altCil=cil->alturaCilindro;
	float vol=raioCil*raioCil*altCil*M_PI;
	
	return vol;

}

void freeClilindro(Cilindro* cil){

	free(cil);

}


