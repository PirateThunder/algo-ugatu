// ID: 66228085
// https://contest.yandex.ru/contest/35212/problems/2_2/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)  {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> v;
    int from, to;
    while (cin >> from >> to) {
        v.push_back({from, to});
    }
    sort(v.begin(), v.end(), cmp);
    int j = 0, res = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= v[j].second) {
            res++;
            j = i;
        }
    }
    cout << res << "\n";
    return 0;
}
