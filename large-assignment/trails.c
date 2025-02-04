/*------------------------------------------------------------------------
Complexity Analysis
    Total worst-case complexity: O(n² log a)
    |   Task 1: O(n² log a)
    |   |   Graph Initialization: O(n)
    |   |   Vertices Insertion: O(n)
    |   |   Nested loop over all pairs (i, j) O(n²) times: O(n² log a)
    |   |   |   isValidSuccessor: O(log a)
    |   |   |   |   numOfDigits: O(log a)
    |   |   |   |   |   *Each iteration reduces a by a factor of 10.
    |   |   |   |   Iterates through the digits of a and b: O(log a)
    |   Task 2: O(n²)
    |   |   maxLenFrom: O(n²)
    |   |   |   *O(n) for each call, and it's called for all n vertices.
    |   |   showListOfLen: O(n²)
    |   |   |   *O(n) for each call, and it's called for all n vertices.

------------------------------------------------------------------------*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "WGraph.h"

// Return number of digits of <a>.
int numOfDigits(int a) {
    if (a < 0) return 0;
    int n = 0, t = a;
    while (t != 0) {
        t /= 10;
        n++;
    }
    return n;
}

// Return true if <b> is a valid successor of <a>, vice versa.
bool isValidSuccessor(int a, int b) {
    if (a >= b) return false;

    int la = numOfDigits(a), lb = numOfDigits(b);
    if (lb - la <= 1) {
        bool flag = false;
        int ta = a, tb = b, ma, mb;
        while (ta != 0) {
            ma = ta % 10;
            mb = tb % 10;
            if (ma != mb) {
                if (!flag) {
                    flag = true;
                    // If <b> is longer than <a>,
                    // move to next digit of <b> and compare again.
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

    // Build up adjacency lists.
    for (int i = 0; i < n; i++) {
        Vertex va = getVertexData(g, i);
        printf("%d:", va);
        for (int j = 0; j < n; j++) {
            Vertex vb = getVertexData(g, j);

            if (isValidSuccessor(va, vb)) {
                // Edge exist from vertex <i> to <j>.
                Edge new;
                new.v = i;
                new.w = j;
                new.weight = 1;
                insertAdjList(g, new);
                printf(" %d", vb);
            }
        }
        printf("\n");
    }
    printf("\n");

    // Array storing maximum trail lengths starting from each vertex.
    int *maxLenRecords = calloc(n, sizeof(int));
    // Maximum trail length.
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        maxLenRecords[i] = maxLenFrom(g, i);
        if (maxLenRecords[i] > maxLen) maxLen = maxLenRecords[i];
    }

    printf("Maximum trail length: %d\n", maxLen);
    printf("Longest trail(s):\n");
    for (int i = 0; i < n; i++) {
        // Display all trails with length of <maxLen>.
        if (maxLenRecords[i] == maxLen) showListOfLen(g, i, 0, maxLen, NULL);
    }

    freeGraph(g);
}

/* debug command
gcc -Wall -Werror -std=c11 -c List.c;
gcc -Wall -Werror -std=c11 -c WGraph.c;
gcc -Wall -Werror -std=c11 -c trails.c;
gcc -Wall -Werror -std=c11 -o trails trails.o WGraph.o List.o;
./trails
*/