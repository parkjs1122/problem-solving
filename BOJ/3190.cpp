#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	
	int dir_x[4] = {0, 1, 0, -1};
	int dir_y[4] = {-1, 0, 1, 0};
	
	int M, center, T;
	
	cin >> M;
	
	center = M;
	
	M = 2*M+1;
	
	int matrix[M][M];
	
	for(int i=0; i<M; i++){
		for(int j=0; j<M; j++){
			matrix[i][j] = 0;
		}
	}
	
	cin >> T;
	
	queue<pair<int, int> > turn;
	
	for(int i=0; i<T; i++){
		char temp;
		int time, dir;
		cin >> time; cin >> temp;
		
		if(temp == 'R'){
			dir = 0;
		}else if(temp == 'L'){
			dir = 1;
		}
		
		turn.push(make_pair(time, dir));
	}
	
	int time = 0, dir = 1, x = center, y = center;
	
	matrix[x][y] = 1;
	
	while(!turn.empty()){
		int t = turn.front().first;
		int d = turn.front().second;
		turn.pop();
		
		while(t--){
			
			time++;
			
			x += dir_x[dir];
			y += dir_y[dir];
			
			if(x >= 0 && x < M && y >=0 && y < M && matrix[y][x] == 0){
				matrix[y][x] = 1;
			}else{
				cout << time;
				return 0;
			}
		}
		
		switch(dir){
			case 0:
				if(d == 0) dir = 1;
				if(d == 1) dir = 3;
				break;
			case 1:
				if(d == 0) dir = 2;
				if(d == 1) dir = 0;
				break;
			case 2:
				if(d == 0) dir = 3;
				if(d == 1) dir = 1;
				break;
			case 3:
				if(d == 0) dir = 0;
				if(d == 1) dir = 2;
				break;
		}
	}
	
	return 0;
}
