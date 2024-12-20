#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

struct Edge {
    char destVertexID;
    int weight;
    Edge* nextEdge;
};

struct Vertex {
    char idVertex;
    Vertex* nextVertex;
    Edge* firstEdge;
};

struct Graph {
    Vertex* firstVertex;
};

void createVertex_103032300055(char newVertexID, Vertex* &v);
void initGraph_103032300055(Graph &G);
void addVertex_103032300055(Graph &G, char newVertexID);
void buildGraph_103032300055(Graph &G);
void printGraph_103032300055(const Graph &G);

#endif
