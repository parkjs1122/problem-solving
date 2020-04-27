#include <stdio.h>
#include <stdlib.h>

int main(){

	int wine[10001];
	int **dynamic = (int**)malloc(sizeof(int*) * 10001);

	int i, j, n;

	for (i = 0; i <= 10000; i++){
		dynamic[i] = (int*)malloc(sizeof(int) * 2);
	}

	scanf("%d", &n);

	for (i = 1; i <= n; i++){
		scanf("%d", &wine[i]);
	}

	dynamic[0][0] = 0;
	dynamic[0][1] = 0;
	dynamic[1][0] = 0;
	dynamic[1][1] = wine[1];
	dynamic[2][0] = dynamic[1][1];
	dynamic[2][1] = wine[1]+wine[2];

	for (i = 3; i <= n; i++){
		dynamic[i][0] = ((dynamic[i - 1][1] > dynamic[i - 2][1]) ? dynamic[i - 1][1] : dynamic[i - 2][1]);
		int temp = ((dynamic[i - 2][1] > dynamic[i - 3][1]) ? dynamic[i - 2][1] : dynamic[i - 3][1]);
		temp = ((temp > (dynamic[i - 2][0] + wine[i - 1])) ? temp : (dynamic[i - 2][0] + wine[i - 1]));
		dynamic[i][1] = temp + wine[i];
	}

	int result = (dynamic[n][0] > dynamic[n][1]) ? dynamic[n][0] : dynamic[n][1];

	printf("%d\n", result);

	return 0;
}