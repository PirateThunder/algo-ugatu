// ID: 68007600
// https://contest.yandex.ru/contest/36361/problems/6/

#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

const int N = 100000;
vector<pair<int, int>> g[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	int dist[n];
	int was[n];
	for (int i = 0; i < n; i++) {
		dist[i] = 1e9;
		was[i] = 0;
	}
	dist[0] = 0;
	set<pair<int, int>> S;
	S.insert({0, 0});
	int cost_mst = 0;
	while (!S.empty()) {
		auto [distanse, v] = *S.begin();
		cost_mst += distanse;
		S.erase(S.begin());
		was[v] = 1;
		for (auto [u, cost] : g[v]) {
			if (dist[u] > cost && was[u] == 0) {
				S.erase({dist[u], u});
				dist[u] = cost;
				S.insert({dist[u], u});
			}
		}
	}
    long long pivo = 75;
    cout << cost_mst << "\n";
}