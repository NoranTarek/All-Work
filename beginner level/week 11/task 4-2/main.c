#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , p, res=1;
    printf("enter the number : ");
    scanf("%d", &n);
    printf("enter the power : ");
    scanf("%d", &p);
    while(p!=0)
    {
      res*=n;
      p--;
    }
    printf("answer : %d",res);
    return 0;
}
