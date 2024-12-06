#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h , salary;
    printf("enter your working hour \n");
    scanf("%d",&h);
    if(h>40){
        salary = h*50;
    }else{
    salary = (h*50) * .9 ;
    }
    printf("salary = %d",salary);
    return 0;
}
