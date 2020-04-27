#include <stdio.h>

int main(){

	int number[101][10] = { 0, };

	int mod = 1000000000;

	int i, j, n;

	scanf("%d", &n);

	for (i = 1; i < 10; i++){
		number[1][i] = 1;
	}

	for (i = 2; i <= n; i++){
		for (j = 0; j < 10; j++){
			if (j == 0) number[i][j] = (number[i][j] % mod + number[i - 1][j + 1] % mod) % mod;
			else if (j == 9) number[i][j] = (number[i][j] % mod + number[i - 1][j - 1] % mod);
			else number[i][j] = (number[i][j] % mod + number[i - 1][j - 1] % mod + number[i - 1][j + 1] % mod);
		}
	}

	int result = 0;

	for (i = 0; i < 10; i++){
		result = (result % mod + number[n][i] % mod);
	}

	printf("%d\n", result % mod);

	return 0;
}