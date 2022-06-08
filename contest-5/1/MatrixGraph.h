#include <bits/stdc++.h>
using namespace std;

#include "IGraph.h"

#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H


class MatrixGraph: public IGraph {
	vector<vector<int>> g;

public:
	MatrixGraph();

	MatrixGraph(int n);

	~MatrixGraph();

	virtual void AddEdge(int from, int to) override;

	virtual  int VerticesCount() const override;

	virtual void FindAllAdjacentIn(int vertex, vector<int>& vertices) const override ;

	virtual void FindAllAdjacentOut(int vertex, vector<int>& vertices) const override ;

};

#endif // MATRIXGRAPH_H
