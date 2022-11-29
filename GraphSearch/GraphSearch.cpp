#include <iostream>
#include "Graph.h";
#include "GraphSearcher.h"

int main()
{
    int vertexAmount = 4;
    //printf("How many vertexes graph will have?\n"); scanf_s("%i", &size);
    
    /*Graph graph = Graph(vertexAmount);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 6, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 1, 1);
    graph.addEdge(2, 6, 1);
    graph.addEdge(3, 1, 1);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 3, 1);
    graph.addEdge(4, 5, 1);
    graph.addEdge(5, 4, 1);
    graph.addEdge(5, 6, 1);
    graph.addEdge(6, 0, 1);
    graph.addEdge(6, 2, 1);
    graph.addEdge(6, 5, 1);
    graph.displayMatrix();*/

    Graph graph = Graph(vertexAmount);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 3, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 1, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 0, 1);
    graph.addEdge(3, 1, 1);
    graph.addEdge(3, 2, 1);
    graph.displayMatrix();

    GraphSearcher graphSearcher = GraphSearcher(&graph);
    graphSearcher.searchAll();

    printf("Path: %s", graphSearcher.paths.top().c_str());

    delete graph.adjMatrix;
}
