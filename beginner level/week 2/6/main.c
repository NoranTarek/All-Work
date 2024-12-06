#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter the result of 3*4 : \n");
    int res;
    for(;;)
    {
        scanf("%d",&res);
        if(res==12){
            printf("Thanks");
            break;
        }
        else
            printf("Try again");
    }
    return 0;
}
