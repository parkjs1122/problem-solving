#include <iostream>

using namespace std;

int main(){
	
	int N;
	
	cin >> N;
	
	int num[N], dynamic[N];
	
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
	
	int max = 0;
	
	for(int i=0; i<N; i++){
		dynamic[i] = num[i];
		
		for(int j=0; j<i; j++){
			if(num[j] < num[i] && dynamic[i] < num[i] + dynamic[j]) dynamic[i] = num[i] + dynamic[j];
		}
		
		if(max < dynamic[i]) max = dynamic[i];
	}
	
	cout << max;
	
	return 0;
}
