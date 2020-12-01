#include "stdio.h"

int fib(int num)
{
    int t1 = 0, t2 = 1, nextterm;
    for(int i = 0; i<num ;i++)
    {
        printf("%d ",t1);
        nextterm = t1+t2;
        t1 =  t2;
        t2 = nextterm;
    }
    printf("\n");
}

int f(int i)
{
    if(i == 0 || i == 1)
    {
        return i;
    }
    else
    {
        return (f(i-1) + f(i-2));
    }
}

void main()
{
    int num = 0;
    printf("Enter number of elements desired\n");
    scanf("%d",&num);

    fib(num);

    for(int i = 0; i<= num;i++)
    {
        printf("%d ",f(i));
    }
}