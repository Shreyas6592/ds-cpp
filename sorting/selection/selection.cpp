#include <iostream>
#include <time.h>

using namespace std;

void selection_sort(int arr[],int num)
{
    time_t seconds = time(NULL);
    cout<<"["<<seconds<<"]"<<"Before sort ";
    for(int k=0;k<num;k++)
    {
        cout<<arr[k]<<" ";
    }
    for(int i=0;i<num;i++)                 //{6,2,5,4,1,8,7,3}
    {
        int imin = arr[i];
        int idx = i;
        for(int j = i+1;j<num;j++)
        {
            if(imin > arr[j])
            {
                imin = arr[j];
                idx = j;
            }
        }
        if(imin != arr[i])
        {
            int tmp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = tmp;
        }
    }
    seconds = time(NULL);
    cout<<endl<<"["<<seconds<<"]"<<"After sort ";
    for(int m=0;m<num;m++)
    {
        cout<<arr[m]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arry[8] = {6,2,5,4,1,8,7,3};
    selection_sort(arry,8);
}