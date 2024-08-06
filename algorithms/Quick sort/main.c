#include <stdio.h>
#include <stdlib.h>
int Partition(int a[], int start, int end)
{
    int pivot = a[end];
    int part = start;
    for(int i = start ; i < end ; i++)
    {
        if(a[i] <= pivot)
        {
            int temp = a[i];
            a[i] = a[part];
            a[part] = temp;
            part++;
        }
    }
    int temp = a[part] ;
    a[part] = a[end];
    a[end] = temp;
    return part;
}
void QuickSort(int a[],int start,int end)
{
    if(start < end)
    {
        int part = Partition(a,start,end);
        QuickSort(a,start,part-1);
        QuickSort(a,part+1,end);
    }
}
int main()
{
    int A[] = {2,7,4,1,5,3};
    QuickSort(A,0,5);
    for(int i = 0; i < 6 ;i++)
        printf("%d ",A[i]);
    return 0;
}
