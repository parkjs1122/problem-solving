#include <iostream>

using namespace std;

int N, L, num, map[101][101], availableL, needL, result;

int main() {

	cin >> N; cin >> L;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		availableL = 1; needL = 0;
		for (int j = 1; j <= N; j++) {
			if (j == N) {
				if (needL == 0) result++;
			}
			else {
				if (map[i][j] == map[i][j + 1]) {
					if (needL > 0) needL--;
					else availableL++;
				}
				else if (map[i][j] + 1 == map[i][j + 1]) {
					if (availableL >= L) availableL = 1;
					else break;
				}
				else if (map[i][j] == map[i][j + 1] + 1) {
					if (needL == 0) {
						needL = L - 1;
						availableL = 0;
					}
					else break;
				}
				else break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		availableL = 1; needL = 0;
		for (int j = 1; j <= N; j++) {
			if (j == N) {
				if (needL == 0) result++;
			}
			else {
				if (map[j][i] == map[j + 1][i]) {
					if (needL > 0) needL--;
					else availableL++;
				}
				else if (map[j][i] + 1 == map[j + 1][i]) {
					if (availableL >= L) availableL = 1;
					else break;
				}
				else if (map[j][i] == map[j + 1][i] + 1) {
					if (needL == 0) {
						needL = L - 1;
						availableL = 0;
					}
					else break;
				}
				else break;
			}
		}
	}

	cout << result << endl;

	return 0;
}