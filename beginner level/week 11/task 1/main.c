#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, bin = 0, i = 1, rem = 0,one = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    while (num != 0)
    {
        rem = num % 2;
        num /= 2;
        bin += rem * i;
        i *= 10;
    }
    while(bin !=0)
    {
        if(bin % 10 !=0)
            one++;
        bin/=10;
    }
    printf("number of zeros is : %d \n",32-one);
    printf("number of ones is : %d \n",one);
    return 0;
}
