#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int sum = 0;
    for(auto &c : str)
    {
        if(isdigit(c))
        {
            sum = sum * 10 + (c - '0');
        }
    }
    cout<<sum<<endl;
    return 0;
}