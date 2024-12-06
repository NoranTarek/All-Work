#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    printf("enter the first number :\n");
    scanf("%d",&a);
    printf("enter the second number :\n");
    scanf("%d",&b);
    printf("enter the third number :\n");
    scanf("%d",&c);
    int x = (a>b)?a:b;
    int y = (x>c)?x:c;
    printf("the maximum number is : %d",y);
    return 0;
}
