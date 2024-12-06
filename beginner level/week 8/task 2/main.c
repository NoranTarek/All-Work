#include <stdio.h>
#include <stdlib.h>

struct student
{
    int prog , data , dis , alg;
};
int main()
{
    struct student g[10];
    int c;
    for(int i = 0 ; i < 10 ; i++)
    {
        g[i].prog= ++c;
        g[i].data= ++c;
        g[i].dis= ++c;
        g[i].alg= ++c;
    }
    printf("enter the ID of student from 1 to 10 : \n");
    int id=0;
    a:scanf("%d", &id);
    if(id>0 && id<10)
    {
        printf("the grades is %d , %d , %d , %d \n",g[id-1].prog ,g[id-1].data,g[id-1].dis,g[id-1].alg);
        int test;
        printf("enter 0 if grades are wrong \n");
        scanf("%d", &test);
        if(test == 0)
        {
            scanf("%d %d %d %d", &g[id-1].prog , &g[id-1].data, &g[id-1].dis, &g[id-1].alg);
            printf("the true grades is :  %d , %d , %d , %d \n",g[id-1].prog ,g[id-1].data,g[id-1].dis,g[id-1].alg);
        }
    }
    else
    {
        printf("wrong ID! enter from 1 to 10 \n");
        goto a;
    }
    return 0;
}
