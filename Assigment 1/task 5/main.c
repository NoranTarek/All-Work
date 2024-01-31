#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[3];
    printf("enter the numbers : \n");
    for(int i = 0;i<3;i++){
        scanf("%d",&x[i]);
    }
    printf("before reversing : \n");
    for(int i = 0;i<3;i++){
        printf("number %d is : %d \n",i+1 ,x[i]);
    }
    printf("after reversing : \n");
    for(int i = 0;i<3;i++){
        printf("number %d is : %d \n",i+1 ,x[3-i-1]);
    }
    return 0;
}
