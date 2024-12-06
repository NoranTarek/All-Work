#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, c=0;
    printf("Enter the number : \n");
    scanf("%d", &x);
    for(;x>0;x /= 10)
    {
        c++ ;
    }
    printf("number of digits is : %d",c);
    return 0;
}
