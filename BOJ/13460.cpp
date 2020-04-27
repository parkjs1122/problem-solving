#include <iostream>
#include <stack>

using namespace std;

int N, M;

struct board{
	int matrix[10][10];
	int depth;
	int rx;
	int ry;
	int bx;
	int by;
	int rstate;
	int bstate;
};

stack<struct board> dfs;

void move(struct board *b, int dir){
	
	int flag;
	
	switch(dir){
		case 1:
			if(b->by < b->ry){
				flag = 0;
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by-1][b->bx] == 0 || b->matrix[b->by-1][b->bx] == 4){
					b->by--;
					if(b->matrix[b->by][b->bx] == 4){
						b->bstate = 1;
						flag = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->by][b->bx] = 3;
				
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry-1][b->rx] == 0 || b->matrix[b->ry-1][b->rx] == 4){
					b->ry--;
					if(b->matrix[b->ry][b->rx] == 4){
						b->rstate = 1;
						break;
					}
				}
			}else{
				flag = 0;
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry-1][b->rx] == 0 || b->matrix[b->ry-1][b->rx] == 4){
					b->ry--;
					if(b->matrix[b->ry][b->rx] == 4){
						b->rstate = 1;
						flag = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->ry][b->rx] = 2;
				
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by-1][b->bx] == 0 || b->matrix[b->by-1][b->bx] == 4){
					b->by--;
					if(b->matrix[b->by][b->bx] == 4){
						b->bstate = 1;
						break;
					}
				}
				b->matrix[b->by][b->bx] = 3;
			}
		break;
		
		case 2:
			if(b->bx > b->rx){
				flag = 0;
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by][b->bx+1] == 0 || b->matrix[b->by][b->bx+1] == 4){
					b->bx++;
					if(b->matrix[b->by][b->bx] == 4){
						flag = 1;
						b->bstate = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->by][b->bx] = 3;
				
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry][b->rx+1] == 0 || b->matrix[b->ry][b->rx+1] == 4){
					b->rx++;
					if(b->matrix[b->ry][b->rx] == 4){
						b->rstate = 1;
						break;
					}
				}
				b->matrix[b->ry][b->rx] = 2;
			}else{
				flag = 0;
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry][b->rx+1] == 0 || b->matrix[b->ry][b->rx+1] == 4){
					b->rx++;
					if(b->matrix[b->ry][b->rx] == 4){
						flag = 1;
						b->rstate = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->ry][b->rx] = 2;
				
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by][b->bx+1] == 0 || b->matrix[b->by][b->bx+1] == 4){
					b->bx++;
					if(b->matrix[b->by][b->bx] == 4){
						b->bstate = 1;
						break;
					}
				}
				b->matrix[b->by][b->bx] = 3;
			}
		break;
		
		case 3:
			if(b->by > b->ry){
				flag = 0;
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by+1][b->bx] == 0 || b->matrix[b->by+1][b->bx] == 4){
					b->by++;
					if(b->matrix[b->by][b->bx] == 4){
						flag = 1;
						b->bstate = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->by][b->bx] = 3;
				
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry+1][b->rx] == 0 || b->matrix[b->ry+1][b->rx] == 4){
					b->ry++;
					if(b->matrix[b->ry][b->rx] == 4){
						b->rstate = 1;
						break;
					}
				}
				b->matrix[b->ry][b->rx] = 2;
			}else{
				flag = 0;
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry+1][b->rx] == 0 || b->matrix[b->ry+1][b->rx] == 4){
					b->ry++;
					if(b->matrix[b->ry][b->rx] == 4){
						flag = 1;
						b->rstate = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->ry][b->rx] = 2;
				
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by+1][b->bx] == 0 || b->matrix[b->by+1][b->bx] == 4){
					b->by++;
					if(b->matrix[b->by][b->bx] == 4){
						b->bstate = 1;
						break;
					}
				}
				b->matrix[b->by][b->bx] = 3;
			}
		break;
		
		case 4:
			if(b->bx < b->rx){
				flag = 0;
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by][b->bx-1] == 0 || b->matrix[b->by][b->bx-1] == 4){
					b->bx--;
					if(b->matrix[b->by][b->bx] == 4){
						flag = 1;
						b->bstate = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->by][b->bx] = 3;
				
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry][b->rx-1] == 0 || b->matrix[b->ry][b->rx-1] == 4){
					b->rx--;
					if(b->matrix[b->ry][b->rx] == 4){
						b->rstate = 1;
						break;
					}
				}
				b->matrix[b->ry][b->rx] = 2;
			}else{
				flag = 0;
				b->matrix[b->ry][b->rx] = 0;
				while(b->matrix[b->ry][b->rx-1] == 0 || b->matrix[b->ry][b->rx-1] == 4){
					b->rx--;
					if(b->matrix[b->ry][b->rx] == 4){
						flag = 1;
						b->rstate = 1;
						break;
					}
				}
				if(flag == 0) b->matrix[b->ry][b->rx] = 2;
				
				b->matrix[b->by][b->bx] = 0;
				while(b->matrix[b->by][b->bx-1] == 0 || b->matrix[b->by][b->bx-1] == 4){
					b->bx--;
					if(b->matrix[b->by][b->bx] == 4){
						b->bstate = 1;
						break;
					}
				}
				b->matrix[b->by][b->bx] = 3;
			}
		break;
	}

}

void make_nodes(struct board b){
	for(int i=1; i<=4; i++){
		struct board new_b;
		
		new_b.depth = b.depth + 1;
		new_b.rx = b.rx;
		new_b.ry = b.ry;
		new_b.bx = b.bx;
		new_b.by = b.by;
		new_b.bstate = b.bstate;
		new_b.rstate = b.rstate;
		
		for(int j=0; j<N; j++){
			for(int k=0; k<M; k++){
				new_b.matrix[j][k] = b.matrix[j][k];
			}
		}
		
		move(&new_b, i);
		
		dfs.push(new_b);
		
	}
}

int main(){
	
	cin >> N; cin >> M;
	
	struct board root;
	
	char temp;
	
	root.depth = 0;
	root.bstate = 0;
	root.rstate = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1c", &temp);
			
			if(temp == '#'){
				root.matrix[i][j] = 1;
			}else if(temp == '.'){
				root.matrix[i][j] = 0;
			}else if(temp == 'R'){
				root.matrix[i][j] = 2;
				root.rx = j;
				root.ry = i;
			}else if(temp == 'B'){
				root.matrix[i][j] = 3;
				root.bx = j;
				root.by = i;
			}else if(temp == 'O'){
				root.matrix[i][j] = 4;
			}else{
				j--;
			}
		}
	}
	
	dfs.push(root);
	
	int min = 100;
	
	while(!dfs.empty()){
		struct board now = dfs.top();
		dfs.pop();
		
		if(now.rstate == 1 && now.bstate != 1){
			if(min > now.depth) min = now.depth;
		}
		
		if(now.depth < 10) make_nodes(now);
		
	}
	
	if(min != 100){
		cout << min;
	}else{
		cout << -1;
	}
	
	return 0;
}
