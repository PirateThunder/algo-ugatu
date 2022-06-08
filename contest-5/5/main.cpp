// ID: 67656858
// https://contest.yandex.ru/contest/36361/problems/5/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<double>> g;
bool flag = false;

void dfs(int v, double w, vector<int> u) {
	if (u[v] == 2) {
		if (w > 1) {
			flag = true;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (v == i || g[v][i] == -1) continue;
		if (u[i] != 1) {
			vector<int> u2(n);
			u2.assign(u.begin(), u.end());
			if (u2[i] != 2) u2[i] = 1;
			dfs(i, w*g[v][i], u2);
		}
	}
}

void main_dfs(int x) {
	vector<int> u(n, 0);
	u[x] = 2; // 0 не были 1 были 2 окончить цикл
	
	for (int i = 0; i < n; i++) {
		if (x == i) continue;
		vector<int> u2(n);
		u2.assign(u.begin(), u.end());
		if (u2[i] != 2) u2[i] = 1;
		dfs(i, g[x][i], u2);
		
		break;
	}
}

int main(int argc, char *argv[]) {
	cin >> n;
	g.resize(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				g[i][j] = 0;
				continue;
			}
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (!flag) main_dfs(i);
	}

	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}