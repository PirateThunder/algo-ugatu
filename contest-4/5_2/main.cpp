// ID: 66276388
// https://contest.yandex.ru/contest/35212/problems/5_2/

#include <iostream>
#include <vector>
using namespace std;

typedef std::vector<std::vector<int>> Tree;

void dfs1(const Tree& tree, int node, std::vector<int>& _count, std::vector<int>& d) {
    for (int child : tree[node]) {
        dfs1(tree, child, _count, d);
    }

    _count[node] = 1;
    for (int child : tree[node]) {
        _count[node] += _count[child];
    }
    d[node] = 0;
    for (int child : tree[node]) {
        d[node] += _count[child] + d[child];
    }
}

void dfs2(const Tree& tree, int node, std::vector<int>& _count, std::vector<int>& d, std::vector<int>& summ) {
    summ[0] = d[0];
    for (int child : tree[node]) {
        summ[child] = summ[node] + tree.size() - 2 * _count[child];
        dfs2(tree, child, _count, d, summ);
    }
}

std::vector<int> calc_summes(const Tree& tree) {
    std::vector<int> _count(tree.size());
    std::vector<int> d(tree.size());

    dfs1(tree, 0, _count, d);

    std::vector<int> summ(tree.size());
    dfs2(tree, 0, _count, d, summ);

    return summ;
}


int main() {
    int n;
    std::cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; i++) {
        int parent, child;
        std::cin >> parent >> child;
        tree[parent].push_back(child);
    }
    
    std::vector<int> result = calc_summes(tree);
    for (int v : result) {
        std::cout << v << std::endl;
    }
}