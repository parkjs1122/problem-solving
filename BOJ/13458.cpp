#include <iostream>
#include <queue>

using namespace std;

int main(){
	
	int N, B, C;
	long long result = 0;
	
	cin >> N;
	
	int testee[N];
	
	for(int i=0; i<N; i++){
		cin >> testee[i];
	}
	
	cin >> B; cin >> C;
	
	for(int i=0; i<N; i++){
		if(testee[i] > 0){
			if(testee[i] - B >= 0) testee[i] -= B;
			else testee[i] = 0;
		}
		result++;
	}
	
	for(int i=0; i<N; i++){
		if(testee[i] % C == 0){
			result += (testee[i] / C);
		}else{
			result += (testee[i] / C) + 1;
		}
	}
	
	cout << result;
	
	return 0;
}
