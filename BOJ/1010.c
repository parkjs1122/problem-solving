#include <stdio.h>

int main(){

	int dynamic[31][31] = {0,}, i, j, n1, n2, T;

	dynamic[1][1] = 1;
	dynamic[2][1] = 2;
	dynamic[2][2] = 1;

	for (i = 3; i <= 30; i++){
		for (j = 1; j <= i; j++){
			if (j == 1) dynamic[i][j] = i;
			else dynamic[i][j] = dynamic[i - 1][j] + dynamic[i - 1][j - 1];
		}
	}

	scanf("%d", &T);

	for (i = 0; i < T; i++){
		scanf("%d", &n1);
		scanf("%d", &n2);

		printf("%d\n", dynamic[n2][n1]);
	}


	return 0;
}