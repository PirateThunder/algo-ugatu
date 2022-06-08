// ID: 68359041
// https://contest.yandex.ru/contest/37787/problems/1/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix_function (string s) {
	int n = s.length();
	vector<int> pi(n);
	for (int i=1; i < n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j]) j = pi[j-1];
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	}
	return pi;
}

int main(int argc, char *argv[]) {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int s_length_old = s.length();
	s += '#' + t;
	int s_length_new = s.length();
	vector<int> pi = prefix_function(s);
	for (int i = s_length_old+1; i < s_length_new; i++) {
		if (pi[i] == s_length_old) {
			cout << i - 2*s_length_old << " ";
		}
	}
}