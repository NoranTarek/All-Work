#include <stdio.h>
#include <stdlib.h>
int a = 10, b=20;
int swap(int , int);
int main()
{
    printf("numbers before swap : %d %d \n",a ,b);
    swap(a,b);
    return 0;
}
int swap(int x,int y)
{
    int z = x;
    x = y;
    y = z;
    printf("numbers after swap : %d %d\n",x ,y);
}
