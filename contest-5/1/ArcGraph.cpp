#include <bits/stdc++.h>
using namespace std;

#include "ArcGraph.h"

ArcGraph::ArcGraph() {}

ArcGraph::~ArcGraph() {
    g.clear();
}

 void ArcGraph::AddEdge(int from, int to)  {
    g.push_back({from, to});
}

  int ArcGraph::VerticesCount() const   {
    if (g.empty()) {
        return 0;
    }
    else {
        int max_v = 0;
        for (auto [from, to]: g) {
            max_v = max(max_v, max(from, to));
        }
        return max_v + 1;
    }
}

 void ArcGraph::FindAllAdjacentIn(int vertex, vector<int>& vertices) const  {
    vertices.clear();
    for (auto [from, to]: g) {
        if (to == vertex) {
            vertices.push_back(from);
        }
    }
}

 void ArcGraph::FindAllAdjacentOut(int vertex, vector<int>& vertices) const  {
    vertices.clear();
    for (auto [from, to]: g) {
        if (from == vertex) {
            vertices.push_back(to);
        }
    }
}
