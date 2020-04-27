#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	
	int dir_x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int dir_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	
	int M, N;
	
	while(1){
		cin >> N; cin >> M;
		
		if(N == 0 && M == 0) break;
		
		int matrix[M][N];
		int visit[M][N];
		
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				cin >> matrix[i][j];
				visit[i][j] = 0;
			}
		}
		
		int island_count = 0;
		
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				if(matrix[i][j] == 1 && visit[i][j] != 1){
					queue<pair<int, int> > q;
					
					q.push(make_pair(i, j));
					visit[i][j] = 1;
					
					island_count++;
				
					pair<int, int> bfs;
					
					while(!q.empty()){
						bfs = q.front();
						q.pop();
						
						for(int k=0; k<8; k++){
							int new_x = bfs.second + dir_x[k];
							int new_y = bfs.first + dir_y[k];
							
							if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && visit[new_y][new_x] != 1 && matrix[new_y][new_x] == 1){
								q.push(make_pair(new_y, new_x));
								visit[new_y][new_x] = 1;
							}
						}
					}
				}
			}
		}
		
		cout << island_count << "\n";
	}
	
	return 0;
}
