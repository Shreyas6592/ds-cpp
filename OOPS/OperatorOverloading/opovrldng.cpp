#include <iostream>

using namespace std;

class Cmplx
{
    int real;
    int imag;
    public:

    Cmplx(int r=0,int i=0):real(r),imag(i){}

    const Cmplx operator+(const Cmplx& c) const
    {
        Cmplx temp;
        temp.real = c.real + real;
        temp.imag = c.imag;
        return temp;
    }

    friend const Cmplx operator+(const int& m, const Cmplx& c);

    void Print()
    {
        cout<<"Real: "<<this->real<<"Imag: "<<this->imag<<endl;
    }
};

const Cmplx operator+(const int& m, const Cmplx& c)
{
    Cmplx temp;
    temp.real = m + c.real;
    temp.imag = c.imag;
    return temp;
}

int main()
{
    Cmplx c(1,2);
    Cmplx d;
    c.Print();
    d.Print();
    c = 5 + c;
    d = d + 5;
    c.Print();
    d.Print();
}