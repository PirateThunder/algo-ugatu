// ID: 68571440
// https://contest.yandex.ru/contest/37787/problems/5/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 2e5;

int order[N], now_suff_add, n;

int get_order(int pos) {
	if (pos < n) {
		return order[pos];
	}
	return -1;
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return get_order(a.second + now_suff_add) < get_order(b.second + now_suff_add);
}

vector<int> build_suf_ar(string s) {
	n = s.length();
	int cnt[26];
	for (int i = 0; i < 26; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 1; i < 26; i++) {
		cnt[i] += cnt[i - 1];
	}
	vector<pair<int, int>> suf;
	for (int i = 0; i < n; i++) {
		order[i] = cnt[s[i] - 'a'] - 1;
		suf.push_back({order[i], i});
	}
	sort(suf.begin(), suf.end(), comp);
	now_suff_add = 1;
	while (now_suff_add <= n) {
		sort(suf.begin(), suf.end(), comp);
		for (int i = suf.size() - 2; i >= 0; i--) {
			if (order[suf[i].second + now_suff_add] < order[suf[i + 1].second + now_suff_add]) {
				suf[i].first = i;
			}
			else {
				suf[i].first = min(suf[i + 1].first, suf[i].first);
			}
		}
		for (auto [order_suf, suf_num] : suf) {
			order[suf_num] = order_suf;
		}
		now_suff_add += now_suff_add;
	}
	vector<int> answer;
	for (auto [order, suf_num] : suf) {
		//cout << order << " " << suf_num << "\n";
		answer.push_back(suf_num);
	}
	now_suff_add = 0;
	
	return answer;
}

vector<int> kasai(string s, vector<int> sa) {
	int n=s.size(),k=0;
	vector<int> lcp(n,0);
	vector<int> rank(n,0);
	
	for(int i=0; i<n; i++) {
		rank[sa[i]]=i;
	}
		
	for(int i=0; i<n; i++, k?k--:0) {
		if(rank[i]==n-1) {
			k=0;
			continue;
		}
		int j=sa[rank[i]+1];
		while(i+k<n && j+k<n && s[i+k]==s[j+k])
			k++;
		lcp[rank[i]]=k;
	}
	lcp.pop_back();
	return lcp;
}
	
int main() {
	string s;
	cin >> s;
	vector<int> suf_ar = build_suf_ar(s);
	vector<int> lcp = kasai(s, suf_ar);

	int n = s.length();
	int c = 0;
	for (auto x: lcp) c += x;
	
	cout << n*(n+1)/2 - c;
	return 0;
}