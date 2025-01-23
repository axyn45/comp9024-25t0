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

// bool cliqueExisted(int )

int main(){
    int numOfV=0;
    printf("Enter the number of vertices: ");
    scanf("%4d",&numOfV);
    Graph graph=newGraph(numOfV);
    char buffer[32];
    Edge newEdge;
    int *degreeTrack=(int*)malloc(sizeof(int)*numOfV);
    int cliques=0;


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
        degreeTrack[newEdge.v]++;
        degreeTrack[newEdge.w]++;
    }
    printf("Done.\n");
    // for(int i=0;i<numOfE;i++){

    // }

    for(int i=0;i<numOfV;i++){
        printf("Degree of node %d: %d\n",i,degreeTrack[i]);
    }
    // int **cqMtx=malloc(sizeof(int*)*1000);
    // for(int i=0;i<1000;i++){
    //     cqMtx[i]=malloc(sizeof(int)*3);
    // }
    for(int i=0;i<numOfV;i++){
        for(int j=0;j<numOfV;j++){
            if(i==j)
                continue;
            // if(j<i)
            //     break;
            for(int k=0;k<numOfV;k++){
                if(i==k||j==k)
                    continue;
                // if(k<j||k<i)
                //     break;
                if(adjacent(graph,i,j)&&adjacent(graph,j,k)&&adjacent(graph,i,k)){
                    cliques++;
                    if(cliques==1){
                        printf("3-cliques:\n");
                    }
                    if(k>j&&j>i)
                        printf("%d-%d-%d\n",i,j,k);
                }
                
            }
        }
    }
    
}