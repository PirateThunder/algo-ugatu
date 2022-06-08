// ID: 68612539
// https://contest.yandex.ru/contest/37787/problems/3/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ull;

int main() {
	string s;
	cin>>s;
	ull n=s.length();
	
	vector<ull> d1 (n, 0);
	ull l=0, r=-1;
	for (ull i=0; i<n; ++i) {
		ull k = i>r ? 1 : min (d1[l+r-i], r-i+1);
		while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) ++k;
		d1[i] = k;
		if (i+k-1 > r) l = i-k+1, r = i+k-1;
	}
	vector<ull> d2 (n, 0);
	l=0, r=-1;
	for (ull i=0; i<n; ++i) {
		ull k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
		while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1]) ++k;
		d2[i] = k;
		if (i+k-1 > r) l = i-k, r = i+k-1;
	}
	
	ull res = 0;
	for (ull i = 0; i < n; i++) {
		res += d1[i]-1;
		if (i!=0) res += d2[i];
	}
	cout << res;
}