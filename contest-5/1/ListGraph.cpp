#include <bits/stdc++.h>
using namespace std;

#include "ListGraph.h"

ListGraph::ListGraph() {}

ListGraph::ListGraph(int n) {
    g.resize(n);
}

ListGraph::~ListGraph() {
    g.clear();
}

void ListGraph::AddEdge(int from, int to) {
    if (g.size() <= max(from, to)) {
        g.resize(max(from, to) + 1);
    }
    g[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return g.size();
}

void ListGraph::FindAllAdjacentIn(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] == vertex) {
                vertices.push_back(i);
                break;
            }
        }
    }
}

void ListGraph::FindAllAdjacentOut(int vertex, vector<int>& vertices) const {
    vertices.assign(g[vertex].begin(), g[vertex].end());
}
