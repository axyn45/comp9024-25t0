// Weighted Directed Graph ADT
// Adjacency Matrix Representation ... COMP9024 25T0
#include "WGraph.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

typedef struct GraphRep {
    int **edges;  // adjacency matrix storing positive weights
                  // 0 if nodes not adjacent
    int nV;       // #vertices
    int nE;       // #edges

    int **adjList;     // store adjacency list for efficient trails searching
    Vertex *vertices;  // vertices data value (id=>value)
} GraphRep;

Graph newGraph(int V) {
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int *));
    assert(g->edges != NULL);
    // allocate memory for each column and initialise with 0
    g->adjList = malloc(sizeof(int *) * V);
    for (i = 0; i < V; i++) {
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);

        // first element of each adjList
        // indicates the length of the list
        g->adjList[i] = calloc(V + 1, sizeof(int));
        assert(g->adjList[i]);
    }

    g->vertices = malloc(sizeof(Vertex) * V);
    assert(g->vertices);

    return g;
}

int numOfVertices(Graph g) { return g->nV; }

// check if vertex is valid in a graph
int validV(Graph g, int v) { return (g != NULL && v >= 0 && v < g->nV); }

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (g->edges[e.v][e.w] == 0) {  // edge e not in graph
        g->edges[e.v][e.w] = e.weight;
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (g->edges[e.v][e.w] != 0) {  // edge e in graph
        g->edges[e.v][e.w] = 0;
        g->nE--;
    }
}

int adjacent(Graph g, int v, int w) {
    assert(g != NULL && validV(g, v) && validV(g, w));

    return g->edges[v][w];
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
        for (j = 0; j < g->nV; j++)
            if (g->edges[i][j] != 0)
                printf("Edge %d(%d) - %d(%d)\n", i, g->vertices[i], j,
                       g->vertices[j]);
}

void freeGraph(Graph g) {
    assert(g != NULL);

    int i;
    for (i = 0; i < g->nV; i++) free(g->edges[i]);
    free(g->edges);
    free(g->vertices);

    free(g);
}

// add vertex data to array
void insertVertex(Graph g, int id, Vertex v) { g->vertices[id] = v; }

// return id of vertex with value <v>
int getVertexID(Graph g, Vertex v) {
    for (int i = 0; i < g->nV; i++) {
        if (g->vertices[i] == v) return v;
    }
    return -1;
}

// return value of vertex with id <id>
int getVertexData(Graph g, int id) {
    if (id >= g->nV) return -1;
    return g->vertices[id];
}

// insert adjacency info into adjacency list
void insertAdjList(Graph g, Edge e) {
    if (e.weight <= 0) return;
    g->adjList[e.v][g->adjList[e.v][0] + 1] = e.w;
    g->adjList[e.v][0]++;
}

// return maximum trail length starting from vertex with id <id>
int maxLenFrom(Graph g, int id) {
    if (g->adjList[id][0] == 0) return 1;
    int maxLen = 1, t = 0;
    for (int i = 0; i < g->adjList[id][0]; i++) {
        t = maxLenFrom(g, g->adjList[id][i + 1]);
        if (maxLen < 1 + t) {
            maxLen = 1 + t;
        }
    }
    return maxLen;
}

// display trails of length of <len> starting from vertex with id <id>
void showListOfLen(Graph g, int id, int len, int targetLen, List ll) {
    // terminate if <len+1> reaches <targetLen>
    if (len + 1 == targetLen) {
        showTrail(appendLL(ll, g->vertices[id]));
        // free last appended node
        deleteLL(ll, g->vertices[id]);
        return;
    }

    // terminate if no adjacent vertices found
    if (g->adjList[id][0] == 0) {
        return;
    };

    for (int i = 0; i < g->adjList[id][0]; i++) {
        List new = appendLL(ll, g->vertices[id]);
        showListOfLen(g, g->adjList[id][i + 1], len + 1, targetLen, new);
        // free last appended node
        deleteLL(new, g->vertices[id]);
    }
}