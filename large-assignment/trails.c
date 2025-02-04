#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #include "List.h"
#include "WGraph.h"

int numOfDigits(int a) {
    if (a < 0) return 0;
    int n = 0, t = a;
    while (t != 0) {
        t /= 10;
        n++;
    }
    return n;
}

bool isValidSuccessor(int a, int b) {
    if (a >= b) return false;

    int la = numOfDigits(a), lb = numOfDigits(b);
    // if (a == 5314) printf("\n- %d %d", la, lb);

    if (lb - la <= 1) {
        bool flag = false;
        int ta = a, tb = b, ma, mb;
        while (ta != 0) {
            ma = ta % 10;
            mb = tb % 10;
            if (ma != mb) {
                if (!flag) {
                    flag = true;
                    if (la + 1 == lb) {
                        tb /= 10;
                        mb = tb % 10;
                        if (ma != mb) return false;
                    }
                } else
                    return false;
            }
            ta /= 10;
            tb /= 10;
        }
    } else
        return false;

    return true;
}

int main() {
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    for (int i = 0; i < n; i++) {
        Vertex new = 0;
        printf("Enter a number: ");
        scanf("%d", &new);
        insertVertex(g, i, new);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        Vertex va = getVertexData(g, i);
        printf("%d:", va);
        for (int j = 0; j < n; j++) {
            Vertex vb = getVertexData(g, j);
            if (isValidSuccessor(va, vb)) {
                Edge new;
                new.v = i;
                new.w = j;
                new.weight = 1;
                insertEdge(g, new);
                insertAdjList(g, new);
                printf(" %d", vb);
            }
        }
        printf("\n");
    }
    printf("\n");

    // showGraph(g);

    // int maxLen = 0, maxStart;
    int *maxLenRecords = calloc(n, sizeof(int));
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLenRecords[i] = maxLenFrom(g, i);
        if (maxLenRecords[i] > maxLen) maxLen = maxLenRecords[i];
    }
    printf("Maximum trail length: %d\n", maxLen);
    printf("Longest trail(s):\n");

    for (int i = 0; i < n; i++) {
        if (maxLenRecords[i] == maxLen) showListOfLen(g, i, 0, maxLen, NULL);
    }

    freeGraph(g);
}