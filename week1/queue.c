// Queue ADO implementation ... COMP9024 25T0

#include "queue.h"
#include <assert.h>

typedef struct
{
    int item[MAXITEMS];
    int front;
    int rear;
} queueRep; // defines the Data Structure

static queueRep queueObject; // defines the Data Object

void QueueInit()
{ // set up empty queue
    queueObject.front = -1;
    queueObject.rear = 0;
}

int QueueIsEmpty()
{ // check whether queue is empty
    return (queueObject.front == -1);
}

void QueueEnqueue(char v)
{ // Enqueue char in front of queue
    assert((queueObject.front - queueObject.rear) % MAXITEMS < MAXITEMS-1);
    // queueObject.front=(queueObject.front+1)%MAXITEMS;
    queueObject.front = (queueObject.front + 1) % MAXITEMS;

    int i = queueObject.front;
    queueObject.item[i] = v;
}

char QueueDequeue()
{ // remove char from front of queue
    assert(queueObject.front > -1);
    int i = queueObject.rear;
    char v = queueObject.item[i];
    if (queueObject.rear == queueObject.front)
        queueObject.front = -1;
    else
        queueObject.rear = (queueObject.rear + 1) % MAXITEMS;
    return v;
}