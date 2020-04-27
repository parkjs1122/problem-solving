#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int visited[1010] = {0,};
int b[1010] = {0,};
vector<int> job[1010];

int dfs(int here){
	if(visited[here] == 1) return 0;
	visited[here] = 1;
	
	for(int i=0; i<job[here].size(); i++){
		int there = job[here][i];
		if(b[there] == 0 || dfs(b[there])){
			b[there] = here;
			return 1;
		}
	}
	
	return 0;
}

int main(){
	
	int N, M, count = 0;
	
	cin >> N; cin >> M;
	
	for(int i=1; i<=N; i++){
		int J, T;
		
		cin >> J;
		
		for(int j=0; j<J; j++){
			cin >> T;
			job[i].push_back(T);
		}
	}
	
	for(int i=1; i<=N; i++){
		memset(visited, 0, sizeof(visited));
		if(dfs(i)) count++;
	}
	
	cout << count;
	
	return 0;
}
