#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char n[100];
    printf("enter the text : \n");
    scanf(" %s", &n);
    for(int i = 0;i < strlen(n); i++ )
    {
        if(n[i] >=97 && n[i] <= 122)
            n[i] = (int)n[i] - 32;
    }
    for(int i = 0;i < strlen(n); i++ )
    {
        printf("%c",n[i]);
    }
    return 0;
}
