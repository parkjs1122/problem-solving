#include <stdio.h>

int cache[101] = {0,};


int main(){
	int T;
	int test_case;

	scanf("%d", &T);
	
	for(test_case = 1; test_case <= T; test_case++) {
		
		int length, n, j, sum=0;
		
		long long A[1000] = {0,};
		long long B[1000] = {0,};
		long long C[1000] = {0,};
		
		scanf("%d", &length);
		
		A[1]=1;
		A[2]=5;
		B[1]=1;
		B[2]=1;
		C[1]=1;
		C[2]=2;
		
		for(n=3; n<=length; n++){
			B[n]=B[n-2]+A[n-1];
			C[n]=C[n-1]+A[n-1];
			A[n]=A[n-2]+A[n-1]+B[n-1]+2*C[n-1];
		}
		
		printf("%d\n", A[length]);
		
	}
}
