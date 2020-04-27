#include <stdio.h>

int main(){

	long long arr[91] = { 0, };

	int i, n;

	scanf("%d", &n);

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;

	for (i = 4; i <= 90; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%llu\n", arr[n]);

	return 0;
}