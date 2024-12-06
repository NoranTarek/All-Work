#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("enter the first number : \n");
    scanf("%d",&x);
    printf("enter the second number : \n");
    scanf("%d",&y);
    printf("x + y = %d \n",x+y);
    printf("x - y = %d \n",x-y);
    printf("x * y = %d \n",x*y);
    printf("x / y = %d \n",x/y);
    printf("x \% y = %d \n",x%y);
    printf("x && y = %d \n",x&&y);
    printf("x || y = %d \n",x||y);
    printf("x ^ y = %d \n",x^y);
    printf("!x = %d \n",!x);
    printf("!y = %d \n",!y);
    printf("x & y = %d \n",x&y);
    printf("x | y = %d \n",x|y);
    printf("x << y = %d \n",x<<y);
    printf("x >> y = %d \n",x>>y);
    return 0;
}
