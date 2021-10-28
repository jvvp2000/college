#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float squareRoot (float num, float ans, float tol){
	
	if (fabs((ans*ans)-num)<=tol){
		
		return ans;
		
	}else{
		
		return squareRoot(num,((ans*ans)+num)/(2*ans),tol);
		
	}
		
}

int main(){
	
	printf("%f \n",squareRoot(5,2,0.01));
	printf("%f",squareRoot(4,2,0.01));


}
