#include <iostream>

using namespace std;

int main(){
	
	int N;
	
	cin >> N;
	
	int dist[N+1][N+1];
	int adj[N+1][N+1];
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> dist[i][j];
			adj[i][j] = 0;
		}
	}
	
	int sum = 0, to;
	
	if(N % 2 == 1){
		to = N / 2 + 1;
	}else{
		to = N / 2;
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(int k=1; k<=N; k++){
				if((dist[j][i] + dist[i][k]) == dist[j][k]){
					dist[j][k] = 0;
				}
			}
		}
	}
	
	cout << "\n";
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << dist[i][j] << " ";
			sum += dist[i][j];
		}
		cout << "\n";
	}
	
	cout << sum;
	
	return 0;
}
