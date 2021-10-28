#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include 


typedef struct Date{
		
}date;

date* CreateStruct (){
    date* data = (d*) malloc ( sizeof (d) );
    if(data != NULL){
        return data;
    }
    return NULL;
	}

char aString(int dia,int mes,int ano){
   
   	int i=0;
    char data [10]="";
    char di [2];
    char me [2];
    char an [4];

    sprintf(di, "%d", dia);
    sprintf(me, "%d", mes);
    sprintf(an, "%d", ano);
        
	if (mes == 2){
		
		if (ano%4 == 0){
			
			if (dia > 0 && dia <= 29 && mes > 0 && mes <= 12 && ano >= 0){
			
				strcat(data, di);
   				strcat(data, "/");
    			strcat(data, me);
  				strcat(data, "/");
    			strcat(data, an);
				
				printf("Sua data (ano bissexto):");
								
				for (i=0;i<10;i++){
					
					printf("%c", data[i]);
				
				}
				
				return* data;
				
			}
				
		}else if (dia > 0 && dia <= 28 && mes > 0 && mes <= 12 && ano >= 0) {
									
			strcat(data, di);
			strcat(data, "/");
			strcat(data, me);
			strcat(data, "/");
    		strcat(data, an);
				
			printf("Sua data:");
				
			for (i=0;i<10;i++){
					
				printf("%c", data[i]);
				
			}
				
			return* data;
		
		}else{
				
			printf("ai naooo");
				
		}
								
	}else if (mes%2 == 0){
		
		
		if (dia > 0 && dia <= 30 && mes > 0 && mes <= 12 && ano >= 0){
		
		strcat(data, di);		
		strcat(data, "/");
    	strcat(data, me);
    	strcat(data, "/");
    	strcat(data, an);
		
		printf("Sua data:");
		
		
		for (i=0;i<10;i++){
			
			printf("%c", data[i]);
				
		}
		
		return* data;
		
		}else{
		
		printf("ai nao irmao");
			
		}
		
	}else if (mes%2 == 1){
		
		
		if (dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano >= 0){
			
		strcat(data, di);
		strcat(data, "/");
		strcat(data, me);
    	strcat(data, "/");
    	strcat(data, an);	
	
		printf("Sua data:");
		
		for (i=0;i<10;i++){
			printf("%c", data[i]);
				
		}
			
		return* data;	
				
		}else{
		
		printf("po...");
		
		}
		
	}
  
}

char bString(char data, date ){
	
	
	
	
	
}

int main(){
	
	int dia=0, mes=0, ano=0;
	
	char data;
	printf ("Digite o dia: \t");
	scanf ("%d", &dia);
	printf ("Digite o mes: \t");
	scanf ("%d", &mes);
	printf ("Digite o ano: \t");
	scanf ("%d", &ano);
	
	aString(dia, mes, ano);	
	
	
	
	data = aString(dia, mes, ano);
	 
	bString(data, )
}
