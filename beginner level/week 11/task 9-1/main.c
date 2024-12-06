#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0 , s=1;
    printf("enter the binary number : ");
    int n ; scanf("%d", &n);
    while(n != 0)
    {
        sum += ((n%10)*s);
        s*=2;
        n/=10;
    }
    printf("number in decimal = %d",sum);
    return 0;
}
