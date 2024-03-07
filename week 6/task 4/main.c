#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    printf("enter the text : \n");
    scanf("%s", &s);
    printf("enter character to search : \n");
    char n ;
    scanf(" %c", &n);
    int i , o = strlen(s);
    for(i=0;i<o;i++)
    {
        if(s[i]==n)
            printf("'%c' is found at index %d \n",n ,i+1);
    }
    return 0;
}
