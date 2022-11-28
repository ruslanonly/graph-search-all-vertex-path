#pragma once
#include "Graph.h"
#include <stack>

using namespace std;

class GraphSearcher
{
private:
	Graph* graph;

	int search(int v, bool visited[], int stack[], int pathLength);
public:
	GraphSearcher(Graph* graph);
	int searchAll();
};

