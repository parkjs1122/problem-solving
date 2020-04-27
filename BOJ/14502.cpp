#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

int main(){
	
	int M, N;
	
	cin >> M; cin >> N;
	
	int map[M][N];
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	
	int start_i = 0;
	int start_j = 0;
	
	int temp_map[M][N];
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			temp_map[i][j] = map[i][j];
		}
	}
	
	int max = 0;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(temp_map[i][j] == 0){
				temp_map[i][j] = 1;
				int start_i = i;
				int start_j = j;
				
				for(int k=start_i; k<M; k++){
					int l;
					if(k == start_i) l = start_j;
					else l = 0;
					while(l < N){
						if(temp_map[k][l] == 0){
							temp_map[k][l] = 1;
							int start_k = k;
							int start_l = l;
							
							for(int m=start_k; m<M; m++){
								int n;
								if(m == start_k) n = start_l;
								else n = 0;
								while(n < N){
									if(temp_map[m][n] == 0){
										temp_map[m][n] = 1;
										
//										for(int v=0; v<M; v++){
//											for(int b=0; b<N; b++){
//												cout << temp_map[v][b] << " ";
//											}
//											
//											cout << "\n";
//										}
//										
//										cout << "\n";

										queue<pair<int, int> > bfs;
										int visit[M][N];

										for(int v=0; v<M; v++){
											for(int b=0; b<N; b++){
												if(temp_map[v][b] == 2){
													bfs.push(make_pair(v, b));
												}
												visit[v][b] = 0;
											}
										}
										
										while(!bfs.empty()){
											pair<int, int> now = bfs.front();
											bfs.pop();
											
											for(int v=0; v<4; v++){
												int new_x = now.second + dir_x[v];
												int new_y = now.first + dir_y[v];
												
												if(new_x >= 0 && new_x < N && new_y >=0 && new_y < M && visit[new_y][new_x] != 1 && temp_map[new_y][new_x] == 0){
													bfs.push(make_pair(new_y, new_x));
													visit[new_y][new_x] = 1;
												}
											}
										}
										
										int count = 0;
										
										for(int v=0; v<M; v++){
											for(int b=0; b<N; b++){
												if(visit[v][b] != 1 && temp_map[v][b] == 0) count++;
											}
										}
										
										if(max < count) max = count;
										
										temp_map[m][n] = 0;
									}
									n++;
								}
							}
							temp_map[k][l] = 0;
						}
						l++;
					}
				}
				temp_map[i][j] = 0;
			}
		}
	}
	
	cout << max;
	
	return 0;
}
