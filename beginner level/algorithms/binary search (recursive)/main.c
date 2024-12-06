#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int A[],int low,int high,int x)
{
    if(low>high)
        return -1;
    int mid = low + (high-low)/2;
        if(x==A[mid])
            return mid;
        else if(x<A[mid])
            return BinarySearch(A,low,mid-1,x);
        else
            return BinarySearch(A,mid+1,high,x);

}
int main()
{
    int A[] = {2,6,21,36,47,63,81,97};
    printf("Enter a number: ");
    int x;
    scanf("%d", &x);
    int index = BinarySearch(A,2,97,x);
    return 0;
}
