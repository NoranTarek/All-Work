#include <stdio.h>
#include <stdlib.h>
int Merge(int a[],int l[],int nl,int r[],int nr)
{
    int i,j,k;
    i = j = k = 0;
    while(i < nl && j < nr)
    {
        if(l[i] < r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while(i < nl)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while(j < nr)
    {
        a[k] = r[j];
        j++;
        k++;
    }
    return a;
}
int MergeSort(int a[],int n)
{
    if(n < 2)
        return ;
    int mid = n / 2;
    int l[mid],r[n-mid],i;
    for(i = 0; i < mid; i++)
        l[i] = a[i];
    for(i = mid;i < n;i++)
        r[i-mid] = a[i];
    MergeSort(l , mid);
    MergeSort(r , n-mid);
    Merge(a , l , mid , r , (n-mid));
    return a;
}
int main()
{
    int A[] = {2,7,4,1,5,3};
    MergeSort(A,6);
    for(int i = 0; i < 6 ;i++)
        printf("%d ",A[i]);
    return 0;
}
