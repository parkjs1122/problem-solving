#include <stdio.h>

void max_heapify(int a[], int i, int n){
	
	int largest = 0, left = 2*i, right = 2*i+1;
	
	if(left < n && a[left] > a[i]){
		largest = left;
	}else{
		largest = i;
	}
	
	if(right < n && a[right] > a[largest]){
		largest = right;
	}
	
	if(largest != i){
		int temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		max_heapify(a, largest, n);
	}
}

void build_maxheap(int a[], int n){
	int i = 0;
	
	for(i=n/2; i>=0; i--){
		max_heapify(a, i, n);
	}
}

void heap_sort(int a[], int n){
	int i, temp;
	
	for(i=n-1; i>0; i--){
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		max_heapify(a, 0, i);
	}
}

int main(){
	
	int a[50] = {0,};
	int b[50] = {0,};
	
	int sum = 0;
	
	int N, i;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<N; i++){
		scanf("%d", &b[i]);
	}
	
	build_maxheap(a, N);
	build_maxheap(b, N);
	
	heap_sort(a, N);
	heap_sort(b, N);
	
	for(i=0; i<N; i++){
		sum += a[i] * b[N-i-1];
	}
	
	printf("%d", sum);
	
	return 0;
}
