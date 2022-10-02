#include "graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int max, int null_edge) {
    NULL_EDGE = null_edge;
    maxVertices = max;
    numVertices = 0;
    vertices = new Vertex[maxVertices];
    marks = new bool[maxVertices];
    edges = new int* [maxVertices];

    // criar matriz de adjacências
    for(int row = 0; row < maxVertices; row++)
        edges[row] = new int [maxVertices];
    // populando matriz de adjacências com valor nulo
    for(int row = 0; row < maxVertices; row++)
        for(int col = 0; col < maxVertices; col++)
            edges[row][col] = NULL_EDGE;
}
Graph::~Graph() {
    delete [] vertices;
    delete [] marks;
    for (int row = 0; row < maxVertices; row++) {
        delete [] edges[row];
    }
    delete [] edges;
}
int Graph::getIndex(Vertex vertex) {
    int index = 0;
    while (!(vertex.getNome() == vertices[index].getNome())) {
        index++;
    }
    return index;
}
void Graph::addVertex(Vertex vertex) {
    vertices[numVertices] = vertex;
    numVertices++;
}
void Graph::addEdge(Vertex fromVertex, Vertex toVertex, int weight) {
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);

    edges[row][col] = weight;
    // remover se grafo direcionado.
    edges[col][row] = weight;
}
int Graph::getWeight(Vertex fromVertex, Vertex toVertex) {
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);
    return edges[row][col];
}
int Graph::getAdjacents(Vertex vertex, Queue &adjVertices) {
    int fromIndex;
    int toIndex;
    fromIndex = getIndex(vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.enqueue(vertices[toIndex]);
}
