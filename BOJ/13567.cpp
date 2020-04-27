#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	
	int M, n;
	
	cin >> M; cin >> n;
	
	int y = M, x = 0;
	
	queue<pair<int, int> > list;
	
	for(int i=0; i<n; i++){
		string s;
		int move;
		
		cin >> s; cin >> move;
		
		if(s == "MOVE"){
			list.push(make_pair(0, move));
		}else if(s == "TURN"){
			list.push(make_pair(1, move));
		}
	}
	
	pair<int, int> m;
	
	int dir = 2;
	
	while(!list.empty()){
		m = list.front();
		list.pop();
		
		int m1 = m.first;
		int m2 = m.second;
		
		if(m1 == 0){
			switch(dir){
				case 1:
					if(y-m2 >= 0 && y-m2 <= M){
						y = y - m2;
					}else{
						cout << -1 << "\n";
						return 0;
					}
				break;
				
				case 2:
					if(x+m2 >= 0 && x+m2 <= M){
						x = x + m2;
					}else{
						cout << -1 << "\n";
						return 0;
					}
				break;
				
				case 3:
					if(y+m2 >= 0 && y+m2 <= M){
						y = y + m2;
					}else{
						cout << -1 << "\n";
						return 0;
					}
				break;
				
				case 4:
					if(x-m2 >= 0 && x-m2 <= M){
						x = x - m2;
					}else{
						cout << -1 << "\n";
						return 0;
					}
				break;
			}
		}else{
			switch(dir){
				case 1:
					if(m2 == 0){
						dir = 4;
					}else{
						dir = 2;
					}
				break;
				
				case 2:
					if(m2 == 0){
						dir = 1;
					}else{
						dir = 3;
					}
				break;
				
				case 3:
					if(m2 == 0){
						dir = 2;
					}else{
						dir = 4;
					}
				break;
				
				case 4:
					if(m2 == 0){
						dir = 3;
					}else{
						dir = 1;
					}
				break;
			}
		}
	}
	
	cout << x << " " << M - y << "\n";
	
	return 0;
}
