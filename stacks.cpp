//Program to make a stack and store the string in it
//Stack shall have the following functions:
//1. Push
//2. Pop
//3. Peek
//4. Count
//5. Clear
//6. Constructor

#include <iostream>
#include <string>

using namespace std;

class Stack
{
    private:
        int data[100];
        int top;
    public:
        Stack()
        {
            top = -1;
        }

        void push(int v)
        {
            ++top;
            data[top] = v;  
        }   
};

int main()
{
    Stack test;
}
