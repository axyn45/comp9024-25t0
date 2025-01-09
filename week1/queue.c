// Stack ADO implementation ... COMP9024 25T0

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
{ // set up empty stack
    queueObject.front = 0;
    queueObject.rear = -1;
}

int QueueIsEmpty()
{ // check whether stack is empty
    return (queueObject.rear == -1);
}

void QueueEnqueue(char v)
{ // insert int on front of queue
    assert((queueObject.rear - queueObject.front) % MAXITEMS < MAXITEMS-1);
    //    queueObject.front=(queueObject.front+1)%MAXITEMS;
    queueObject.rear = (queueObject.rear + 1) % MAXITEMS;

    int i = queueObject.rear;
    queueObject.item[i] = v;
}

char QueueDequeue()
{ // remove int from top of stack
    assert(queueObject.rear > -1);
    int i = queueObject.front;
    char v = queueObject.item[i];
    if (queueObject.front == queueObject.rear)
        queueObject.rear = -1;
    else
        queueObject.front = (queueObject.front + 1) % MAXITEMS;
    return v;
}