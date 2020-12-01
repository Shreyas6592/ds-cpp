#include <stdio.h>
#include <math.h>

void main()
{
    int n=0;
    scanf("%d",&n);   //user input

    int num = n,i=0;
    while(num % 10 != 0)   //digits
    {
        i++;
        num = num/10;
    }

    printf("Digits: %d\n",i);

    int nu = n;
    int num_ = 0 ;
    for(int j=i;(j>0 && nu!=0);j--)
    {
        num_ =  num_ + ((nu%10) * (pow(10,j-1)));
        printf("j: %d num_= %d \n",j,num_);
        nu /=10;
    }

    printf("Reverse :%d ",num_);
}