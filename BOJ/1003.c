#include <stdio.h>

int zero, one;

int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(){

	int n, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		zero = 0;
		one = 0;

		int num;

		scanf("%d", &num);

		fibonacci(num);

		printf("%d %d\n", zero, one);
	}

	return 0;
}