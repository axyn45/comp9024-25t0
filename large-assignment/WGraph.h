#include "List.h"

// Weighted Graph ADT interface ... COMP9024 25T0

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// typedef struct Vertex {
//     int data;
// } Vertex;

// edges are pairs of vertices (end-points) with a weight
typedef struct Edge {
    int v;
    int w;
    int weight;
} Edge;

Graph newGraph(int);
int numOfVertices(Graph);
void insertEdge(Graph, Edge);
void removeEdge(Graph, Edge);
int adjacent(Graph, int, int);  // returns weight, or 0 if not adjacent
void showGraph(Graph);
void freeGraph(Graph);
void insertVertex(Graph, int, Vertex);
int getVertexID(Graph, Vertex);
int getVertexData(Graph, int);
void insertAdjList(Graph, Edge);
int maxLenFrom(Graph, int);
void showListOfLen(Graph g, int id, int len, int targetLen, List ll);