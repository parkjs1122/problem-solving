#include <stdio.h>
#define SIZE1 20002
#define SIZE2 300000

struct edge{
	int from;
	int to;
	int distance;
};

FILE *fp;
int vertex[SIZE1];
struct edge edges[SIZE2];
int edges_idx[SIZE1];
int result[SIZE1];
int real_result[SIZE1];
int vertex_idx[SIZE1];

int i, j;

void min_heapify(int arr[], int m, int n){
	int l = m * 2, r = m * 2 + 1, smallest;
	
	if(arr[l] < arr[m] && l < n){
		smallest = l;
	}else{
		smallest = m;
	}
	
	if(arr[r] < arr[smallest] && r < n){
		smallest = r;
	}
	
	if(smallest != m){
		int temp = arr[smallest];
		arr[smallest] = arr[m];
		arr[m] = temp;
		
		temp = vertex[smallest];
		vertex[smallest] = vertex[m];
		vertex[m] = temp;
		
		vertex_idx[vertex[smallest]] = smallest;
		vertex_idx[vertex[m]] = m;
		
		min_heapify(arr, smallest, n);
	}
}

void build_minheap(int arr[], int n){
	for(i=n/2; i>=0; i--){
		min_heapify(arr, i, n);
	}
}

void max_heapify(struct edge arr[], int m, int n){
	int l = m * 2, r = m * 2 + 1, largest;
	
	if(arr[l].from > arr[m].from && l < n){
		largest = l;
	}else{
		largest = m;
	}
	
	if(arr[r].from > arr[largest].from && r < n){
		largest = r;
	}
	
	if(largest != m){
		struct edge temp = arr[largest];
		arr[largest] = arr[m];
		arr[m] = temp;
		
		max_heapify(arr, largest, n);
	}
}

void build_maxheap(struct edge arr[], int n){
	for(i=n/2; i>=0; i--){
		max_heapify(arr, i, n);
	}
}

void maxheap_sort(struct edge arr[], int n){
	struct edge temp;
	
	for(i=n-1; i>=1; i--){
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		
		max_heapify(arr, 0, i);
	}
}


int main(){
	
	int v, e, start, count;
	
	fp = fopen("input.txt", "r");
	
	fscanf(fp, "%d %d", &v, &e);
	fscanf(fp, "%d", &start);
	
	//cin >> v; cin >> e; cin >> start;
	
	count = v+1;
	
	for(i=1; i<=v; i++){
		vertex[i] = i;
		vertex_idx[i] = i;
	}
	
	for(i=0; i<e; i++){
		fscanf(fp, "%d %d %d", &edges[i].from, &edges[i].to, &edges[i].distance);
	}
	
	build_maxheap(edges, e);
	maxheap_sort(edges, e);
	
	edges_idx[edges[0].from] = 0;
	
	for(i=0; i<e; i++){
		edges_idx[edges[i].from+1] = i+1;
	}
	
	for(i=1; i<=v; i++){
		result[i] = 99999999;
	}
	
	result[0] = 0;
	result[start] = 0;
	
	build_minheap(result, count);
	
	while(count >= 0){
		
		int vv = vertex[0];
		
		real_result[vv] = result[0];
		
		for(i=edges_idx[vv]; i<e; i++){
			if(edges[i].from != vv) break;
			
			int temp_idx = vertex_idx[edges[i].to];
			
			int temp_dist = result[0] + edges[i].distance;
			
			if(result[temp_idx] > temp_dist) result[temp_idx] = temp_dist;
		}
		
		int temp = result[0];
		result[0] = result[count-1];
		result[count-1] = temp;
		temp = vertex[0];
		vertex[0] = vertex[count-1];
		vertex[count-1] = temp;
		
		build_minheap(result, --count);
	}
	
	for(i=1; i<=v; i++){
		if(real_result[i] == 99999999) printf("INF\n");
		else printf("%d\n", real_result[i]);
	}
	
	return 0;
}
