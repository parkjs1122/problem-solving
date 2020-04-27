#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> trust[10011];
int visit[10011] = {0,};
int cnt[10011] = {0,};
int max_cnt = 0;

void dfs(int from, int r){
	if(visit[from] == r) return;
	
	visit[from] = r;
	
	for(int i=0; i<trust[from].size(); i++) dfs(trust[from][i], r);
	
	cnt[r]++;
}

int main(){
	
	int N, M;
	
	cin >> N; cin >> M;
	
	for(int i=0; i<M; i++){
		int S, T;
		
		cin >> S; cin >> T;
		
		trust[T].push_back(S);
	}
	
	for(int i=1; i<=N; i++){
		memset(visit, 0, 10011*sizeof(int));
		dfs(i, i);
		if(cnt[i] > max_cnt) max_cnt = cnt[i];
	}
	
	for(int i=1; i<=N; i++){
		if(max_cnt == cnt[i]) cout << i << " ";
	}
	
	return 0;
}
