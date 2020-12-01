#include "stdio.h"

int fact(int num)
{
    int res = 1;
    for(int i=num;i>=1;i--)
    {
        res*=i;
    }
    return res;
}

int f(int num)
{
    if (num>=1)
    {
        return num * f(num-1);
    }
    else
    {
        return 1;
    }
}

void main()
{
    int num;
    printf("Enter a num \n: ");
    scanf("%d",&num);

    printf("\n%d",f(num));
}