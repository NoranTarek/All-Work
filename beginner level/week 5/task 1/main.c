#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    printf("before changing : x = %d \n",x);
    int *p;
    p = &x;
    *p = 20;
    printf("after changing : x = %d \n",x);
    return 0;
}
