#include <stdio.h>
#include <stdlib.h>
int sort(int x[]);
int main()
{
    int a[5]={5,7,3,9,1};
    sort(a);
    for(int n = 0; n<5;n++)
    {
        printf("A[%d] = %d ",n+1 ,a[n]);
    }
    return 0;
}
int sort(int x[])
{
    int *p;
    p=x;
    for(int n=0;n<5;n++)
    {
        for(int i = n; i<5; i++)
        {
          if(p[n]>p[i])
        {
            int temp = p[n];
            p[n]=p[i];
            p[i]=temp;
        }
        }
    }
}
