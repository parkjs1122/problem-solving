#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int stat1[1010];
int stat2[1010];
int stat3[1010];

int visited[2010] = {0,};
int b[2010] = {0,};
vector<int> eat[2010];

int dfs(int here){
	if(visited[here] == 1) return 0;
	visited[here] = 1;
	
	for(int i=0; i<eat[here].size(); i++){
		int there = eat[here][i];
		if(b[there] == 0 || dfs(b[there])){
			b[there] = here;
			return 1;
		}
	}
	
	return 0;
}

int main(){
	
	int N, count = 0;
	
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int s1, s2, s3;
		
		cin >> s1; cin >> s2; cin >> s3;
		
		stat1[i] = s1;
		stat2[i] = s2;
		stat3[i] = s3;
	}
	
	int eater = 1;
	
	for(int i=1; i<=2*N; i=i+2){
		for(int j=1; j<=N; j++){
			if(eater != j){
				if(stat1[eater] >= stat1[j] && stat2[eater] >= stat2[j] && stat3[eater] >= stat3[j]){
					if(stat1[eater] == stat1[j] && stat2[eater] == stat2[j] && stat3[eater] == stat3[j]){
						if(eater < j){
							eat[i].push_back(j);
							eat[i+1].push_back(j);
						}
					}else{
						eat[i].push_back(j);
						eat[i+1].push_back(j);
					}
				}
			}
		}
		eater++;
	}
	
	for(int i=1; i<=2*N; i++){
		memset(visited, 0, sizeof(visited));
		dfs(i);
	}
	
	for(int i=1; i<=N; i++){
		if(b[i] == 0) count++;
	}
	
	cout << count;
	
	return 0;
}
