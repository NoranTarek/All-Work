#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("enter the height of the pyramid :\n");
    scanf(" %d",&x);
    for(int i = 0 ; i<=x ; i++)
    {
        for(int k = 0 ; k<x-i ; k++)
        {
         printf(" ");
        }
        for (int j = 0 ; j<2*i-1 ; j++ )
        {
           printf("*");
        }
        printf("\n");
    }
    return 0;
}
