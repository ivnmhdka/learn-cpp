#include "graph.h"

void createVertex_103032300055(char newVertexID, Vertex* &v) {
    v = new Vertex;
    v->idVertex = newVertexID;
    v->nextVertex = nullptr;
    v->firstEdge = nullptr;
};

void initGraph_103032300055(Graph &G) {
    G.firstVertex = nullptr;
};

void addVertex_103032300055(Graph &G, char newVertexID) {
    Vertex* newVertex;
    createVertex_103032300055(newVertexID, newVertex);

    if (G.firstVertex == nullptr) {
        G.firstVertex = newVertex;
    } else {
        Vertex* temp = G.firstVertex;
        while (temp->nextVertex != nullptr) {
            temp = temp->nextVertex;
        }
        temp->nextVertex = newVertex;
    }
};

void buildGraph_103032300055(Graph &G) {
    initGraph_103032300055(G);

    char newVertexID;
    cout << "Masukkan ID vertex (A-Z), ketik karakter non-huruf untuk berhenti: ";
    while (cin >> newVertexID && isalpha(newVertexID)) {
        addVertex_103032300055(G, newVertexID);
        cout << "Vertex" << newVertexID << "berhasil ditambahkan. Masukkan ID berikutnya: ";
    }
    cout << "Pembuatan graph selesai.\n";
};

void printGraph_103032300055(const Graph &G) {
    Vertex* tempVertex = G.firstVertex;
    while (tempVertex != nullptr) {
        cout << "Vertex" << tempVertex->idVertex << ": ";
        Edge* tempEdge = tempVertex->firstEdge;
        while (tempEdge != nullptr) {
            cout << "->" << tempEdge->destVertexID << "(" << tempEdge->weight << ")";
            tempEdge= tempEdge->nextEdge;
        }
        cout << endl;
        tempVertex = tempVertex->nextVertex;
    }
};