#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("please enter 10 numbers : \n");
    float x , sum , av;
    for(int i = 0;i<10;i++)
    {
        scanf("%f",&x);
        sum+=x;
    }
    av = sum / 10;
    printf("summation of the numbers is : %0.2f",sum);
    printf("average of the numbers is : %0.2f",av);
    return 0;
}
