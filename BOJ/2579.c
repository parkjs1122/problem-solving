#include <stdio.h>

int main(){

	int n, i;

	int step[301] = { 0, };
	int dynamic[301][2] = { 0, };

	scanf("%d", &n);

	for (i = 1; i <= n; i++){
		scanf("%d", &step[i]);
	}

	dynamic[1][1] = step[1];

	for (i = 2; i <= n; i++){
		dynamic[i][0] = dynamic[i - 1][1];
		dynamic[i][1] = (((dynamic[i - 2][0] + step[i - 1]) > dynamic[i - 2][1]) ? (dynamic[i - 2][0] + step[i - 1]) : dynamic[i - 2][1]) + step[i];
	}

	printf("%d\n", dynamic[n][1]);

	return 0;
}