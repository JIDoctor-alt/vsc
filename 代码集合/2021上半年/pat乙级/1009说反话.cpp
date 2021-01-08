#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    vector<string> stu;
    string str;
    while(cin>>str)
    {
        stu.push_back(str);
    }
    for(int i = stu.size() - 1;i >= 0;--i)
    {
        cout<<stu[i];
        if(i != 0)
        {
            cout<<" ";
        }
        else 
        {
            cout<<endl;
        }
    }
    return 0;
}