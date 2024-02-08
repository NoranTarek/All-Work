#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter your ID : \n");
    int id ;
    scanf("%d",&id);
    if(id == 1234){
        printf("Harry");
    }else if(id == 5678){
    printf("Ron");
    }else if(id == 1145){
    printf("Hermione");
    }else{
    printf("Wrong ID");
    }
    return 0;
}
