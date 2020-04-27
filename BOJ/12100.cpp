#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct puzzle{
	int matrix[20][20];
	int size;
	int depth;
};

stack<struct puzzle> dfs;

int move_up(struct puzzle *puz){
	
	int new_mat[20][20];
	int size = puz->size;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			new_mat[i][j] = puz->matrix[i][j];
			puz->matrix[i][j] = 0;
		}
	}
	
	for(int i=0; i<size; i++){
		
		queue<int> mat;
		
		for(int j=0; j<size; j++){
			if(new_mat[j][i] > 0) mat.push(new_mat[j][i]);
		}
		
		int prev = 0, count = 0;
		
		while(!mat.empty()){
			int temp = mat.front();
			mat.pop();
			if(temp == prev){
				temp += temp;
				count--;
				puz->matrix[count++][i] = temp;
				temp = 0;
			}else{
				puz->matrix[count++][i] = temp;
			}
			prev = temp;
		}
	}
}

int move_down(struct puzzle *puz){
	
	int new_mat[20][20];
	int size = puz->size;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			new_mat[i][j] = puz->matrix[i][j];
			puz->matrix[i][j] = 0;
		}
	}
	
	for(int i=0; i<size; i++){
		
		queue<int> mat;
		
		for(int j=size - 1; j>=0; j--){
			if(new_mat[j][i] > 0) mat.push(new_mat[j][i]);
		}
		
		int prev = 0, count = size - 1;
		
		while(!mat.empty()){
			int temp = mat.front();
			mat.pop();
			if(temp == prev){
				temp += temp;
				count++;
				puz->matrix[count--][i] = temp;
				temp = 0;
			}else{
				puz->matrix[count--][i] = temp;
			}
			prev = temp;
		}
	}
}

int move_left(struct puzzle *puz){
	
	int new_mat[20][20];
	int size = puz->size;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			new_mat[i][j] = puz->matrix[i][j];
			puz->matrix[i][j] = 0;
		}
	}
	
	for(int i=0; i<size; i++){
		
		queue<int> mat;
		
		for(int j=0; j<size; j++){
			if(new_mat[i][j] > 0) mat.push(new_mat[i][j]);
		}
		
		int prev = 0, count = 0;
		
		while(!mat.empty()){
			int temp = mat.front();
			mat.pop();
			if(temp == prev){
				temp += temp;
				count--;
				puz->matrix[i][count++] = temp;
				temp = 0;
			}else{
				puz->matrix[i][count++] = temp;
			}
			prev = temp;
		}
	}
}

int move_right(struct puzzle *puz){
	
	int new_mat[20][20];
	int size = puz->size;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			new_mat[i][j] = puz->matrix[i][j];
			puz->matrix[i][j] = 0;
		}
	}
	
	for(int i=0; i<size; i++){
		
		queue<int> mat;
		
		for(int j=size-1; j>=0; j--){
			if(new_mat[i][j] > 0) mat.push(new_mat[i][j]);
		}
		
		int prev = 0, count = size - 1;
		
		while(!mat.empty()){
			int temp = mat.front();
			mat.pop();
			if(temp == prev){
				temp += temp;
				count++;
				puz->matrix[i][count--] = temp;
				temp = 0;
			}else{
				puz->matrix[i][count--] = temp;
			}
			prev = temp;
		}
	}
}

void make_nodes(struct puzzle puz){
	for(int i=0; i<4; i++){
		struct puzzle child;
		child.size = puz.size;
		for(int j=0; j<puz.size; j++){
			for(int k=0; k<puz.size; k++){
				child.matrix[j][k] = puz.matrix[j][k];
			}
		}
		
		if(i==0) move_up(&child);
		else if(i==1) move_right(&child);
		else if(i==2) move_down(&child);
		else if(i==3) move_left(&child);
		
		child.depth = puz.depth + 1;
		
		dfs.push(child);
	}
}

int main(){
	
	int size, max = 0;
	
	cin >> size;
	
	struct puzzle root;
	
	root.size = size;
	
	root.depth = 0;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cin >> root.matrix[i][j];
		}
	}
	
	dfs.push(root);
	
	while(!dfs.empty()){
		struct puzzle temp = dfs.top();
		dfs.pop();
		
		if(temp.depth < 5) make_nodes(temp);
		
		if(temp.depth == 5){
			for(int i=0; i<temp.size; i++){
				for(int j=0; j<temp.size; j++){
					if(temp.matrix[i][j] > max) max = temp.matrix[i][j];
				}
			}
		}
	}
	
	cout << max;
	
	return 0;
}
