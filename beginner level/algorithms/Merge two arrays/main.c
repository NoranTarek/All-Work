#include <stdio.h>
#include <stdlib.h>
void MergeSort(int a[],int n, int b[],int m)
{
    int Arr[n+m];
    int i = 0,j = 0, k = 0;
    while(i < n && j < m)
    {
        if(a[i] <= b[j])
        {
            Arr[k] = a[i];
            i++;
        }
        else
        {
            Arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < n)
    {
        Arr[k] = a[i];
        i++;
        k++;
    }
    while(j < m)
    {
        Arr[k] = b[j];
        j++;
        k++;
    }
    for(int l = 0;l < k ; l++)
        printf("%d  ",Arr[l]);
}
int main()
{
    printf("enter the size of the first array : ");
    int n; scanf("%d", &n);
    printf("enter the elements of the first array : \n");
    int a[n];
    for(int i = 0; i<n ;i++)
        scanf("%d", &a[i]);
    printf("enter the size of the second array : ");
    int m; scanf("%d", &m);
    printf("enter the elements of the second array : \n");
    int b[m];
    for(int i = 0; i<m ;i++)
        scanf("%d", &b[i]);
    MergeSort(a , n , b , m);
    return 0;
}
