#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N, M, result = 999999;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

int map1[50][50];
int map2[50][50];
int visit1[50][50];
int visit2[50][50];

int main(){
	
	cin >> M; cin >> N;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			char temp;
			
			scanf("%1c", &temp);
			
			if(temp == '.'){
				map1[i][j] = 0;
				map2[i][j] = 0;
			}
			else if(temp == '*'){
				map1[i][j] = 1;
				map2[i][j] = 1;
			}
			else if(temp == 'S'){
				map2[i][j] = 2;
			}
			else if(temp == 'D'){
				map1[i][j] = 3;
				map2[i][j] = 3;
			}
			else if(temp == 'X'){
				map1[i][j] = 4;
				map2[i][j] = 4;
			}
			else j--;
			
			visit1[i][j] = -1;
			visit2[i][j] = -1;
		}
	}
	
	// Water
	queue<pair<int, int> > water;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(map1[i][j] == 1){
				water.push(make_pair(i, j));
				visit1[i][j] = 0;
			}
		}
	}
	
	while(!water.empty()){
		pair<int, int> water_point = water.front();
		water.pop();
		
		for(int i=0; i<4; i++){
			int new_water_x = water_point.second + dir_x[i];
			int new_water_y = water_point.first + dir_y[i];
			
			if(new_water_x >=0 && new_water_x < N && new_water_y >= 0 && new_water_y < M && map1[new_water_y][new_water_x] < 2 && visit1[new_water_y][new_water_x] < 0){
				map1[new_water_y][new_water_x] = 1;
				visit1[new_water_y][new_water_x] = visit1[water_point.first][water_point.second] + 1;
				water.push(make_pair(new_water_y, new_water_x));
			}
		}
	}
	
	// Hog
	queue<pair<int, int> > hog;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(map2[i][j] == 2){
				hog.push(make_pair(i, j));
				visit2[i][j] = 0;
			}
		}
	}
	
	while(!hog.empty()){
		pair<int, int> hog_point = hog.front();
		hog.pop();
		
		for(int i=0; i<4; i++){
			int new_hog_x = hog_point.second + dir_x[i];
			int new_hog_y = hog_point.first + dir_y[i];
			
			if(new_hog_x >=0 && new_hog_x < N && new_hog_y >= 0 && new_hog_y < M && map2[new_hog_y][new_hog_x] == 0 && visit2[new_hog_y][new_hog_x] < 0){
				if(visit1[new_hog_y][new_hog_x] >= 0 && visit1[new_hog_y][new_hog_x] > visit2[hog_point.first][hog_point.second] + 1){
					visit2[new_hog_y][new_hog_x] = visit2[hog_point.first][hog_point.second] + 1;
					hog.push(make_pair(new_hog_y, new_hog_x));
				}
				if(visit1[new_hog_y][new_hog_x] < 0){
					visit2[new_hog_y][new_hog_x] = visit2[hog_point.first][hog_point.second] + 1;
					hog.push(make_pair(new_hog_y, new_hog_x));
				}
				
			}
			
			if(new_hog_x >=0 && new_hog_x < N && new_hog_y >= 0 && new_hog_y < M && map2[new_hog_y][new_hog_x] == 3 && visit2[new_hog_y][new_hog_x] < 0){
				visit2[new_hog_y][new_hog_x] = visit2[hog_point.first][hog_point.second] + 1;
				hog.push(make_pair(new_hog_y, new_hog_x));
				result = visit2[new_hog_y][new_hog_x];
			}
		}
	}
	
	if(result == 999999) cout << "KAKTUS";
	else cout << result;	
	
	return 0;
}
