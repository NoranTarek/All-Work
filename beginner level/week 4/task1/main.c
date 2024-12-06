#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a[5] ={0} ;
    int b[5]={0};
    printf("enter the element of the array : \n");
    for(int i = 0 ; i < 5 ; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the numbers 0 or 1 : \n");
    int n = 0;
    scanf("%d",&n);
    if (n == 1){
    for(int i = 0 ; i < 5 ; i++)
    {
       for ( int j = i ; j<5 ; j++){
           if (a[i]> a [j]){
               int temp= a[i];
               a[i]= a[j];
               a[j]= temp;
           }
       }
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d ", a[i]);
    }}
    else if (n == 0){
    for(int i = 0 ; i < 5 ; i++)
    {
       for ( int j = i ; j<5 ; j++){
           if (a[i]< a [j]){
               int temp= a[i];
               a[i]= a[j];
               a[j]= temp;
           }
       }
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d ", a[i]);
    }
    }
    return 0;
}
