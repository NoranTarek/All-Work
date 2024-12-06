#include <stdio.h>
#include <stdlib.h>
typedef int StackEntry;

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
void Create_Stack(Stack *ps)
{
    ps->Top=NULL;
    ps->Size=0;
}
void Push(StackEntry e,Stack *ps)
{
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->Entry=e;
    pn->Next=ps->Top;
    ps->Top=pn;
    ps->Size++;
}
void Pop(StackEntry *pe,Stack *ps)
{
    StackNode *pn;
    *pe=ps->Top->Entry;
    pn=ps->Top;
    ps->Top=ps->Top->Next;
    free(pn);
    ps->Size--;
}
int StackEmpty(Stack *ps)
{
    return ps->Top==NULL;
}
int stackFull(Stack *ps)
{
    return 0;
}
void ClearStack(Stack *ps)
{
    StackNode *pn=ps->Top;
    while(pn)
    {
        pn=pn->Next;
        free(ps->Top);
        ps->Top=pn;
    }
    ps->Size=0;
}
void TraverseStack(Stack *ps,void(*pf)(StackEntry))
{
    StackNode *pn=ps->Top;
    while(pn)
    {
        (*pf)(pn->Entry);
        pn=pn->Next;
    }
}
int StackSize(Stack *ps)
{
    return ps->Size;
}
int main()
{
    Stack s;
    StackEntry e;
    Create_Stack(&s);
    Push(7,&s);
    Pop(e,&s);
    return 0;
}
