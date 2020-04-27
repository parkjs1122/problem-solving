#include <stdio.h>
#include <stdlib.h>

int main(){

	int t, i, j;
	long long max = -999999999999999999;
	long long sum = 0;
	int count;
	
	scanf("%d", &t);
	scanf("%d", &count);
	
	int *result = (int*) malloc (sizeof(int) * t);
	
	for(i=0; i<t; i++){
		scanf("%d", &result[i]);
	}
	
	for(j=0; j<count; j++){
		sum += result[j];
	}
	
	if(max < sum) max = sum;
	
	for(i=1; i<t-count+1; i++){
		sum = sum - result[i-1] + result[i+count-1];
		if(max < sum) max = sum;
	}
	
	printf("%d", max);

}
