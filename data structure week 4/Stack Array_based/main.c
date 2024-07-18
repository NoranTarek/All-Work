#include <stdio.h>
#include <stdlib.h>
typedef int StackEntry;
#define max_stack 100
typedef struct stack
{
    int top;
    int entry[max_stack];
}stack;
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

int main()
{
    stack s;
    CreateStack(&s);
    if(!StackFull)
    {
        push(5,&s);
    }
    if(!StackEmpty)
    {
        pop(5,&s);
    }
    return 0;
}
