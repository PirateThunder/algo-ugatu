#include <bits/stdc++.h>
using namespace std;

#include "HashGraph.h"

HashGraph::HashGraph() {}

HashGraph::HashGraph(int n) {
    g.resize(n);
}

HashGraph::~HashGraph() {
    g.clear();
}

 void HashGraph::AddEdge(int from, int to)  {
    if (g.size() <= max(from, to)) {
        g.resize(max(from, to) + 1);
    }
    g[from].insert(to);
}

  int HashGraph::VerticesCount() const  {
    return g.size();
}

 void HashGraph::FindAllAdjacentIn(int vertex, vector<int>& vertices) const  {
    vertices.clear();
    for (int i = 0; i < g.size(); i++) {
        for (auto x: g[i]) {
            if (x == vertex) {
                vertices.push_back(i);
                break;
            }
        }
    }
    //sort(vertices.begin(), vertices.end());
}

 void HashGraph::FindAllAdjacentOut(int vertex, vector<int>& vertices) const  {
    vertices.assign(g[vertex].begin(), g[vertex].end());
    sort(vertices.begin(), vertices.end());
}
