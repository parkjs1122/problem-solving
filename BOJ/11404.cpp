#include <iostream>

using namespace std;

int main(){
	
	int M, N;
	
	cin >> M; cin >> N;
	
	long long result[M+1][M+1];
	
	for(int i=1; i<=M; i++){
		for(int j=1; j<=M; j++){
			if(i == j) result[i][j] = 0;
			else result[i][j] = 999999999;
		}
	}
	
	for(int i=0; i<N; i++){
		int S, T, cost;
		
		cin >> S; cin >> T; cin >> cost;
		
		result[S][T] = (result[S][T] > cost)?cost:result[S][T];
	}
	
	for(int i=1; i<=M; i++){
		for(int j=1; j<=M; j++){
			for(int k=1; k<=M; k++){
				int new_distance = result[j][i] + result[i][k];
				if(result[j][k] > new_distance) result[j][k] = new_distance;
			}
		}
	}
	
	for(int i=1; i<=M; i++){
		for(int j=1; j<=M; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
