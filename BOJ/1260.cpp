#include <iostream>
#include <queue>

using namespace std;

int N, M, V;

int adj[1001][1001];
int visit[1001];

void dfs(int v){
	visit[v] = 1;
	cout << v << " ";
	for(int i=1; i<=N; i++){
		if(adj[v][i] == 1 && visit[i] != 1){
			dfs(i);
		}
	}
}

int main(){
	
	cin >> N; cin >> M; cin >> V;
	
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			adj[i][j] = 0;
		}
	}
	
	for(int i=0; i<M; i++){
		int s; cin >> s;
		int t; cin >> t;
		adj[s][t] = 1;
		adj[t][s] = 1;
	}
	
	for(int i=1; i<=N; i++){
		visit[i] = 0;
	}
	
	visit[V] = 1;
	
	dfs(V); cout << "\n";
	
	for(int i=1; i<=N; i++){
		visit[i] = 0;
	}
	
	visit[V] = 1;
	
	queue<int> bfs;
	
	bfs.push(V);
	
	while(!bfs.empty()){
		int N = bfs.front();
		bfs.pop();
		
		cout << N << " ";
		
		for(int i=1; i<=1001; i++){
			if(adj[N][i] == 1 && visit[i] != 1){
				visit[i] = 1;
				bfs.push(i);
			}
		}
	}
	
	return 0;
}
