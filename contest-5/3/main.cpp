// ID: 67773340
// https://contest.yandex.ru/contest/36361/problems/3/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g1, g2;
vector<bool> used;
vector<int> order;
vector<int> component;
vector<int> dsu;

vector<pair<int, int>> is_s_t;

int s = 0, t = 0, q = 0;

void dfs1(int v) {
	used[v] = true;
	for (int i = 0; i < g1[v].size(); i++) {
		if (!used[g1[v][i]]) {
			dfs1(g1[v][i]);
		}
	}
	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	component.push_back(v);
	for (int i = 0; i < g2[v].size(); i++) {
		if (!used[g2[v][i]]) {
			dfs2(g2[v][i]);
		}
	}
}

void dfs3(int v) {
	//cout << "(" << v + 1 << " " << dsu[v] << ")";
	//cout << "\nnow at " << v << " dsu(" << dsu[v] << "), looking for i: ";
	used[v] = true;
	for (int i = 0; i < g1[v].size(); i++) {
		if (!used[g1[v][i]]) {
			//dfs3(g1[v][i]);
			//cout << "/v, dsu[v]: " << v << " " << dsu[v] << " i, dsu[i]: " << i << " " << dsu[i] << "/";
			//cout << i << " dsu(" << dsu[i] << ") ";
			
			if (dsu[v] != dsu[g1[v][i]]) {
				//cout << "tut";
				is_s_t[dsu[v]].first++;
				is_s_t[dsu[g1[v][i]]].second++;
			}
			
			dfs3(g1[v][i]);
		}
	}
}

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	g1.resize(n);
	g2.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) continue;
		a--;
		b--;
		bool is_second_road = false;
		for (int j = 0; j < g1[a].size(); j++) {
			if (g1[a][j] == b) {
				is_second_road = true;
				break;
			}
		}
		if (!is_second_road) {
			g1[a].push_back(b);
			g2[b].push_back(a);
		}
	}

	used.assign(n, false);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	
	used.assign(n, false);
	dsu.resize(n);
	int cursor = 0;
	for (int i = 0; i < n; i++) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v);
			if (component.size() == n) {
				cout << 0;
				return 0;
			}
			for (auto x: component) {
				dsu[x] = cursor;
			}
			component.clear();
			cursor++;
		}
	}
	
	is_s_t.resize(cursor, {0, 0});
	used.assign(n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < g1[i].size(); j++) {
			if (dsu[i] != dsu[g1[i][j]]) {
				is_s_t[dsu[i]].first++;
				is_s_t[dsu[g1[i][j]]].second++;
			}
		}
	}
	for (int i = 0; i < cursor; i++) {
		if (!is_s_t[i].first && !is_s_t[i].second) {
			 q++;
		}
		else if ((is_s_t[i].first || is_s_t[i].second) && is_s_t[i].first - is_s_t[i].second != 0) {
			if (is_s_t[i].first) {
				s++;
			}
			if (is_s_t[i].second) {
				t++;
			}
		}
		
	}
	cout << max(s + q, t + q);
	
}