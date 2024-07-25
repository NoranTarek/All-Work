#ifndef stack_h
#define stack_h
typedef int StackEntry;
#define max_stack 100
typedef struct stack_
{
    int top;
    int entry[max_stack];
}Stack;
void CreateStack (Stack *ps);
void push(StackEntry e, Stack *ps);
int StackFull(Stack *ps);
void pop(StackEntry *pe, Stack *ps);
int StackEmpty(Stack *ps);
void StackTop(StackEntry *pe , Stack *ps);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void Display(StackEntry e);
void TraverseStack(Stack *ps ,void (*pf)(StackEntry));
#endif
