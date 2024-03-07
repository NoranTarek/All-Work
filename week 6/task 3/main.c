#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[100],s2[100];
    printf("enter the text : \n");
    scanf("%s", &s1);
    int i;
    int c = strlen(s1);
    for(i=0;i<c;i++)
    {
        s2[i]=s1[c-i-1];
    }
    printf("reverse text : ");
    for(i=0;i<c;i++)
    {
        printf("%c",s2[i]);
    }
    return 0;
}
