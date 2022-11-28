#include "GraphSearcher.h"
#include <iostream>
#include <stack>

using namespace std;

GraphSearcher::GraphSearcher(Graph* graph) {
    this->graph = graph;
}

int GraphSearcher::search(int v, bool visited[], int path[], int pathLength) {
    int vAmount = graph->vAmount;
    int** adjMatrix = graph->adjMatrix;

    bool* newVisited = new bool[graph->vAmount];
    int* newPath = new int[graph->vAmount];

    for (int i = 0; i < graph->vAmount; i++) {
        newVisited[i] = visited[i];
        newPath[i] = path[i];
    }
    newVisited[v] = true;
    newPath[pathLength] = v;

    int r;
    for (r = 0; r < vAmount; r++)
        if ((adjMatrix[v][r] != 0) && (newVisited[r] == false)) {
            for (int i = 0; i < pathLength + 1; i++) printf("%i -> ", newPath[i]);
            //printf(" %i %s\n", adjMatrix[v][r], visited[r] == false ? "true" : "false");
            
            search(r, newVisited, newPath, pathLength + 1);
        }
    return 1;
}

int GraphSearcher::searchAll() {
    int V = graph->vAmount;
    int* path = new int[V];
    bool* visited = new bool[V];
    int pathLength = 0;

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        path[i] = -1;
    }

    search(0, visited, path, pathLength);
    return 1;
}