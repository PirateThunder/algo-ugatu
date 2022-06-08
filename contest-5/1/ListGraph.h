#include <bits/stdc++.h>
using namespace std;

#include "IGraph.h"

#ifndef LISTGRAPH_H
#define LISTGRAPH_H

class ListGraph : public IGraph {
	vector<vector<int>> g;

public:
	ListGraph();

	ListGraph(int n);

	~ListGraph();

	virtual void AddEdge(int from, int to) override;

	virtual  int VerticesCount() const override;
	virtual void FindAllAdjacentIn(int vertex, vector<int>& vertices) const override;

	virtual void FindAllAdjacentOut(int vertex, vector<int>& vertices) const override;
};

#endif // LISTGRAPH_H
