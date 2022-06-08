#include <bits/stdc++.h>
using namespace std;

#ifndef IGRAPH_H
#define IGRAPH_H

struct IGraph {
	virtual ~IGraph() {}


	virtual void AddEdge(int from, int to) = 0;

	virtual int VerticesCount() const = 0;

	virtual void FindAllAdjacentIn(int vertex, vector<int>& vertices) const = 0;
	virtual void FindAllAdjacentOut(int vertex, vector<int>& vertices) const = 0;

};

#endif // IGRAPH_H
