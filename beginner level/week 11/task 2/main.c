#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter year : \n");
    scanf("%d", &n);
    if(n%400==0)
    {
        printf("leap year \n");
    }else if (n%4==0 && n%100!=0)
    {
        printf("leap year \n");
    }else
    {
        printf("not a leap year");
    }
    return 0;
}
