#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    map<int,int> ms;
    for(int i = 0;i < str.size();++i)
    {
        int id = (str[i] - '0');
        ms[id]++;
    }
    map<int,int>::iterator i;
    for(i = ms.begin(); i != ms.end();++i)
    {
        cout<<i->first<<":"<<i->second<<endl;
    }
    return 0;
}