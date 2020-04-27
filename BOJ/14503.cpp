#include <iostream>

using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {-1, 0, 1, 0};
int map[50][50];
int N, M, X, Y, dir, count = 0;

int main(){
	
	cin >> N; cin >> M;
	cin >> Y; cin >> X; cin >> dir;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
	
	while(true){
		if(map[Y][X] == 0) count++;
		map[Y][X] = 2;
		
		int flag = 0;
		
		for(int i=0; i<4; i++){
			dir = (dir + 3) % 4;
			int new_x = X + dir_x[dir];
			int new_y = Y + dir_y[dir];
			
			if(map[new_y][new_x] == 0){
				flag = 1;
				X = new_x;
				Y = new_y;
				break;
			}
		}
		
		if(flag == 0){
			int back_d = (dir + 2) % 4;
			int back_x = X + dir_x[back_d];
			int back_y = Y + dir_y[back_d];
			
			if(map[back_y][back_x] != 1){
				X = back_x;
				Y = back_y;
			}
			else break;
		}
	}
	
	cout << count;
	
	return 0;
}

