#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	int N, K, M;
	
	queue<int> visit;
	
	cin >> N; cin >> K; cin >> M;
	
	vector<int> adj[N+M+10];
	
	int visitYN[N+M+10] = {0,};
	
	for(int i=1; i<=M; i++){
		for(int j=0; j<K; j++){
			int t;
			cin >> t;
			
			adj[t].push_back(N+i);
			adj[N+i].push_back(t);
		}
	}
	
	visit.push(1);
	visitYN[1] = 1;
	
	int depth = 0, flag = 0;
	
	while(!visit.empty()){
		int now = visit.front();
		visit.pop();
		
		for(int i=0; i<adj[now].size(); i++){
			if(visitYN[adj[now][i]] <= 0){
				visit.push(adj[now][i]);
				visitYN[adj[now][i]] = visitYN[now] + 1;
			}
		}
	}
	
	if(visitYN[N] > 0) cout << visitYN[N] / 2 + 1;
	else cout << -1;
	
	return 0;
}
