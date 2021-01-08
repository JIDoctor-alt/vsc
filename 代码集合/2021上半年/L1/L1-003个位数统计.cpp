#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    map<int,int> ms;
    string str;
    getline(cin,str);
    for(int i = 0;i < str.length();++i)
        ms[str[i] - '0']++;
    for(auto i : ms)
        cout<<i.first<<":"<<i.second<<endl;
    return 0;
}