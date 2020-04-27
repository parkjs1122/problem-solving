#include <stdio.h>

int cache[101] = {0,};


int main(){
	int length, i, j, sum=0;
	
	long long cache[1000] = {0,};
	
	cache[0] = 1;
	cache[1] = 2;
	cache[2] = 3;
	cache[3] = 5;
	
	scanf("%d", &length);
	
	for(i=0; i<length; i++){
		if(i > 3){
			cache[i] += (cache[i-2] + cache[i-1]) % 10007;
		}
		
	}
	
	printf("%d", cache[length-1] % 10007);
}
