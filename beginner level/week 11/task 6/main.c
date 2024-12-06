#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0 , even = 0 , odd = 0;
    printf("enter the size of the array :\n");
    scanf("%d", &n);
    int x[n];
    printf("enter the elements of the array : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &x[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(x[i]%2==0)
            even++;
        else
            odd++;
    }
    printf("total even elements : %d \n",even);
    printf("total odd elements : %d \n",odd);
    return 0;
}
