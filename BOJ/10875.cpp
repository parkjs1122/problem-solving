#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct line{
	unsigned long long from_x;
	unsigned long long from_y;
	unsigned long long to_x;
	unsigned long long to_y;
};

int main(){
	
	int dir_x[4] = {0, 1, 0, -1};
	int dir_y[4] = {-1, 0, 1, 0};
	
	vector<struct line> lines;
	
	unsigned long long M, T, center;
	
	cin >> M; cin >> T;
	
	center = M;
	
	M = 2*M+1;
	
	queue<pair<unsigned long long, unsigned long long> > turn;
	
	for(int i=0; i<T; i++){
		char temp;
		unsigned long long time, dir;
		cin >> time; cin >> temp;
		
		if(temp == 'R'){
			dir = 0;
		}else if(temp == 'L'){
			dir = 1;
		}
		
		turn.push(make_pair(time, dir));
	}
	
	unsigned long long time = 0, dir = 1, x = center, y = center;
	
	struct line new_line;
		
	new_line.from_x = x;
	new_line.from_y = y;
	new_line.to_x = x;
	new_line.to_y = y;
	
	lines.push_back(new_line);
	
	while(!turn.empty()){
		unsigned long long t = turn.front().first;
		unsigned long long d = turn.front().second;
		turn.pop();
		
		unsigned long long out_t = 999999999999;
		
		switch(dir){
			case 0:
				for(int i=0; i<lines.size(); i++){
					if(lines[i].from_y < y && ((lines[i].from_x >= x && lines[i].to_x <= x) || (lines[i].from_x <= x && lines[i].to_x >= x))){
						if(t >= (y - lines[i].from_y)){
							unsigned long long tt = time + (y - lines[i].from_y);
							if(tt < out_t) out_t = tt;
						}
					}
					if(lines[i].from_x == x && lines[i].to_x == x && lines[i].from_y < y && lines[i].to_y < y){
						if(lines[i].from_y >= lines[i].to_y && t >= (y - lines[i].from_y)){
							unsigned long long tt = time + (y - lines[i].from_y);
							if(tt < out_t) out_t = tt;
						}
						
						if(lines[i].to_y >= lines[i].from_y && t >= (y - lines[i].to_y)){
							unsigned long long tt = time + (y - lines[i].to_y);
							if(tt < out_t) out_t = tt;
						}
					}
				}
				break;
			case 1:
				for(int i=0; i<lines.size(); i++){
					if(lines[i].from_x > x && ((lines[i].from_y >= y && lines[i].to_y <= y) || (lines[i].from_y <= y && lines[i].to_y >= y))){
						if(t >= (lines[i].from_x - x)){
							unsigned long long tt = time + (lines[i].from_x - x);
							if(tt < out_t) out_t = tt;
						}
					}
					if(lines[i].from_y == y && lines[i].to_y == y && lines[i].from_x > x && lines[i].to_x > x){
						if(lines[i].from_x >= lines[i].to_x && t >= (lines[i].to_x - x)){
							unsigned long long tt = time + (lines[i].to_x - x);
							if(tt < out_t) out_t = tt;
						}
						
						if(lines[i].to_x >= lines[i].from_x && t >= (lines[i].from_x - x)){
							unsigned long long tt = time + (lines[i].from_x - x);
							if(tt < out_t) out_t = tt;
						}
					}
				}
				break;
			case 2:
				for(int i=0; i<lines.size(); i++){
					if(lines[i].from_y > y && ((lines[i].from_x >= x && lines[i].to_x <= x) || (lines[i].from_x <= x && lines[i].to_x >= x))){
						if(t >= (lines[i].from_y - y)){
							unsigned long long tt = time + (lines[i].from_y - y);
							if(tt < out_t) out_t = tt;
						}
					}
					if(lines[i].from_x == x && lines[i].to_x == x && lines[i].from_y > y && lines[i].to_y > y){
						if(lines[i].from_y >= lines[i].to_y && t >= (lines[i].to_y - y)){
							unsigned long long tt = time + (lines[i].to_y - y);
							if(tt < out_t) out_t = tt;
						}
						
						if(lines[i].to_y >= lines[i].from_y && t >= (lines[i].from_y - y)){
							unsigned long long tt = time + (lines[i].from_y - y);
							if(tt < out_t) out_t = tt;
						}
					}
				}
				break;
			case 3:
				for(int i=0; i<lines.size(); i++){
					if(lines[i].from_x < x && ((lines[i].from_y >= y && lines[i].to_y <= y) || (lines[i].from_y <= y && lines[i].to_y >= y))){
						if(t >= (x - lines[i].from_x)){
							unsigned long long tt = time + (x - lines[i].from_x);
							if(tt < out_t) out_t = tt;
						}
					}
					if(lines[i].from_y == y && lines[i].to_y == y && lines[i].from_x < x && lines[i].to_x < x){
						if(lines[i].from_x >= lines[i].to_x && t >= (x - lines[i].from_x)){
							unsigned long long tt = time + (x - lines[i].from_x);
							if(tt < out_t) out_t = tt;
						}
						
						if(lines[i].to_x >= lines[i].from_x && t >= (x - lines[i].to_x)){
							unsigned long long tt = time + (x - lines[i].to_x);
							if(tt < out_t) out_t = tt;
						}
					}
				}
				break;
		}
		
		if(out_t != 999999999999){
			cout << out_t;
			return 0;
		}
		
		struct line new_line;
		
		new_line.from_x = x;
		new_line.from_y = y;
		
		unsigned long long new_x = x + dir_x[dir] * t;
		unsigned long long new_y = y + dir_y[dir] * t;
		
		if(new_x >= 0 && new_x < M && new_y >=0 && new_y < M){
			time += t;
			x = new_x;
			y = new_y;
		}else{
			switch(dir){
				case 0:
					cout << time + y + 1;
					return 0;
					break;
				case 1:
					cout << time + (M - x);
					return 0;
					break;
				case 2:
					cout << time + (M - y);
					return 0;
					break;
				case 3:
					cout << time + x + 1;
					return 0;
					break;
			}
			return 0;
		}
		
		new_line.to_x = x;
		new_line.to_y = y;
		
		switch(dir){
			case 0:
				if(d == 0) dir = 1;
				if(d == 1) dir = 3;
				lines.push_back(new_line);
				break;
			case 1:
				if(d == 0) dir = 2;
				if(d == 1) dir = 0;
				lines.push_back(new_line);
				break;
			case 2:
				if(d == 0) dir = 3;
				if(d == 1) dir = 1;
				lines.push_back(new_line);
				break;
			case 3:
				if(d == 0) dir = 0;
				if(d == 1) dir = 2;
				lines.push_back(new_line);
				break;
		}
	}
	
	if(T == 0){
		cout << center + 1;
		return 0;
	}
	
	switch(dir){
		case 0:
			cout << time + y + 1;
			break;
		case 1:
			cout << time + M - x;
			break;
		case 2:
			cout << time + M - y;
			break;
		case 3:
			cout << time + x + 1;
			break;
	}
	
	return 0;
}
