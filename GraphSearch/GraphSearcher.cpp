#include "GraphSearcher.h"
#include <iostream>
#include <stack>

using namespace std;

GraphSearcher::GraphSearcher(Graph* graph) {
    this->graph = graph;
}

string GraphSearcher::getPathString(int path[], int pathLength) {
    std::string result = "";
    for (int i = 0; i < pathLength - 1; i++) result += to_string(path[i]) + " -> "; result += to_string(path[pathLength - 1]);
    return result;
}

int GraphSearcher::search(int v, bool visited[], int path[], int pathLength) {
    int vAmount = graph->vAmount;
    int** adjMatrix = graph->adjMatrix;

    visited[v] = true;
    path[pathLength] = v;
    pathLength++;

    int r;
    for (r = 0; r < vAmount; r++) {

        if ((adjMatrix[v][r] != 0) && (visited[r] == false)) {
            search(r, visited, path, pathLength);
        }
    }

    if (pathLength == vAmount) {
        bool satCondition = adjMatrix[path[0]][path[vAmount - 1]] == 0 && adjMatrix[path[vAmount - 1]][path[0]] == 0;
        if (satCondition)
            paths.push(getPathString(path, pathLength).c_str());
    }

    visited[v] = false;
    pathLength--;
    return 1;
}

int GraphSearcher::searchAll() {
    int V = graph->vAmount;

    for (int i = 0; i < V; i++) {
        int* path = new int[V];
        bool* visited = new bool[V];
        int pathLength = 0;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            path[i] = -1;
        }

        search(i, visited, path, pathLength);

        delete path;
        delete visited;
    }
    return 1;
}