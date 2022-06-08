// ID: 67583596
// https://contest.yandex.ru/contest/36361/problems/4/

#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b) continue;
		bool is_second_road = false;
		for (int j = 0; j < g[a].size(); j++) {
			if (g[a][j].first == b) {
				is_second_road = true;
				if (g[a][j].second > c) {
					g[a][j].second = c;
				}
				break;
			}
		}
		for (int j = 0; j < g[b].size(); j++) {
			if (g[b][j].first == a) {
				if (g[b][j].second > c) {
					g[b][j].second = c;
				}
				break;
			}
		}
		if (!is_second_road) {
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}
	}

	int FROM, TO;
	cin >> FROM >> TO;
	
	vector<int> distance(n, 1e9);
	distance[FROM] = 0;
	set<pair<int, int>> s;
	s.insert({distance[FROM], FROM});
	while (!s.empty()){
		int v = s.begin()->second;
		s.erase(s.begin());
		for (int j = 0; j < g[v].size(); j++) {
			if (distance[v] + g[v][j].second < distance[g[v][j].first]) {
				s.erase({distance[g[v][j].first], g[v][j].first});
				distance[g[v][j].first] = distance[v] + g[v][j].second;
				s.insert({distance[g[v][j].first], g[v][j].first});
			}
		}
	}
	cout << distance[TO];
	return 0;
}