#include <iostream>

using namespace std;

struct edge{
	int from;
	int to;
	int distance;
};

struct vertex{
	int num;
};

int vertex[20002];
struct edge edges[300000];
int edges_idx[20002];
int result[20002];
int real_result[20002];
int vertex_idx[20002];

void min_heapify(int arr[], int m, int n){
	int l = m * 2, r = m * 2 + 1, smallest;
	
	if(l <= n && arr[l] < arr[m]){
		smallest = l;
	}else{
		smallest = m;
	}
	
	if(r <= n && arr[r] < arr[smallest]){
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
	for(int i=n/2; i>0; i--){
		min_heapify(arr, i, n);
	}
}

void max_heapify(struct edge arr[], int m, int n){
	int l = m * 2, r = m * 2 + 1, largest;
	
	if(l < n && arr[l].from > arr[m].from){
		largest = l;
	}else{
		largest = m;
	}
	
	if(r < n && arr[r].from > arr[largest].from){
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
	for(int i=n/2; i>=0; i--){
		max_heapify(arr, i, n);
	}
}

void maxheap_sort(struct edge arr[], int n){
	struct edge temp;
	
	for(int i=n-1; i>=1; i--){
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		
		max_heapify(arr, 0, i);
	}
}


int main(){
	
	int v, e, start, count;
	
	cin >> v; cin >> e; cin >> start;
	
	count = v;
	
	for(int i=0; i<e; i++){
		scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].distance);
	}
	
	build_maxheap(edges, e);
	maxheap_sort(edges, e);
	
	edges_idx[edges[0].from] = 0;
	
	for(int i=0; i<e; i++){
		edges_idx[edges[i].from+1] = i+1;
	}
	
	for(int i=1; i<=v; i++){
		vertex[i] = i;
		vertex_idx[i] = i;
		result[i] = 99999999;
	}
	
	result[start] = 0;
	
	build_minheap(result, count);
	
	while(count >= 0){
		
		int vv = vertex[1];
		
		real_result[vv] = result[1];
		
		for(int i=edges_idx[vv]; i<e; i++){
			if(edges[i].from != vv) break;
			
			int temp_idx = vertex_idx[edges[i].to];
			
			int temp_dist = result[1] + edges[i].distance;
			
			if(result[temp_idx] > temp_dist) result[temp_idx] = temp_dist;
		}
		
		int temp = result[1];
		result[1] = result[count];
		result[count] = temp;
		temp = vertex[1];
		vertex[1] = vertex[count];
		vertex[count] = temp;
		
		build_minheap(result, --count);
	}
	
	for(int i=1; i<=v; i++){
		if(real_result[i] == 99999999) printf("INF\n");
		else printf("%d\n", real_result[i]);
	}
	
	return 0;
}
