#include <iostream>
#include <queue>

using namespace std;

int main(){
	
	int V;
	
	cin >> V;
	
	int edge[100][100] = {0,};
	int result[100][100] = {0,};
	
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cin >> edge[i][j];
		}
	}
	
	for(int i=0; i<V; i++){
		
		queue<int> q;
		
		int visit_yn[100][100] = {0,};
		
		q.push(i);
		
		int flag = 0;
		
		while(!q.empty()){
			int t = q.front();
			
			q.pop();
			
			if(i == t && flag) continue;
			
			for(int j=0; j<V; j++){
				if(edge[t][j] == 1 && visit_yn[t][j] == 0){
					result[t][j] = 1;
					result[i][j] = 1;
					visit_yn[t][j] = 1;
					q.push(j);
				}
			}
			
			flag = 1;
		}
	}
	
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
