#include <stdio.h>
#include <stdlib.h>

typedef int QueueEntry;
typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;
typedef struct queue
{
  QueueNode *front;
  QueueNode *rear;
  int size;
}Queue;
void CreateQueue(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}
void Append(QueueEntry e,Queue* pq)
{
    QueueNode* pn=(QueueNode*)malloc(sizeof(QueueNode));
    pn->next=NULL;
    pn->entry=e;
    if(!pq->rear)
        pq->front=pn;
    else
        pq->rear->next=pn;
    pq->rear=pn;
    pq->size++;
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
    return !pq->front;//or !pq->rear or !pq->size
}
int QueueFull(Queue* pq)
{
    return 0;
}
int QueueSize(Queue* pq)
{
    return pq->size;
}
void ClearQueue(Queue* pq)
{
    while(pq->front)
    {
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}
void Display(QueueEntry e)
{
    printf("e is : %d \n",e);
}
void TraverseQueue(Queue* pq,void (*pf)(QueueEntry))
{
    for(QueueNode *pn=pq->front; pn ;pn=pn->next)
        (*pf)(pn->entry);
}
int main()
{
    Queue q;
    QueueEntry e;
    CreateQueue(&q);
    Append(8,&q);
    Serve(e,&q);
    return 0;
}
