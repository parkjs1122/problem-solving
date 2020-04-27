#include <stdio.h>

int main(){

	int n, i, j;

	int rgb[1001][3] = { 0, };
	int dynamic[1001][3] = { 0, };

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		for (j = 0; j < 3; j++){
			scanf("%d", &rgb[i][j]);
		}
	}

	dynamic[0][0] = rgb[0][0];
	dynamic[0][1] = rgb[0][1];
	dynamic[0][2] = rgb[0][2];

	for (i = 1; i < n; i++){
		dynamic[i][0] = rgb[i][0] + ((dynamic[i - 1][1] > dynamic[i - 1][2]) ? dynamic[i - 1][2] : dynamic[i - 1][1]);
		dynamic[i][1] = rgb[i][1] + ((dynamic[i - 1][0] > dynamic[i - 1][2]) ? dynamic[i - 1][2] : dynamic[i - 1][0]);
		dynamic[i][2] = rgb[i][2] + ((dynamic[i - 1][0] > dynamic[i - 1][1]) ? dynamic[i - 1][1] : dynamic[i - 1][0]);
	}

	int result = (dynamic[n - 1][1] > dynamic[n - 1][2]) ? dynamic[n - 1][2] : dynamic[n - 1][1];
	result = (result > dynamic[n - 1][0]) ? dynamic[n - 1][0] : result;

	printf("%d", result);

	return 0;
}
