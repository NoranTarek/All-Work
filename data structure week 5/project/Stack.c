#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#ifdef LIMITED_MEMORY
void CreateStack (stack *ps)
{
    ps->top=0;
}
void push(StackEntry e, stack *ps)
{
    ps->entry[ps->top++]=e;
}
int StackFull(stack *ps)
{
    return ps->top == max_stack;
}
void pop(StackEntry *pe, stack *ps)
{
    *pe = ps->entry[--ps->top];
}
int StackEmpty(stack *ps)
{
    return !ps->top;
}
void StackTop(StackEntry *pe , stack *ps)
{
    *pe = ps->entry[ps->top-1];
}
int StackSize(stack *ps)
{
    return ps->top;
}
void ClearStack(stack *ps)
{
    ps->top=0;
}
void Display(StackEntry e)
{
    printf("e is : %d \n",e);
}
void TraverseStack(stack *ps ,void (*pf)(StackEntry))
{
    for(int i=ps->top;i > 0;i--)
    {
        (*pf)(ps->entry[i-1]);
    }
}

#else
void Create_Stack(Stack *ps)
{
    ps->Top=NULL;
    ps->Size=0;
}
void Push(StackEntry e,Stack *ps)
{
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    if(!pn)
    {
        return 0;
    }else
    {
        pn->Entry=e;
        pn->Next=ps->Top;
        ps->Top=pn;
        ps->Size++;
        return 1;
    }
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
#endif
