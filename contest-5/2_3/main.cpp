// ID: 67776513
// https://contest.yandex.ru/contest/36361/problems/2.3/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> color;

bool is_dvudolny_yeeaah = true;

void dfs(int v, int cur_color) {
	if (!is_dvudolny_yeeaah) return;
	color[v] = cur_color;
	
	for (auto x: g[v]) {
		if (!color[x]) {
			if (cur_color == 1) dfs(x, 2);
			else if (cur_color == 2) dfs(x, 1);
		}
		else {
			if (color[v] == color[x]) {
				is_dvudolny_yeeaah = false;
				return;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	color.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(0, 1);
	if (is_dvudolny_yeeaah) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}