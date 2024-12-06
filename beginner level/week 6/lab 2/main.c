#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    printf("enter the length of the array : ");
    scanf("%d", &n);
    int *ptr;
    ptr = (int*)malloc(n*sizeof(int));
    printf("enter the elements of the array : \n");
    for(int i =0; i < n ; i++)
    {
        scanf("%d",&ptr[i]);
    }
    int max = ptr[0], min = ptr[0];
    for(int i =0; i < n ; i++)
    {
        if(ptr[i]>max)
            max = ptr[i];
        else if (ptr[i]<min)
            min = ptr[i];
    }
    printf("the maximum number is : %d \n",max);
    printf("the minimum number is : %d \n",min);
    return 0;
}
