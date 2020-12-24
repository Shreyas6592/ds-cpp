//Given a string in format abcdefXfedcba
//Determine if it is a palindrome or not
//Method1: Uses string method
//Methos2: Uses stack

//Author: Shreyas Atul Pophli
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

//Returns: TRUE : If string is a palindrome
//Returns: False: If string is not a palindrome
bool Is_palindrome(char str[])
{
    bool ret = false;
    auto i=0,j=0;
    int len = strlen(str);
    for(i=0,j=len-1;i<j;i++,j--)
    {
        if(str[i] != str[j])
        {
            break;
        }
        cout<<"Checking.."<<str[i]<<" and "<<str[j]<<endl;
    }
    if(i==j)
    {
        ret = true;
    }
    return ret;
}

bool Is_Pal_Using_Stack(char str[])
{
    bool ret = true;
    stack <char> S;
    auto i=0,j=0;
    int len = strlen(str);
    while(str[i] != 'X')
    {
        S.push(str[i]);
        cout<<"Pushed.. "<<str[i]<<endl;
        i++;
    }
    i++;
    cout<<"Start of comparison, now at: "<<str[i]<<endl;

    while(!S.empty() || i<=len-1)
    {
        cout<<"Comp: "<<str[i]<<" and "<<S.top()<<endl;
        if(str[i++] != S.top())
        {
            ret = false;
            break;
        }
        S.pop();
    }

    return ret;
}

int main()
{
    char str[] = "abcdefXfedcba";
    cout<<"Lenght from main is: "<<strlen(str)<<endl;
    if(Is_palindrome(str))
    {
        cout<<"The string is a palindrome"<<endl;
    }
    else
    {
        cout<<"String is not a palindrome"<<endl;
    }

    if(Is_Pal_Using_Stack(str))
    {
        cout<<"The string is a palindrome"<<endl;
    }
    else
    {
        cout<<"String is not a palindrome"<<endl;
    }
    
}