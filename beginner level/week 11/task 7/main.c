#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c[100],copy[100];
    printf("enter the string : \n");
    scanf("%s", &c);
    for(int i = 0 ; i < 100 ; i++)
    {
        if(c[i]=='/0')
        {
            break;
        }
        copy[i]=c[i];
    }
    printf("the copy of the string is : %s",copy);
    return 0;
}
