#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	
	int test_case;
	
	int direction_x[4] = {0, 1, 0, -1};
	int direction_y[4] = {1, 0, -1, 0};
	
	cin >> test_case;
	
	for(int T=0; T<test_case; T++){
		int M, N, K;
		
		cin >> M; cin >> N; cin >> K;
		
		int baechu[N][M];
		int visit_yn[N][M];
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				baechu[i][j] = 0;
				visit_yn[i][j] = 0;
			}
		}
		
		int result_count = 0;
		
		for(int i=0; i<K; i++){
			int x, y;
			
			cin >> x; cin >> y;
			
			baechu[y][x] = 1;
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(baechu[i][j] == 1){
					result_count++;
					
					pair<int, int> now;
					
					queue<pair<int, int> > visit;
					
					visit.push(make_pair(i, j));
					visit_yn[i][j] = 1;
					baechu[i][j] = 3;
					
					while(!visit.empty()){
						now = visit.front();
						
						visit.pop();
						
						for(int k=0; k<4; k++){
							int new_y = now.first + direction_y[k];
							int new_x = now.second + direction_x[k];
							
							if(new_x >= 0 && new_x < M && new_y >= 0 && new_y < N && baechu[new_y][new_x] == 1 && visit_yn[new_y][new_x] != 1){
								visit.push(make_pair(new_y, new_x));
								visit_yn[new_y][new_x] = 1;
								baechu[new_y][new_x] = 3;
							}
						}
					}
				}
			}
		}
		
		cout << result_count << "\n";
	}
	
	return 0;
}
