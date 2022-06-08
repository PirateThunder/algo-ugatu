// ID: 68359041
// https://contest.yandex.ru/contest/37787/problems/2_1/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> pi;
    while (cin >> x) {
        pi.push_back(x);
    }
    
    if (pi.size() == 0) {
        return 0;
    }
    string ans = "a";
    for (int i = 1; i < pi.size(); i++) {
        if (pi[i] == 0) {
	    vector<bool> u(26, false);
            int k = pi[i - 1];
            while (k > 0) {
                u[res[k] - 'a'] = true;
                k = pi[k - 1];
            }
            char c = 'b';
            while (u[c - 'a']) {
                c++;
            }
            ans += c;
        }
        else {
            ans += ans[pi[i] - 1];
        }
    }
    cout << ans;
}