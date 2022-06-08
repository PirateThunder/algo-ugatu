// ID: 67548118
// https://contest.yandex.ru/contest/36361/problems/2.1/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int min_cycle = 1e9;
	for (int i = 0; i < n; i++) {
		queue<int> q;
		vector<int> state(n, WHITE);
		vector<int> path(n, 0);
		q.push(i);
		state[i] = GRAY;
		
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			
			bool is_cycle = false;
			int v2;
			for (auto x: g[v]) {
				if (state[x] == GRAY) {
					is_cycle = true;
					v2 = x;
					break;
				}
			}
			if (is_cycle) {
				min_cycle = min(min_cycle, path[v] + path[v2] + 1);
				break;
			}
			
			state[v] = BLACK;
			for (auto x: g[v]) {
				if (state[x] == WHITE) {
					q.push(x);
					state[x] = GRAY;
					path[x] = path[v] + 1;
				}
			}
		}
	}
	
	if (min_cycle == 1e9) {
		cout << -1;
	}
	else {
		cout << min_cycle;
	}
	return 0;
}