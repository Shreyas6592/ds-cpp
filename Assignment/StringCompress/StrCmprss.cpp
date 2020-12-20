//Program to compress the string 
//I/P1: AAAABBCDDDD O/P: A4B2C1D3
//I/P2: ABCD O/P: A1B1C1D1

#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

char* StrCmprss(char str[],int len)
{
    char *o_str = (char*) malloc(2*(len+1));
    int o_idx = 0;
    int j = 0;
    for (int i=0;i<len;i++)
    {
        char Curr_char = str[i];
        char cnt = '1';
        j = i;
        while((str[j]==str[j+1]))
        {
            cnt++;
            j++;
        }
        i=j;
        o_str[o_idx++] = Curr_char;
        o_str[o_idx++] = cnt;
    }
    o_str[o_idx] = '\0';
    return o_str;
}

int main()
{
    char str[50];
    int len = 0;
    cout<<"Enter a string: "<<endl;
    cin.getline(str,50);
    cout<<"The result is: "<<endl;
    cout<<StrCmprss(str,strlen(str))<<endl;
}