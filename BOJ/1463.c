#include <stdio.h>
#include <stdlib.h>

int main(){

	int *dynamic = (int*) malloc(sizeof(int) * 1000001);

	dynamic[1] = 0;
	dynamic[2] = 1;
	dynamic[3] = 1;

	int n, i, MAX = 9999999999;
	int r1 = 0, r2 = 0, r3 = 0, r = 0;

	for (i = 4; i < 1000001; i++){
		dynamic[i] = 0;
	}

	scanf("%d", &n);

	for (i = 4; i <= n; i++){
		r1 = (i % 3 == 0) ? dynamic[i / 3] : MAX;
		r2 = (i % 2 == 0) ? dynamic[i / 2] : MAX;
		r3 = dynamic[i - 1];

		r = ((r1 > r2) ? r2 : r1);
		r = ((r > r3) ? r3 : r);

		dynamic[i] = r + 1;
	}

	printf("%d\n", dynamic[n]);

	return 0;
}