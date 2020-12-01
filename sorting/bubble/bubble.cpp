#include <iostream>
using namespace std;

void show(int arr[],int num)
{
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Bubble(int arr[],int num)
{
    show(arr,num);
    int cnt = num;
    for(int i=0;cnt!=0;i++,cnt--)        //{2,4,7,1,3,6,5}
    {
        int tmp = 0;
        //cout<<"i: "<<arr[i];
        for(int j=i+1;j<num;j++)
        {
            //compare values at idx i and j
            if(arr[i]>arr[j])
            {
                // swap if val at j < val at i
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    show(arr,num);
}

int main()
{
    int arr[7] = {2,4,7,1,3,6,5};
    Bubble(arr,7);
}
