#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("please enter a dollars and cents amount : \n");
    int x;
    scanf("%d",&x);
    float y = x +(x*.05);
    printf("amount with tax is : %f \$",y);
    return 0;
}
