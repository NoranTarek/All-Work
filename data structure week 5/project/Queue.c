#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#ifdef LIMITED_MEMORY_
void CreateQueue(queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void Append(QueueEntry e,queue* pq)
{
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}
void Serve(QueueEntry *pe,queue *pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}
int QueueEmpty(queue* pq)
{
    return !pq->size;
}
int QueueFull(queue* pq)
{
    return (pq->size == MAXQUEUE);
}
int QueueSize(queue* pq)
{
    return pq->size;
}
void ClearQueue(queue* pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void display(QueueEntry e)
{
    printf("e is : %d \n",e);
}
void TraverseQueue(queue* pq,void (*pf)(QueueEntry))
{
    int pos, s;
    for(pos=pq->front,s=0; s<pq->size ;s++)
    {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MAXQUEUE;
    }
}
#else
void CreateQueue(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}
void Append(QueueEntry e,Queue* pq)
{
    QueueNode* pn=(QueueNode*)malloc(sizeof(QueueNode));
    if(!pn)
    {
        return 0;
    }else
    {
        pn->next=NULL;
        pn->entry=e;
        if(!pq->rear)
            pq->front=pn;
        else
            pq->rear->next=pn;
        pq->rear=pn;
        pq->size++;
        return 1
    }
}
void Serve(QueueEntry *pe,Queue* pq)
{
    QueueNode *pn=pq->front;
    *pe=pn->entry;
    pq->front=pn->next;
    free(pn);
    if(!pq->front)
        pq->rear=NULL;
    pq->size--;
}
int QueueEmpty(Queue* pq)
{
    return !pq->size;
}
int QueueFull(Queue* pq)
{
    return (pq->size == MAXQUEUE);
}
int QueueSize(Queue* pq)
{
    return pq->size;
}
void ClearQueue(Queue* pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void display(QueueEntry e)
{
    printf("e is : %d \n",e);
}
void TraverseQueue(Queue* pq,void (*pf)(QueueEntry))
{
    for(QueueNode *pn=pq->front; pn ;pn=pn->next)
        (*pf)(pn->entry);
}
#endif // LIMITED_MEMORY_
