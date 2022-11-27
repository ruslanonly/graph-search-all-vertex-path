#pragma once
#include "Graph.h"
class GraphSearcher
{
private:
	Graph* graph;

	int* nodes;
	void nullNodes();
	int search(int v);
public:
	GraphSearcher(Graph* graph);
	int searchAll();
};

