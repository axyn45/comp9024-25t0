// Weighted Directed Graph ADT
// Adjacency Matrix Representation ... COMP9024 25T0
#include "WGraph.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

typedef struct GraphRep {
    int nV;  // #vertices
    int nE;  // #edges

    int **adjList;     // Store adjacency list for efficient trails searching.
                       // First element of each adjList
                       // indicates the length of the list.
    Vertex *vertices;  // Vertices data value (id=>value).
} GraphRep;

Graph newGraph(int V) {
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // Allocate memory for each column and initialise with 0.
    g->adjList = malloc(sizeof(int *) * V);
    for (i = 0; i < V; i++) {
        g->adjList[i] = calloc(V + 1, sizeof(int));
        assert(g->adjList[i]);
    }

    g->vertices = malloc(sizeof(Vertex) * V);
    assert(g->vertices);

    return g;
}

void freeGraph(Graph g) {
    assert(g != NULL);

    int i;
    for (i = 0; i < g->nV; i++) free(g->adjList[i]);
    free(g->adjList);
    free(g->vertices);

    free(g);
}

// Add vertex data to array.
void insertVertex(Graph g, int id, Vertex v) { g->vertices[id] = v; }

// Return id of vertex with value <v>.
int getVertexID(Graph g, Vertex v) {
    for (int i = 0; i < g->nV; i++) {
        if (g->vertices[i] == v) return v;
    }
    return -1;
}

// Return value of vertex with id <id>.
int getVertexData(Graph g, int id) {
    if (id >= g->nV) return -1;
    return g->vertices[id];
}

// Insert adjacency info into adjacency list.
void insertAdjList(Graph g, Edge e) {
    if (e.weight <= 0) return;
    g->adjList[e.v][g->adjList[e.v][0] + 1] = e.w;
    g->adjList[e.v][0]++;
}

// Return maximum trail length starting from vertex with id <id>.
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

// Display trails of length of <len> starting from vertex with id <id>.
void showListOfLen(Graph g, int id, int len, int targetLen, List ll) {
    // Terminate if <len+1> reaches <targetLen>.
    if (len + 1 == targetLen) {
        showTrail(appendLL(ll, g->vertices[id]));
        // Free last appended node.
        deleteLL(ll, g->vertices[id]);
        return;
    }

    // Terminate if no adjacent vertices found.
    if (g->adjList[id][0] == 0) {
        return;
    };

    for (int i = 0; i < g->adjList[id][0]; i++) {
        List new = appendLL(ll, g->vertices[id]);
        showListOfLen(g, g->adjList[id][i + 1], len + 1, targetLen, new);
        // Free last appended node.
        deleteLL(new, g->vertices[id]);
    }
}