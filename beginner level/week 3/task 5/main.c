#include <stdio.h>
#include <stdlib.h>
int fib(int,int,int);
int main()
{
    printf("enter the number : \n");
    int z;
    scanf("%d", &z);
    int x = 0 , y = 1;
    fib(x,y,z);
    return 0;
}
int fib (int a,int b, int c)
{
    int res;
    for (int i = 1;i<=c;i++)
    {
        printf("%d ",a);
        res = a+ b;
        a=b;
        b=res;
    }
}
