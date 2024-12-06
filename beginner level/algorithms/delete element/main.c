#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter the size of the  array : ");
    int n; scanf("%d", &n);
    printf("enter the elements of the  array : \n");
    int a[n];
    for(int i = 0; i<n ;i++)
        scanf("%d", &a[i]);
    printf("input position to delete : \n");
    int m;scanf("%d", &m);
    if(m > n)
        printf("invalid position !");
    else
    {
        for(int i = m-1; i < n-1 ; i++)
            a[i] = a[i+1];

        for(int i = 0; i<n-1 ;i++)
            printf("%d ",a[i]);
    }
    return 0;
}
