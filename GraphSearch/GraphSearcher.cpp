#include "GraphSearcher.h"
#include <iostream>
#include <stack>

using namespace std;

GraphSearcher::GraphSearcher(Graph* graph) {
    this->graph = graph;
    this->nodes = new int[graph->vAmount];
}

void GraphSearcher::nullNodes() {
    for (int i = 0; i < graph->vAmount; i++)
        nodes[i] = 0;
}

int GraphSearcher::search(int v) {
    int vAmount = graph->vAmount;
    int** adjMatrix = graph->adjMatrix;

    int r;
    printf("%i ", v);
    nodes[v] = 1;
    for (r = 0; r < vAmount; r++)
        if ((adjMatrix[v][r] != 0) && (nodes[r] == 0))
            search(r);
    return 1;
}

int GraphSearcher::searchAll() {
    for (int i = 0; i < graph->vAmount; i++) {
        nullNodes();
        printf("%i) ", i);
        search(i);
        printf("\n\n");
    }
    return 1;
}