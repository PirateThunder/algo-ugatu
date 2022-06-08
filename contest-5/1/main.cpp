#include <bits/stdc++.h>
using namespace std;

#include <IGraph.h>

#include <ListGraph.h>
#include <MatrixGraph.h>
#include <HashGraph.h>
#include <ArcGraph.h>

/*
IGraph (интерфейс орграфа)

ListGraph (списки смежности)
MatrixGraph (матрица)
SetGraph (хэш-таблицы)
ArcGraph (один массив пар {from, to})
*/

int main(int argc, char *argv[]) {
	vector<int> v;

	cout << "ListGraph\n";
	ListGraph listGraph;
	//ListGraph listGraph(5);

	listGraph.AddEdge(1, 2);
	listGraph.AddEdge(3, 4);
	listGraph.AddEdge(1, 3);
	listGraph.AddEdge(2, 3);

	cout << listGraph.VerticesCount() << "\n";

	for (int i = 0; i < listGraph.VerticesCount(); i++) {
		cout << i << ": ";
		listGraph.FindAllAdjacentOut(i, v);
		for (auto x: v) cout << x << " ";
		cout << "\n";
	}

	listGraph.FindAllAdjacentIn(3, v);
	for (auto x: v) cout << x << " ";
	cout << "\n\n";


	cout << "MatrixGraph\n";
	MatrixGraph matrixGraph;
	//MatrixGraph matrixGraph(5);

	matrixGraph.AddEdge(1, 2);
	matrixGraph.AddEdge(3, 4);
	matrixGraph.AddEdge(1, 3);
	matrixGraph.AddEdge(2, 3);

	cout << matrixGraph.VerticesCount() << "\n";

	for (int i = 0; i < matrixGraph.VerticesCount(); i++) {
		cout << i << ": ";
		matrixGraph.FindAllAdjacentOut(i, v);
		for (auto x: v) cout << x << " ";
		cout << "\n";
	}

	matrixGraph.FindAllAdjacentIn(3, v);
	for (auto x: v) cout << x << " ";
	cout << "\n\n";


	cout << "HashGraph\n";
	HashGraph hashGraph;
	//HashGraph hashGraph(5);

	hashGraph.AddEdge(1, 2);
	hashGraph.AddEdge(3, 4);
	hashGraph.AddEdge(1, 3);
	hashGraph.AddEdge(2, 3);

	cout << hashGraph.VerticesCount() << "\n";

	for (int i = 0; i < hashGraph.VerticesCount(); i++) {
		cout << i << ": ";
		hashGraph.FindAllAdjacentOut(i, v);
		for (auto x: v) cout << x << " ";
		cout << "\n";
	}

	hashGraph.FindAllAdjacentIn(3, v);
	for (auto x: v) cout << x << " ";
	cout << "\n\n";


	cout << "ArcGraph\n";
	ArcGraph arcGraph;
	//ArcGraph arcGraph(5); // нету

	arcGraph.AddEdge(1, 2);
	arcGraph.AddEdge(3, 4);
	arcGraph.AddEdge(1, 3);
	arcGraph.AddEdge(2, 3);

	cout << arcGraph.VerticesCount() << "\n";

	for (int i = 0; i < arcGraph.VerticesCount(); i++) {
		cout << i << ": ";
		arcGraph.FindAllAdjacentOut(i, v);
		for (auto x: v) cout << x << " ";
		cout << "\n";
	}

	arcGraph.FindAllAdjacentIn(3, v);
	for (auto x: v) cout << x << " ";
	cout << "\n\n";

}
