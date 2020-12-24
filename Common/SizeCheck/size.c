#include <stdio.h>

//#pragma pack(1)

typedef struct
{
    int i;
}sizec;

void main()
{
    sizec s;
    printf("Size of sizec is: %d\n",(int)sizeof(s));
    //printf("Size of Int is: %d\n",(int)sizeof(i));
}