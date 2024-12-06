#include <stdio.h>
#include <stdlib.h>

struct employee
{
   int sal;
   int bon;
   int ded;
}Mohsen, Maged, Mariam;
int main()
{
    printf("enter the salary of Mohsen :\n");
    scanf("%d", &Mohsen.sal);
    printf("enter the bonus of Mohsen :\n");
    scanf("%d", &Mohsen.bon);
    printf("enter the deduction of Mohsen :\n");
    scanf("%d", &Mohsen.ded);
    printf("\n");
    printf("enter the salary of Maged :\n");
    scanf("%d", &Maged.sal);
    printf("enter the bonus of Maged :\n");
    scanf("%d", &Maged.bon);
    printf("enter the deduction of Maged :\n");
    scanf("%d", &Maged.ded);
    printf("\n");
    printf("enter the salary of Mariam :\n");
    scanf("%d", &Mariam.sal);
    printf("enter the bonus of Mariam :\n");
    scanf("%d", &Mariam.bon);
    printf("enter the deduction of Mariam :\n");
    scanf("%d", &Mariam.ded);
    printf("\n");
    printf("salary of Mohsen = %d \n",Mohsen.bon+Mohsen.sal-Mohsen.ded);
    printf("salary of Maged = %d \n",Maged.bon+Maged.sal-Maged.ded);
    printf("salary of Mariam = %d \n",Mariam.bon+Mariam.sal-Mariam.ded);
    return 0;
}
