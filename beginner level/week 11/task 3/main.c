#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter an operator (+,-,*,/) : ");
    char c;
    scanf("%c", &c);
    printf("enter two operands : ");
    float n, m;
    scanf("%f %f", &n , &m);
    switch(c)
    {
    case '+':
        printf("%f + %f = %f",n ,m ,n+m);
        break;
    case '-':
        printf("%f - %f = %f",n ,m ,n-m);
        break;
    case '*':
        printf("%f * %f = %f",n ,m ,n*m);
        break;
    case '/':
        printf("%f / %f = %f",n ,m ,n/m);
        break;
    default:
        printf("wrong operator !");
        break;
    }
    return 0;
}
