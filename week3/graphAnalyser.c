#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Graph.h"

bool isValidInt(char a[])
{
    for (int i = 0; i < 32 && a[i] != 0; i++)
    {
        if ((a[i] < 48 || a[i] > 57) && a[i] != '-' && a[i] != ' ')
            return false;
    }
    return true;
}

int main(){
    int numOfV=0;
    printf("Enter the number of vertices: ");
    scanf("%4d",&numOfV);
    Graph graph=newGraph(numOfV);
    char buffer[32];
    Edge newEdge;
    while(true){
        printf("Enter an edge (from): ");
        scanf("%31s",buffer);
        if(!isValidInt(buffer))
            break;
        newEdge.v=atoi(buffer);
        printf("Enter an edge (to): ");
        scanf("%31s",buffer);
        if(!isValidInt(buffer))
            break;
        newEdge.w=atoi(buffer);

        insertEdge(graph,newEdge);
    }
    printf("Done.\n");
    
}