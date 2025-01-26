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

#include <stdio.h>

#define SIZE 6

void inssort(int **arr, int size, int key) {
    int *temp;
    // int i;
    // int
    // int *init = malloc(sizeof(int) * 3);
    // init[0] = 0;
    // init[1] = 0;
    // init[2] = 0;
    int max = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[j][key] > arr[max][key]) {
                max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }

    // for (int i = 1; i < SIZE; i++) {
    //     int element = arr[i][key];  // for this element ...
    //     int j = i - 1;
    //     while (j >= 0 &&
    //            arr[j][key] > element) {  // ... work down the ordered list
    //         // numbers[j + 1] = numbers[j];  // ... moving elements up

    //         j--;
    //     }
    //     numbers[j + 1] = element;  // and insert in correct position
    // }

    // for (i = 0; i < SIZE; i++) printf("%d\n", numbers[i]);
    // // free(init);
    // return 0;
}

// bool cliqueExisted(int )

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

    // int cliques = 0;

    while (true) {
        printf("Enter a webpage: ");
        scanf("%31s", buffer);
        if (!isValidInt(buffer)) break;
        newEdge.v = atoi(buffer);
        printf("Enter a link on webpage %d: ", newEdge.v);
        scanf("%31s", buffer);
        if (!isValidInt(buffer)) break;
        newEdge.w = atoi(buffer);

        insertEdge(g, newEdge);
        outScore[newEdge.v]++;
        inScore[newEdge.w]++;
        // degreeTrack[newEdge.v]++;
        // degreeTrack[newEdge.w]++;
    }
    printf("Done.\n");

    int **ranking = malloc(sizeof(int *) * webNum);
    for (int i = 0; i < webNum; i++) {
        ranking[i] = malloc(sizeof(int) * 3);
        ranking[i][0] = i;
        ranking[i][1] = inScore[i];
        ranking[i][1] = 0;
        for (int j = 0; j < webNum; j++) {
            if (adjacent(g, j, i)) {
                ranking[i][1] += outScore[j];
            }
        }
    }
    inssort(ranking, webNum, 1);

    printf("Webpage ranking:\n");
    for (int i = 0; i < webNum; i++) {
        printf("%d has %d inbound links and scores %d on inbound links.\n",
               ranking[0], ranking[1], ranking[2]);
    }
    // for(int i=0;i<numOfE;i++){

    // }

    // for (int i = 0; i < numOfV; i++) {
    //     printf("Degree of node %d: %d\n", i, degreeTrack[i]);
    // }
    // // int **cqMtx=malloc(sizeof(int*)*1000);
    // // for(int i=0;i<1000;i++){
    // //     cqMtx[i]=malloc(sizeof(int)*3);
    // // }
    // for (int i = 0; i < numOfV; i++) {
    //     for (int j = 0; j < numOfV; j++) {
    //         if (i == j) continue;
    //         // if(j<i)
    //         //     break;
    //         for (int k = 0; k < numOfV; k++) {
    //             if (i == k || j == k) continue;
    //             // if(k<j||k<i)
    //             //     break;
    //             if (adjacent(graph, i, j) && adjacent(graph, j, k) &&
    //                 adjacent(graph, i, k)) {
    //                 cliques++;
    //                 if (cliques == 1) {
    //                     printf("3-cliques:\n");
    //                 }
    //                 if (k > j && j > i) printf("%d-%d-%d\n", i, j, k);
    //             }
    //         }
    //     }
    // }
}
