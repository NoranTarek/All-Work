#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter the elements of the array :\n");
    int b[5]={0,0,0,0,0};
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

       }
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        if( a[i]>1){
            printf("element of %d = %d \n",i ,b[i]);

        }
    }
    return 0;
}
