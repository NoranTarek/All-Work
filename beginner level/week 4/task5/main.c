#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[5][5]={0},sumr=0,sumc=0;
    printf("enter the elements of 5*5 array : \n");
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            scanf("%d", &x[i][j]);
        }
    }
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            sumr+=x[i][j];
        }
        printf("sum of row %d = %d \n",i ,sumr);
        sumr = 0;
    }
    for(int j = 0;j < 5;j++)
    {
        for(int i = 0;i < 5;i++)
        {
            sumc+=x[i][j];
        }
        printf("sum of column %d = %d \n",j ,sumc);
        sumc = 0;
    }
    return 0;
}
