// Priority Queue ADO header ... COMP9024 25T0

#include <stdbool.h>

#include "WGraph.h"

#define MAX_NODES 1000

void PQueueInit();
void joinPQueue(Vertex);
Vertex leavePQueue(int[]);
bool PQueueIsEmpty();