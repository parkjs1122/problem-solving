#include <stdio.h>

int main(){

	int dynamic[12] = { 0, };

	int T, n, i=0;

	scanf("%d", &T);

	dynamic[1] = 1;
	dynamic[2] = 2;
	dynamic[3] = 4;

	for (i = 4; i <= 11; i++){
		dynamic[i] = dynamic[i - 3] + dynamic[i - 2] + dynamic[i - 1];
	}

	for (i = 0; i < T; i++){
		scanf("%d", &n);

		printf("%d\n", dynamic[n]);
	}

	return 0;
}