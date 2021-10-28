#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int C(int n, int k){
	
	if (k == 0 || n == k){
		
		return 1;
		
	}else if (n > k && k > 0){
		
		return C(n-1,k) + C(n-1,k-1);
		
	}
		
}

int main(){
	
	printf ("%d", C(49,6));

}
