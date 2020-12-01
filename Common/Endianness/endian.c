#include <stdio.h>

void main(int argc, char *argv[])
{
    unsigned int num = 1;
    char *p= (char*) &num;
    if(p)
    {
        printf("Little endian\n");  //Last byte stored first  0x0001
    }
    else
    {
        printf("Big endian\n");  //First byte stored first
    }
}