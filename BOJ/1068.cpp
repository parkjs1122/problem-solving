#include <iostream>
#include <stack>

using namespace std;

int K, D, P, tree[50][50], parent[50], leaf = 0, root;
int visited[50];

void dfs(int cur){
	visited[cur] = 1;
	
	int flag = 0;
	
	for(int i=0; i<50; i++){
		if(tree[cur][i] == 1 && visited[i] != 1){
			dfs(i);
			flag = 1;
		}
	}
	
	if(!flag) leaf++;
}

int main(){
	
	cin >> K;
	
	for(int i=0; i<K; i++){
		for(int j=0; j<K; j++){
			tree[i][j] = 0;
		}
		visited[i] = 0;
	}
	
	for(int i=0; i<K; i++){
		cin >> P;
		
		if(P != -1) tree[P][i] = 1;
		else root = i;
		parent[i] = P;
	}
	
	cin >> D;
	
	if(D == root){
		cout << 0 << "\n";
		return 0;
	}
	else tree[parent[D]][D] = 0;
	
	dfs(root);
	
	cout << leaf << "\n";
	
	return 0;
}
