#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter the number : ");
    int n, sum;
    scanf("%d", &n);
    while(n!=0)
    {
        sum += (n%10);
        n/=10;
    }
    printf("sum of digits = %d",sum);
    return 0;
}
