#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int K;
	
	cin >> K;
	
	int score[K];
	
	for(int i=0; i<K; i++){
		cin >> score[i];
	}
	
	sort(score, score + K);
	
	int remain_score = K - 1;
	int result = 1;
	
	for(int i=0; i<K-1; i++){
		
		int temp = remain_score-- - score[i];
		
		score[i] = 0;
		
		for(int j=K-1; j>i; j--){
			if(score[j] > 0){
				score[j]--;
				if(--temp == 0) break;
			}
		}
		
		if(temp > 0){
			result = -1;
			break;
		}
		
		sort(score + i + 1, score + K);
		
	}
	
	for(int i=0; i<K; i++){
		if(score[i] > 0) result = -1;
	}
	
	cout << result;
	
	return 0;
}
