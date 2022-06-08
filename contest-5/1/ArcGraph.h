#include <bits/stdc++.h>
using namespace std;

#include "IGraph.h"

#ifndef ARCGRAPH_H
#define ARCGRAPH_H


class ArcGraph: public IGraph {
	vector<pair<int, int>> g;

public:
	ArcGraph();

	~ArcGraph();

	virtual void AddEdge(int from, int to) override;

	virtual  int VerticesCount() const override;

	virtual void FindAllAdjacentIn(int vertex, vector<int>& vertices) const override;

	virtual void FindAllAdjacentOut(int vertex, vector<int>& vertices) const override;

};

#endif // ARCGRAPH_H
