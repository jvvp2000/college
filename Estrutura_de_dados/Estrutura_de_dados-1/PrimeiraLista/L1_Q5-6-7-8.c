#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define limit 100 //tamanho da matriz (nxn) 

int aux_a=0, aux_m=0;
clock_t start_t, end_t, total_t, t; //2 tipos de medir o tempo

void MatCreator(int A[][limit], int B[][limit]){
	
	int i=0,j=0;
	
	for (i=0;i<limit;i++){
			
		for (j=0;j<limit;j++){
			
			A[i][j] = rand() % 9;
			B[i][j] = rand() % 9;
				
		}
	
	}
	
	for (i=0;i<limit;i++){
			
		for (j=0;j<limit;j++){	
		
			printf ("%d \t", A[i][j]);
							
		}
	
		printf ("\n");
			
	}
	
	printf("\n");
	
	for (i=0;i<limit;i++){
			
		for (j=0;j<limit;j++){	
		
			printf ("%d \t", B[i][j]);
						
		}
		
		printf ("\n");
	
	}
	
	printf ("\n");

}

int MatAdd(int A[][limit], int B[][limit]){

	int i=0,j=0;
	int result[limit][limit];
	
	start_t = clock(); //primeiro  metodo para medir tempo
		
	for (i=0;i<limit;i++){ //adição de matrizes
				
		for (j=0;j<limit;j++){
				
			result[i][j] = A[i][j]+B[i][j];
			aux_a++;
						
		}
			
	}	
	
	end_t = clock();
	
	for (i=0;i<limit;i++){
			
		for (j=0;j<limit;j++){	
		
			printf ("%d \t", result[i][j]);
				
		}
		printf ("\n");

	}
	
	printf ("\n");
	
}

int MatMultip(int A[][limit], int B[][limit]){

	int i, j, k;
  	int result[limit][limit]; 
   	
   	t = clock(); //segundo metodo para medir tempo
   	
    for (i = 0; i < limit; i++) { //multiplicacao de matrizes
        
		for (j = 0; j < limit; j++) {
            
			result[i][j] = 0;
            
			for (k = 0; k < limit; k++){
			
                result[i][j] += A[i][k] * B[k][j];
                aux_m+=2;
            }
            
		}
		
	}
	
	t = clock() - t;
	
	for (i=0;i<limit;i++){
			
		for (j=0;j<limit;j++){	
		
			printf ("%d \t", result[i][j]);
				
		}
		printf ("\n");

	}

	printf ("\n");

}

int main(){

	int A[limit][limit], B[limit][limit];

	printf ("Matrices A and B: \n");
	MatCreator(A,B); //criacao das matrizes

	printf ("Addition of matrices A and B: \n");
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; //medir o tempo
	MatAdd(A,B);	//adicao das matrizes

	printf ("\n Multiplication of matrices A and B: \n");
	MatMultip(A,B); //multiplicacao das matrizes
	double time_taken = ((double)t)/CLOCKS_PER_SEC; //medir tempo
	
	printf ("Time taken to add matrices (in milliseconds): %f  \n", total_t*1000);
	printf ("Time taken to mult matrices (in milliseconds):  %f  \n", time_taken*1000);

	printf ("\n Number of operations (ADD): %d",aux_a);
	printf ("\n Number of operations (MULT): %d",aux_m);

	
	return 0;
}


/* 																							BigO			
Tamanho n 			Soma de Matrizes 	Multiplicacao de Matrizes			/		O()=n^2						O()=n^3			
					Tempo	N Opera			Tempo	N Opera					/	Tempo		N Opera	 		Tempo		N Opera															
	100				0		10000			5 ms	2000000					/	10			10000 	 		1000		1000000															
	200				0		40000			36 ms	16000000				/	40			40000  			8000		8000000															
	300				0		90000			86 ms	54000000				/	90			90000  			27000		27000000																
	400				0		160000			278 ms	128000000				/	160			160000  		64000		64000000																	
	500				-		-				-		-						/	-			-				-			-				//Meu código parou de funcionar aqui	
	700				-		-				-		-						/	-			-				-			-												
	1000			-		-				-		-						/	-			-				-			-								
*/
