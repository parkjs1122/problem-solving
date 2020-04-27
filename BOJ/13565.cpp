#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	
	int M, N;
	
	int dir_x[4] = {0, 1, 0, -1}, dir_y[4] = {1, 0, -1, 0};
	
	cin >> M; cin >> N;
	
	int matrix[M][N];
	int visit[M][N];
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			scanf("%1d", &matrix[i][j]);
			visit[i][j] = 0;
		}
	}
	
	queue<pair<int, int> > q;
	
	for(int i=0; i<N; i++){
		if(matrix[0][i] == 0){
			q.push(make_pair(0, i));
			visit[0][i] = 1;
		}
	}
	
	pair<int, int> now;
	
	while(!q.empty()){
		now = q.front();
		q.pop();
		
		for(int i=0; i<4; i++){
			int new_x = now.second + dir_x[i];
			int new_y = now.first + dir_y[i];
			
			if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && matrix[new_y][new_x] != 1 && visit[new_y][new_x] != 1){
				if(new_y == M-1){
					cout << "YES\n"; return 0;
				}
				q.push(make_pair(new_y, new_x));
				visit[new_y][new_x] = 1;
			}
		}
	}
	
	cout << "NO\n";
	
	return 0;
}
