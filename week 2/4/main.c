#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter your grade : \n");
    int g;
    scanf("%d",&g);
    if (g>=85)
    {
        printf("excellent");
    }else if(g>=75)
    {
    printf("very good");
    }else if (g>=65)
    {
    printf("good");
    }else if(g>=50)
    {
    printf("pass");
    }else
    {
        printf("fail");
    }
    return 0;
}
