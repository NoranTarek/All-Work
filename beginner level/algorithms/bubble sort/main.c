#include <stdio.h>
#include <stdlib.h>
void BubbleSort(int A[],int n)
{
    for(int i = 1;i < n-1;i++)
    {
        int flag = 0;
        for(int j = 0;j < n-1;j++)
        {
            if(A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}
int main()
{
    int A[] = {2,7,4,1,5,3};
    BubbleSort(A,6);
    for(int i = 0; i < 6 ;i++)
        printf("%d ",A[i]);
    return 0;
}
