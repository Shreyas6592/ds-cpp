// C++ program to convert a decimal num
// to binary number and store in a data struct of given size
  
#include <iostream> 
#include <limits.h>
#include <bits/stdc++.h> 
using namespace std; 

class BitSet_ { 

public:
    char* arr;
    int capacity;
    int num;
    BitSet_(int N, int num)  
    {
        capacity = N;
        size_t size = calcSize(N);
        cout<<"Number of bytes assigned:"<<(unsigned)size<<" for "<<num<<endl;
        arr = (char*)malloc(size);   
        if(NULL == arr)
        {
            cout<<"Memory creation failed!"<<endl;
            exit(-1);
        }
        *arr = num;

        //bitset<32> b(num);//Only for test
        //cout<<b[0]<<endl;
    } 

    //To print the value at a particular bit location
    void BitSet_P(unsigned int i)
    {
        //Since little endian the Lowest bit is stored first
        //Identify the byte in which the bit is present, TBD: Handle byte corner case check
        cout<<"The value at bit "<<i<<" is:";
        if(i > (capacity-1))
        {
            exit(-1);
        }
        unsigned int byte = i/8;
        unsigned int offset = i % 8;
        //cout<<"Calculated byte: "<<(unsigned)arr[byte],<<" Calculated offset: "<<(unsigned)offset<<endl;
        cout<<(unsigned)(arr[byte] & (0x01<<offset))<<endl;
    }
       
    //Function to calculate the bytes needed   
    size_t calcSize(unsigned int N) 
    { 
       size_t s = 0;
       unsigned int rem = 0;
       unsigned int byte = N/8;
       rem = N%8;
       if(rem>0)
       {
           rem = 1;
       }
       //cout<<byte<<" "<<rem<<endl;
       return byte+rem; 
    } 
}; 
  
// Driver prog 
int main() 
{ 
    BitSet_ B(32,17); //Constructor shall be called and will set create a char array for required bytes(here 32 bits, hence 4 byte)
                      //The second parameter is the number that has to be stored at that location  
    B.BitSet_P(0);    //BitSet_P shall be used to access the bit at location(to be given as parameter)
    return 0; 
} 
