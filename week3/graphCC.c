// Graph ADT
// Adjacency Matrix Representation ... COMP9024 25T0
#include "graphCC.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphRep {
    int **edges;  // adjacency matrix
    int nV;       // #vertices
    int nE;       // #edges
    int nC;       // # connected components
    int *cc;      /* which component each vertex is contained in
                     i.e. array [0..nV-1] of 0..nC-1 */
} GraphRep;

Graph newGraph(int V) {
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;
    g->nC = V;

    g->cc = malloc(sizeof(Vertex) * V);

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int *));
    assert(g->edges != NULL);
    // allocate memory for each column and initialise with 0
    for (i = 0; i < V; i++) {
        g->cc[i] = i;
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);
    }

    return g;
}

int numOfVertices(Graph g) { return g->nV; }

// check if vertex is valid in a graph
bool validV(Graph g, Vertex v) { return (g != NULL && v >= 0 && v < g->nV); }

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (!g->edges[e.v][e.w]) {  // edge e not in graph
        g->edges[e.v][e.w] = 1;
        g->edges[e.w][e.v] = 1;
        g->nE++;
    }
    if (g->cc[e.v] != g->cc[e.w]) {
        int greater = g->cc[e.v] > g->cc[e.w] ? g->cc[e.v] : g->cc[e.w];
        int lesser = g->cc[e.v] < g->cc[e.w] ? g->cc[e.v] : g->cc[e.w];
        int max = -1;
        for (int i = 0; i < g->nV; i++) {
            if (g->cc[i] == greater)
                g->cc[i] = lesser;
            else if (g->cc[i] > max)
                max = g->cc[i];
        }
        for (int i = 0; i < g->nV; i++) {
            if (g->cc[i] == max) g->cc[i] = greater;
        }
    }
}

void removeEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (g->edges[e.v][e.w]) {  // edge e in graph
        g->edges[e.v][e.w] = 0;
        g->edges[e.w][e.v] = 0;
        g->nE--;
    }

    int *visit = malloc(sizeof(int) * g->nV);
    for (int i = 0; i < g->nV; i++) {
        visit[i] = 0;
    }
    if (!dfs(g, e.v, e.w, visit)) {
        for (int i = 0; i < g->nV; i++) {
            visit[i] = 0;
        }
        int max = -1;
        for (int i = 0; i < g->nV; i++) {
            if (g->cc[i] > max) max = g->cc[i];
        }
        dfsNewComponent(g, e.w, max, visit);
    }
    free(visit);
}

bool adjacent(Graph g, Vertex v, Vertex w) {
    assert(g != NULL && validV(g, v) && validV(g, w));

    return (g->edges[v][w] != 0);
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
        for (j = i + 1; j < g->nV; j++)
            if (g->edges[i][j]) printf("Edge %d - %d\n", i, j);
}

void freeGraph(Graph g) {
    assert(g != NULL);

    int i;
    for (i = 0; i < g->nV; i++) free(g->edges[i]);
    free(g->edges);
    free(g);
}

bool dfs(Graph g, Vertex src, Vertex dest, int *visit) {
    visit[src] = 1;
    if (src == dest)
        return true;
    else {
        int w = -1;
        for (int i = 0; i < g->nE; i++) {
            if (g->edges[src][i] == 1) {
                w = i;
            } else
                continue;
            if (!visit[w])
                if (dfs(g, w, dest, visit)) {
                    return true;
                }
        }
    }
    return false;
}
void dfsNewComponent(Graph g, Vertex src, int newComp, int *visit) {
    visit[src] = 1;
    g->cc[src] = newComp;

    int w = -1;
    for (int i = 0; i < g->nE; i++) {
        if (g->edges[src][i] == 1) {
            w = i;
        } else
            continue;
        if (!visit[w]) dfsNewComponent(g, w, newComp, visit);
    }

    // return false;
}

void showComponents(Graph g) {
    printf("Connected components:\n");
    for (int i = 0; i < g->nV; i++) {
        printf("%d", g->cc[i]);
        if (i != g->nV - 1)
            printf(", ");
        else
            printf("\n");
    }
}