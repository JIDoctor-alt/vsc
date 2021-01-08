#include<iostream>
#include<map>
#include<string>
using namespace std;
map<char,int> ms;
//根据键值查询对应的信息
int main()
{
    string str;
    getline(cin,str);
    for(int i = 0;i < str.size();++i)
    {
        ms[str[i]]++;
    }
    map<char,int>::iterator i;
    for(i = ms.begin();i != ms.end();++i)
    {
        cout<<i->first<<":"<<i->second<<endl;
    }
    return 0;
}