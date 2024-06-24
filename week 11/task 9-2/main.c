#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, bin = 0, i = 1, rem = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    while (num != 0) {
        rem = num % 2;
        num /= 2;
        bin += rem * i;
        i *= 10;
    }
    int bit=0;
    printf("enter the nth bit to check (0-31): ");
    scanf("%d", &bit);
    for(int n = 1 ; n < bit ; n++)
    {
        bin = bin/10;
    }
    if(bin%10==0)
    {
        printf("the %d bit is set to 0\n", bit);
    }
    else
    {
        printf("the %d bit is set to 1\n", bit);
    }
    return 0;
}
