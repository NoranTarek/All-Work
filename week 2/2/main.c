#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("please, enter the number :\n");
    int x ;
    scanf("%d",&x);
    if(x%2==0){
        printf("number is even");
    }else{
    printf("number is odd");
    }
    return 0;
}
