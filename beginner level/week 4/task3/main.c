#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter the elements of the array :\n");
    int b[5]={0};
    int a[5]={0};
    for(int i = 0 ; i < 5 ; i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i = 0 ; i < 5 ; i++)
    {
       for ( int j = 0 ; j<5 ; j++){
           if (b[i]==b[j]){
               a[i]=a[i]+1;
           }
           if (a[i]>1){
            b[i]=-1;
           }
       }
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        if(b[i]==-1 && a[i]>=1){}else
            printf("element of %d = %d \n",i ,b[i]);
    }
    return 0;
}
