#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fac=1 , x;
    printf("enter the number :\n");
    scanf("%d",&x);
    printf("factorial = ");
    while(x>0){
        fac*=x;
        printf("%d * ",x);
        x--;
    }
    printf("= %d",fac);
    return 0;
}
