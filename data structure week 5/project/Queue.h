#include "Global.h"
#define LIMITED_MEMORY_
#ifndef Queue
#define Queue
typedef struct queue
{
int front;
int rear;
int size;
QueueEntry entry[MAXQUEUE];
}queue;
typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;
typedef struct Queue
{
  QueueNode *front;
  QueueNode *rear;
  int size;
}Queue;
#endif // Queue
