#include <iostream>

using namespace std;

int main(){
	
	int day;
	
	cin >> day;
	
	int dynamic[day];
	int T[day];
	int P[day];
	
	for(int i=0; i<day; i++){
		dynamic[i] = 0;
		
		cin >> T[i]; cin >> P[i];
	}
	
	for(int i=0; i<day; i++){
		
		int max = 0;
		
		for(int j=0; j<i; j++){
			if(dynamic[j] > max) max = dynamic[j];
		}
		
		int end = T[i] + i - 1;
		int n = max + P[i];
		
		if(end < day){
			if(dynamic[end] < n) dynamic[end] = n;
		}
	}
	
	int result = 0;
	
	for(int i=0; i<day; i++){
		if(dynamic[i] > result) result = dynamic[i];
	}
	
	cout << result;
		
	return 0;	
}
