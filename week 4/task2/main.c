#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5]={0};
    printf("enter the element of the array : \n");
    for(int i = 0 ; i < 5 ; i++)
    {
        scanf("%d", &a[i]);
    }
    int max = a[0];
    for(int i = 1 ; i < 5 ; i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    int max2= a[0];
    for(int i = 1 ; i < 5 ; i++)
    {
        if(a[i]<max&&a[i]>max2)
            max2 = a[i];
    }
    printf("second maximum number is : %d",max2);
    return 0;
}
