#include <stdio.h>
#include <stdlib.h>
int MM (int X[],int n);
int main()
{
    int n;
    printf("enter the size of the array : ");
    scanf("%d", &n);
    printf("enter the numbers of the array : \n");
    int x[n];
    for(int i = 0 ; i <n ; i++)
    {
        scanf("%d", &x[i]);
    }
    int* ptr;
    ptr = MM(x,n);
    printf("the maximum number is : %d \n", *ptr);
    ptr++;
    printf("the minimum number is : %d", *ptr);
    return 0;
}
int MM(int X[],int n)
{
    int x[2]={X[0],X[0]};
   for(int i = 1 ; i < n; i++)
    {
        if(X[i] > x[0])
            x[0] = X[i];
        if(X[i] < x[1])
            x[1] = X[i];
    }
    int* ptr;
    ptr = x;
    return (ptr);
}
