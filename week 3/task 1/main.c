#include <stdio.h>
#include <stdlib.h>
int Get_Max(int , int);
int main()
{
    int x, y;
    printf("Enter the first number :");
    scanf("%d", &x);
    printf("Enter the second number :");
    scanf("%d", &y);
    printf("The maximum number is : %d",Get_Max(x,y));
    return 0;
}
int Get_Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
