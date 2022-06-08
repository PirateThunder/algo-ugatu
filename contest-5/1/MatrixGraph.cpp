#include <bits/stdc++.h>
using namespace std;

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph() {}

MatrixGraph::MatrixGraph(int n) {
    g.resize(n, vector<int>(n));
}

MatrixGraph::~MatrixGraph() {
    g.clear();
}

void MatrixGraph::AddEdge(int from, int to) {
    if (g.size() <= max(from, to)) {
        int n = max(from, to) + 1;
        g.resize(n, vector<int>(n));
    }

    g[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return g.size();
}

void MatrixGraph::FindAllAdjacentIn(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < g.size(); i++) {
        if (g[i][vertex] == 1) {
            vertices.push_back(i);
        }
    }
}

void MatrixGraph::FindAllAdjacentOut(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < g.size(); i++) {
        if (g[vertex][i] == 1) {
            vertices.push_back(i);
        }
    }
}
