#include <iostream>

using namespace std;

struct edge{
	int from;
	int to;
	int distance;
};

struct vertex{
	int num;
	int distance;
};

struct edge edges[300000];
int edges_idx[20002];
struct vertex result[20002];
struct vertex cost[20002];

void min_heapify(struct vertex arr[], int m, int n){
	int l = m * 2, r = m * 2 + 1, smallest;
	
	if(l <= n && arr[l].distance < arr[m].distance){
		smallest = l;
	}else{
		smallest = m;
	}
	
	if(r <= n && arr[r].distance < arr[smallest].distance){
		smallest = r;
	}
	
	if(smallest != m){
		struct vertex temp = arr[smallest];
		arr[smallest] = arr[m];
		arr[m] = temp;
		
		min_heapify(arr, smallest, n);
	}
}

void build_minheap(struct vertex arr[], int n){
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
		result[i].num = i;
		result[i].distance = 99999999;
		cost[i].num = i;
		cost[i].distance = 99999999;
	}
	
	result[start].distance = 0;
	cost[start].distance = 0;
	
	build_minheap(cost, count);
	
	while(count >= 0){
		
		int vv = cost[0].num;
		
		result[vv].distance = cost[0].distance;
		
		for(int i=1; i<=v; i++){
			printf("%d:%d, ", cost[0].num, cost[0].distance);
		}
		
		printf("\n");
		
		for(int i=edges_idx[vv]; i<e; i++){
			if(edges[i].from != vv) break;
			
			int temp_dist = cost[0].distance + edges[i].distance;
			
			if(result[edges[i].to].distance > temp_dist) result[edges[i].to].distance = temp_dist;
		}
		
		struct vertex temp = cost[0];
		cost[0] = cost[count-1];
		cost[count-1] = temp;
		
		build_minheap(cost, --count);
	}
	
	for(int i=1; i<=v; i++){
		if(result[i].distance == 99999999) printf("INF\n");
		else printf("%d\n", result[i].distance);
	}
	
	return 0;
}
