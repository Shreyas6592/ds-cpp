#include <iostream>
#include <cstring>

using namespace std;

class Base
{
    public:
    int A;
    char *str;
    Base(int a, char s[20]):A(a),str(s){}
};

class Derived:public Base
{
    public:
    Derived(int a,char* s):Base(a,s){}
    void print();
};


void Derived::print()
{
    cout<<this->str<<endl;
}

int main()
{
    Derived* ptr = new Derived(10,"Shreyas");
    ptr->print();

}