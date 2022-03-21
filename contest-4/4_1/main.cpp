// ID: 66254381
// https://contest.yandex.ru/contest/35212/problems/4_1/

#include <iostream>
#include <vector>
using namespace std;

long long f(long long n, long long m, vector<vector<long long>>& v) {
    if (n < 0 || m < 0) {
        return 0;
    }
    if (m == 1) {
        if (n == 1) {
            return 1;
        }
        return 0;
    }
    else if (n <= 2) {
        return 1;
    }
    if (v[n][m] >= 0) {
        return v[n][m];
    }
    v[n][m] =  f(n, m - 1, v) + f(n - m, m - 1, v);
    return v[n][m];
}

int main() {
    long long n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<vector<long long>> v(n + 10, vector<long long>(n + 10, -1));
    cout << f(n, n, v) << "\n";
    return 0;
}