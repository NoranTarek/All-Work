#include <stdio.h>
#include <stdlib.h>
int mul(int x[],int y[]);
int main()
{
    int a[3]={1,2,3};
    int b[3]={4,5,6};
    printf("the result = %d \n",mul(a,b));
    return 0;
}
int mul(int x[],int y[])
{
    int res;
    int *px=x,*py=y;
    for(int i;i<3;i++)
    {
        res += px[i] * py[i];
    }
    return res;
}
