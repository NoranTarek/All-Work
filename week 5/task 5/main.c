#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=10, y=20, z=30;
    int *px , *py , *pz;
    px=&x; py=&y; pz=&z;
    printf("x = %d , y = %d , z =%d \n",x ,y ,z); // x=10 , y=20 , z=30
    printf("px = %p , py = %p , pz =%p \n",px ,py ,pz); // px = &x , py = &y , pz = &z
    printf("*px = %d , *py = %d , *pz =%d \n",*px ,*py ,*pz); // *px=10 , *py=20 , *pz=30
    printf("swapping pointers \n");
    pz=px; px=py; py=pz;
    printf("x = %d , y = %d , z =%d \n",x ,y ,z); // x=10 , y=20 , z=30
    printf("px = %p , py = %p , pz =%p \n",px ,py ,pz); // px = &y , py =&x , pz= &x
    printf("*px = %d , *py = %d , *pz =%d \n",*px ,*py ,*pz); // *px=20 , *py=10 , *pz=10
    return 0;
}
