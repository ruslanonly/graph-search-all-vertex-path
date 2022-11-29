#pragma once
#include "Graph.h"
#include <stack>
#include <string>

using namespace std;

class GraphSearcher
{
private:
	Graph* graph;

	int search(int v, bool visited[], int path[], int pathLength);
	string getPathString(int path[], int pathLength);
public:
	stack<string> paths;

	GraphSearcher(Graph* graph);
	int searchAll();
};

