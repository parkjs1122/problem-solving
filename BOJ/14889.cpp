#include <iostream>
#include <vector>

using namespace std;

int N, stats[21][21], visit[21], minimum = 0x7fffffff;

void cal() {
	vector<int> teamA, teamB;
	int resultA = 0, resultB = 0, result;

	for (int i = 1; i <= 20; i++) {
		if (visit[i] == 1) teamA.push_back(i);
		else teamB.push_back(i);
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			resultA += stats[teamA[i]][teamA[j]];
			resultB += stats[teamB[i]][teamB[j]];
		}
	}

	result = resultA - resultB;

	if (result < 0) result *= -1;

	if (result < minimum) minimum = result;

}

void dfs(int n, int depth) {

	if (depth == N / 2) {
		cal();
	}

	for (int i = n + 1; i <= N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(i, depth + 1);
			visit[i] = 0;
		}
	}

	
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> stats[i][j];
		}
	}

	visit[1] = 1;
	dfs(1, 1);
	visit[0] = 1;

	cout << minimum << endl;

	return 0;
}