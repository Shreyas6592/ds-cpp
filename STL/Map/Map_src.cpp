
#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 

void output_nums(map<int,int> m)
{
    map<int,int>::iterator it = m.begin();
    while(it != m.end())
    {
        cout<<"First: "<<it->first<<", Second: "<<it->second<<endl;
        it++;
    }
}

void output_str(map<string,int> m)
{
    map<string,int>::iterator it = m.begin();
    while(it != m.end())
    {
        cout<<"First: "<<it->first<<", Second: "<<it->second<<endl;
        it++;
    }
}
  
int main() 
{ 
    // empty map container 
    map<int, int> map_of_nums; 
    map<string, int> map_of_strs;

    map<string, int> :: iterator it;

    map_of_nums.insert(pair<int,int>(1,1));
    map_of_nums.insert(pair<int,int>(2,2));
    map_of_nums.insert(pair<int,int>(3,3));
    map_of_nums[4] = 4;

    map_of_strs.insert(pair<string,int>("One",1));
    map_of_strs.insert(pair<string,int>("Two",2));
    map_of_strs.insert(pair<string,int>("Three",3));

    map_of_nums.erase(1);

    it = map_of_strs.find("Three");
    if(it==map_of_strs.end())
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Found"<<endl;
    }
    

    output_nums(map_of_nums);
    output_str(map_of_strs);

    return 0; 
} 
