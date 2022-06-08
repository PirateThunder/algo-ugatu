#include <bits/stdc++.h>
using namespace std;

#include "IGraph.h"

#ifndef HASHGRAPH_H
#define HASHGRAPH_H


class HashGraph : public IGraph {
	vector<unordered_set<int>> g;

public:
	HashGraph();

	HashGraph(int n);

	~HashGraph();

	virtual void AddEdge(int from, int to) override;

	virtual  int VerticesCount() const override;

	virtual void FindAllAdjacentIn(int vertex, vector<int>& vertices) const override;

	virtual void FindAllAdjacentOut(int vertex, vector<int>& vertices) const override;
};

#endif // HASHGRAPH_H
