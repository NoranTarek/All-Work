#include <stdio.h>
#include <stdlib.h>
int sum (int *px,int *py);
int main()
{
    printf("enter two numbers : \n");
    int x,y;
    scanf("%d %d",&x ,&y);
    printf("sum = %d",sum(&x,&y));
    return 0;
}
int sum (int *px,int *py)
{
    return *px+*py;
}
