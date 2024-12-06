#include "Global.h"
#define LIMITED_MEMORY
#ifndef Stack
#define Stack
typedef struct stack
{
    int top;
    int entry[max_stack];
}stack;
typedef struct StackNode
{
    StackEntry Entry;
    struct StackNode *Next;
}StackNode;
typedef struct Stack
{
    struct StackNode *Top;
    int Size;
}Stack;
#endif
