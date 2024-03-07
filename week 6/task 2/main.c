#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    printf("enter the text : ");
    scanf("%s",&s);
    for(int i = 0 ; i < strlen(s); i++)
    {
        if(s[i]<=57 && s[i]>= 48){
            printf("%c of index %d is digit \n",s[i] ,i+1);
        }else if (s[i]<=122 && s[i]>= 65 && s[i]<=90 && s[i]>=97)
        {
            printf("%c of index %d is character \n",s[i] ,i+1);
        }else
        {
            printf("%c of index %d is special character \n",s[i] ,i+1);
        }
    }
    printf("Hello world!\n");
    return 0;
}
