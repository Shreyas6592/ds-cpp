#include <iostream> 
using namespace std; 
  
void fun(int x)  
{  
    if(x > 0)  
    {  
        fun(--x);  
        cout << x <<" ";  
        fun(--x);  
    }  
}  
  
int main()  
{  
    int a = 4;  
    fun(a);  
        cout<<endl;
    cout<<"1%2 is "<<(unsigned)(1%2)<<endl;
    return 0;  
}  