#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ID = 123, Pass = 456, id ,pass;
    printf("enter your ID : \n");
    scanf("%d",&id);
    if(ID==id)
    {
        printf("enter the password : \n");
        if(Pass == pass)
        {
            printf("welcome him");
        }else{
        for(int i = 0 ; i<3 ; i++)
        {
            printf("incorrect password \n");
            scanf("%d",&pass);
            if(pass==Pass)
                break;
        }
            if(pass==Pass)
                printf("welcome");
            else
                printf("you are not registered \n no more tries");
        }
    }
    return 0;
}
