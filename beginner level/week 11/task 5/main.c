#include <stdio.h>
#include <stdlib.h>
void MM (int X[]);
int main()
{
    printf("enter four numbers : \n");
    int x[4]={0};
    for(int i = 0 ; i <4 ; i++)
    {
        scanf("%d", &x[i]);
    }
    MM(x);
    return 0;
}
void MM (int X[])
{
    int max = X[0], min = X[0];
   for(int i = 1 ; i <4 ; i++)
    {
        if(X[i] > max)
            max = X[i];
        if(X[i] < min)
            min = X[i];
    }
    printf("maximum number is : %d \n",max);
    printf("minimum number is : %d \n",min);
}
