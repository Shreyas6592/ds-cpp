//Input: 73
//Start: 3
//End: 6
//Output: 9

#include <iostream>

using namespace std;

int get_res(int inum,int start,int end)
{
    int res = 0,id=0,idx=0;
    for(int idx=start,id=0;idx<=end;idx++,id++)
    {
        char extracted_bit = (inum>>idx) & 0x01;
        res |= (extracted_bit<<id);
    }
    return res;
}

int main()
{
    //Declare variables
    int inum,st_bit,end_bit,res=0;

    //Get input from the user for number, start and end position of bit
    cout<<"Enter the number from which the bits are to be extracted"<<endl;
    cin>>inum;

    cout<<"Enter the start bit"<<endl;
    cin>>st_bit;

    cout<<"Enter the end bit"<<endl;
    cin>>end_bit;

    cout<<"The result number is:"<<(unsigned)get_res(inum,st_bit,end_bit)<<endl;
}