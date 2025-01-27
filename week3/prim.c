#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"
#include "WGraph.h"

// #define MAXLEN 1000;

bool isValidInt(char a[]) {
    for (int i = 0; i < 32 && a[i] != 0; i++) {
        if ((a[i] < 48 || a[i] > 57) && a[i] != '-' && a[i] != ' ')
            return false;
    }
    return true;
}

int main() {
    char buffer[32];
    int V = 0;
    printf("Enter the number of vertices: ");
    scanf("%4d", &V);
    Graph g = newGraph(V);
    Edge newEdge;
    // int countE = 0;

    while (true) {
        printf("Enter an edge (from): ");
        scanf("%31s", buffer);
        if (!isValidInt(buffer)) break;
        newEdge.v = atoi(buffer);
        printf("Enter an edge (to): ");
        scanf("%31s", buffer);
        if (!isValidInt(buffer)) break;
        newEdge.w = atoi(buffer);
        printf("Enter the weight: ");
        scanf("%31s", buffer);
        if (!isValidInt(buffer)) break;
        newEdge.weight = atoi(buffer);
        // printf("---- %d %d\n", newEdge.v, newEdge.w);

        insertEdge(g, newEdge);
        // countE++;
    }
    printf("Done.\n\n");

    Graph mst = newGraph(V);
    Set usedV = newSet();
    // addToSet(usedV, 0);

    printf("Enter the starting vertex: ");
    scanf("%31s", buffer);
    assert(isValidInt(buffer));
    addToSet(usedV, atoi(buffer));

    int **unusedE = malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        unusedE[i] = calloc(V, sizeof(int));
        assert(unusedE[i] != NULL);
        for (int j = 0; j < V; j++) {
            unusedE[i][j] = adjacent(g, i, j);
        }
    }
    Edge minE;

    while (sizeSet(usedV) < V) {
        minE.v = 0;
        minE.w = 0;
        minE.weight = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (elementOfSet(usedV, i))
                for (int j = 0; j < V; j++) {
                    if (!elementOfSet(usedV, j)) {
                        int temp = adjacent(g, i, j);
                        if (temp < minE.weight && temp > 0) {
                            minE.v = i;
                            minE.w = j;
                            minE.weight = temp;
                        }
                    }
                }
        }
        insertEdge(mst, minE);
        addToSet(usedV, minE.w);
        unusedE[minE.v][minE.w] = 0;
        printf("Edge with weight %d added.\n", minE.weight);
    }
    printf("\n");
    // printf("Number of vertices: %d\n", V);
    // printf("Number of edges: %d\n", V - 1);
    // for () {
    // }
    showGraph(mst);

    for (int i = 0; i < V; i++) {
        free(unusedE[i]);
    }
    free(unusedE);
    freeSet(usedV);
    freeGraph(g);
    freeGraph(mst);
}
