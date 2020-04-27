#include <stdio.h>

int main(){

	long long n, i, j, k, prev=-1, prev2=-1, lowprice=99999999;
	
	long long sum=0;
	
	long long rgb[1000][3];
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld %lld %lld", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<3; j++){
			if(prev2 != j){
				if(lowprice > rgb[i][j]){
					lowprice = rgb[i][j];
					prev = j;
				}	
			}
		}
		printf("%lld ", lowprice);
		prev2 = prev;
		
		sum += lowprice;
		lowprice = 99999999;
		
	}
	
	printf("%lld", sum);

}
