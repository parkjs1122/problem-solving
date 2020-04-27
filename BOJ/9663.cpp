#include <iostream>

using namespace std;

int result = 0;

void dfs(int D, int depth, int C, int track[16]){
	
	if(depth == D){
		result++;
		return;
	}
	
	if(depth == 0){
		for(int i=1; i<=D; i++){
			dfs(D, depth+1, i, track);
		}
	}else{
		track[depth] = C;
		
		int temp[16] = {0,};
		
		if(C-1 >= 0) temp[C-1] = 1;
		if(C+1 <= D) temp[C+1] = 1;
		
		for(int i=1; i<=depth; i++){
			temp[track[i]] = 1;
		}
		
		for(int i=1; i<=depth; i++){
			for(int j=1; j<=D; j++){
				int y = depth + 1 - i;
				int x = track[i] - j;
				
				if(y == x || y == -x) temp[j] = 1;
			}
		}
		
		for(int i=1; i<=D; i++){
			if(temp[i] != 1) dfs(D, depth+1, i, track);
		}
	}
}

int main(){
	
	int N;
	
	cin >> N;
	
	int track[16] = {0,};
	
	dfs(N, 0, 0, track);
	
	cout << result;
	
	return 0;
}
