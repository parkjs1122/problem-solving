#include <stdio.h>

int main(){
	int t = 100000, i;
	
	long long result = 0;
	
	for(i=0; i<t; i++){
	    result += i;
	}
	
	printf("%llu", result);
}
