#include <iostream>

using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
	
int M, N;

int map[500][500];
int visit[500][500];
int max_result = 0;

void dfs(int x, int y, int depth, int result){
	
	if(depth == 4){
		if(max_result < result) max_result = result;
		return;
	}
	
	for(int i=0; i<4; i++){
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];
		
		if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && visit[new_y][new_x] != 1){
			visit[new_y][new_x] = 1;
			dfs(new_x, new_y, depth+1, result+map[new_y][new_x]);
			visit[new_y][new_x] = 0;
		}
	}
}

int main(){
	
	cin >> M; cin >> N;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			visit[i][j] = 1;
			dfs(j, i, 1, map[i][j]);
			visit[i][j] = 0;
		}
	}
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			int sum = map[i][j];
			
			int count = 0, min = 999999;
			
			for(int k=0; k<4; k++){
				int new_x = j + dir_x[k];
				int new_y = i + dir_y[k];
				
				if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M){
					sum += map[new_y][new_x];
					if(min > map[new_y][new_x]) min = map[new_y][new_x];
					count++;
				}
			}
			
			if(count == 4){
				if(sum - min > max_result) max_result = sum - min;
			}
			
			if(count == 3){
				if(sum > max_result) max_result = sum;
			}
		}
	}
	
	cout << max_result;
	
	return 0;
}
