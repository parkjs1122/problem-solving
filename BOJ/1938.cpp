#include <iostream>
#include <queue>
#include <utility>

#define VERTICAL 0
#define HORIZON 1

using namespace std;

int main(){
	
	int N, bcount = 0, ecount = 0, bi, ei;
	
	cin >> N;
	
	int matrix[N][N], visited[N][N][2], targetDir;
	
	queue<pair<int, int> > Q;
	
	pair<int, int> target;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			matrix[i][j] = 0;
			visited[i][j][HORIZON] = 0;
			visited[i][j][VERTICAL] = 0;
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			char temp;
			
			scanf("%1c", &temp);
			
			if(temp == '0'){
				matrix[i][j] = 0;
			}else if(temp == '1'){
				matrix[i][j] = 1;
			}else if(temp == 'B'){
				matrix[i][j] = 0;
				bcount++;
				if(bcount == 1) bi = i;
			}else if(temp == 'E'){
				matrix[i][j] = 0;
				ecount++;
				if(ecount == 1) ei = i;
			}
			
			if(bcount == 2){
				Q.push(make_pair(i, j));
				if(i == bi) visited[i][j][VERTICAL] = 1;
				else visited[i][j][HORIZON] = 1;
			}
			if(ecount == 2){
				target = make_pair(i, j);
				if(i == ei) targetDir = VERTICAL;
				else targetDir = HORIZON;
			}
		}
	}
	
	while(!Q.empty()){
		pair<int, int> now = Q.front();
		Q.pop();
		
		if(visited[now.first][now.second][VERTICAL] > 0){
			
		}
		
		if(visited[now.first][now.second][HORIZON] > 0){
			
		}
	}
	
	return 0;
}
