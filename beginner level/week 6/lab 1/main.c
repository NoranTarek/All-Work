#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    printf("enter the number of subjects : ");
    scanf("%d",&n);
    int *ptr;
    ptr=(int*)malloc(n*sizeof(int));
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        printf("the marks of subject %d is : %d \n",i+1 ,ptr[i]);
    }
    printf("enter another number of subjects : ");
    scanf("%d",&n);
    ptr=(int*)realloc(ptr,n*sizeof(int));
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        printf("the marks of subject %d is : %d \n",i+1 ,ptr[i]);
    }
    return 0;
}
