#include <stdlib.h>
#include <stdio.h>

int func(int n){
	
	if(n==0){
		printf ("%d", n);	
		return 0;
	}
	else{
		func(n-1);
		printf ("%d", n);
	}
	
}	


int main(){
	
	int n=0;
	scanf("%d", &n);
	func(n);

}




