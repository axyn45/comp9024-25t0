#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "WGraph.h"

// #define MAXLEN 1000;

bool isValidInt(char a[]) {
    for (int i = 0; i < 32 && a[i] != 0; i++) {
        if ((a[i] < 48 || a[i] > 57) && a[i] != '-' && a[i] != ' ')
            return false;
    }
    return true;
}

void inssort(int **arr, int start, int size) {
    int *temp;

    int max;
    // int key = 1;
    for (int i = start; i < size; i++) {
        max = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j][1] > arr[max][1]) {
                max = j;
            } else if (arr[j][1] == arr[max][1] && arr[j][2] > arr[max][2]) {
                max = j;
            } else if (arr[j][1] == arr[max][1] && arr[j][2] == arr[max][2] &&
                       arr[j][0] < arr[max][0]) {
                max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main() {
    char buffer[32];
    int webNum = 0;
    printf("Enter the number of webpages: ");
    scanf("%4d", &webNum);
    Graph g = newGraph(webNum);
    Edge newEdge;
    newEdge.weight = 1;
    int *outScore = (int *)malloc(sizeof(int) * webNum);
    int *inScore = (int *)malloc(sizeof(int) * webNum);
    for (int i = 0; i < webNum; i++) {
        outScore[i] = 0;
        inScore[i] = 0;
    }

    while (true) {
        printf("Enter a webpage: ");
        scanf("%31s", buffer);
        if (!isValidInt(buffer)) break;
        newEdge.v = atoi(buffer);
        printf("Enter a link on webpage %d: ", newEdge.v);
        scanf("%31s", buffer);
        if (!isValidInt(buffer)) break;
        newEdge.w = atoi(buffer);
        // printf("---- %d %d\n", newEdge.v, newEdge.w);

        insertEdge(g, newEdge);
        outScore[newEdge.v]++;
        inScore[newEdge.w]++;
        // degreeTrack[newEdge.v]++;
        // degreeTrack[newEdge.w]++;
    }
    printf("Done.\n\n");

    int **ranking = malloc(sizeof(int *) * webNum);
    for (int i = 0; i < webNum; i++) {
        ranking[i] = malloc(sizeof(int) * 3);
        ranking[i][0] = i;
        ranking[i][1] = inScore[i];
        ranking[i][2] = 0;
        for (int j = 0; j < webNum; j++) {
            if (adjacent(g, j, i)) {
                ranking[i][2] += outScore[j];
            }
        }
    }
    inssort(ranking, 0, webNum);
    // inssort(ranking, 0, webNum, 1);

    printf("Webpage ranking:\n");
    for (int i = 0; i < webNum; i++) {
        printf("%d has %d inbound links and scores %d on inbound links.\n",
               ranking[i][0], ranking[i][1], ranking[i][2]);
    }
}
