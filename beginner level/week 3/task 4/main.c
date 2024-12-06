#include <stdio.h>
#include <stdlib.h>
int login(int , int);
int main()
{
    int i,p;
    login(i,p);
    return 0;
}
int login (int I,int P)
{
    printf("enter your id : \n");
    scanf("%d",&I);
    for(int i = 1;i<3;i++)
    {
    if(I==1234)
    {
        printf("enter your password : \n");
        scanf("%d",&P);
         for(int j = 1; j<3;j++)
         {
             if (P==5678)
                goto b;
             else
             {
                 printf("please try again : ");
                 scanf("%d",&P);
             }
         }
         goto aa;
    }
    else
    {
       printf("please try again : ");
       scanf("%d",&I);
    }
    }
   aa: printf("login failed");
   b:
       return ;
}
