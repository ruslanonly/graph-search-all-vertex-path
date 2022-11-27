#include "Graph.h"
#include <iostream>

void Graph::extendMatrix(int extendAmount) {
	int initVAmount = vAmount;
	vAmount = vAmount + extendAmount;

	int** copyMatrix = new int*[vAmount];

	for (int i = 0; i < vAmount; i++) {
		copyMatrix[i] = new int[vAmount];
		for (int j = 0; j < vAmount; j++) {
			if (i > initVAmount - 1 || j > initVAmount - 1) copyMatrix[i][j] = 0;
			else copyMatrix[i][j] = adjMatrix[i][j];
		}
	}

	adjMatrix = copyMatrix;
};

void Graph::shrinkMatrix(int vertex) {
	int initVAmount = vAmount;
	vAmount = vAmount - 1;
	int** copyMatrix = new int* [vAmount];
	for (int i = 0; i < initVAmount; i++) {
		if (i == vertex) continue;
		copyMatrix[i] = new int[vAmount];
		for (int j = 0; j < initVAmount; j++) {
			if (j == vertex) continue;
			copyMatrix[i][j] = adjMatrix[i][j];
		}
	}
};

void Graph::displayMatrix() {
	for (int i = 0; i < vAmount; i++) {
		for (int j = 0; j < vAmount; j++) {
			printf("%i ", adjMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Graph::Graph(int vAmount) {
	this->vAmount = vAmount;
	adjMatrix = new int*[vAmount];
	for (int i = 0; i < vAmount; i++) {
		adjMatrix[i] = new int[vAmount];
		for (int j = 0; j < vAmount; j++) {
			adjMatrix[i][j] = 0;
		}
	}
}

void Graph::addVertex() {
	extendMatrix(1);
};

int Graph::addEdge(int startV, int endV, int weight) {
	if (startV > vAmount || endV > vAmount) return -1;
	adjMatrix[startV][endV] = weight;
};
void Graph::delVertex() {

};

int Graph::delEdge(int startV, int endV) {
	if (startV > vAmount || endV > vAmount) return -1;
	adjMatrix[startV][endV] = 0;
};

void Graph::editVertex() {
	
};
int Graph::editEdge(int startV, int endV, int newWeight) {
	if (startV > vAmount || endV > vAmount) return -1;
	adjMatrix[startV][endV] = newWeight;
};

int Graph::first(int v) {
	for (int i = 0; i < vAmount; i++) {
		if (adjMatrix[i] != 0) return i;
	}
	return -1;
};

int Graph::next(int v, int i) {
	unsigned int count = -1;
	bool meetedFirst = false;
	for (int j = 0; j < vAmount; j++) {
		if (adjMatrix[v][j] != 0) {
			count++;
			if (meetedFirst && count == i) return i;
			meetedFirst = true;
		}
	}
	return -1;
};

int Graph::vertex(int v, int i) {
	unsigned int count = -1;
	for (int j = 0; j < vAmount; j++) {
		if (adjMatrix[v][j] != 0) {
			count++;
			if (count == i) return i;
		}
	}
	return -1;
};