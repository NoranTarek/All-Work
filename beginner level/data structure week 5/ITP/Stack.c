#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void CreateStack (Stack *ps)
{
    ps->top=0;
}
void push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top++]=e;
}
int StackFull(Stack *ps)
{
    return ps->top == max_stack;
}
void pop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[--ps->top];
}
int StackEmpty(Stack *ps)
{
    return !ps->top;
}
void StackTop(StackEntry *pe , Stack *ps)
{
    *pe = ps->entry[ps->top-1];
}
int StackSize(Stack *ps)
{
    return ps->top;
}
void ClearStack(Stack *ps)
{
    ps->top=0;
}
void Display(StackEntry e)
{
    printf("e is : %d \n",e);
}
void TraverseStack(Stack *ps ,void (*pf)(StackEntry))
{
    for(int i=ps->top;i > 0;i--)
    {
        (*pf)(ps->entry[i-1]);
    }
}
