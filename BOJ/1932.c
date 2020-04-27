#include <stdio.h>
#include <stdlib.h>

int main(){

	int i, j, height;

	int **tri = (int**) malloc(sizeof(int*) * 501);
	int **dynamic = (int**)malloc(sizeof(int*) * 501);
	
	for (i = 0; i < 501; i++){
		tri[i] = (int*)malloc(sizeof(int) * 501);
		dynamic[i] = (int*)malloc(sizeof(int) * 501);
	}

	for (i = 0; i < 501; i++){
		for (j = 0; j < 501; j++){
			tri[i][j] = 0;
			dynamic[i][j] = 0;
		}
	}

	scanf("%d", &height);

	for (i = 1; i <= height; i++){
		for (j = 1; j <= i; j++){
			scanf("%d", &tri[i][j]);
		}
	}

	dynamic[1][1] = tri[1][1];

	for (i = 2; i <= height; i++){
		for (j = 1; j <= i; j++){
			dynamic[i][j] = ((dynamic[i - 1][j] > dynamic[i - 1][j - 1]) ? dynamic[i - 1][j] : dynamic[i - 1][j - 1]) + tri[i][j];
		}
	}

	int result = 0;

	for (i = 1; i <= height; i++){
		if (dynamic[height][i] > result) result = dynamic[height][i];
	}

	printf("%d\n", result);

	return 0;
}