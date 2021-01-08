#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    string cg;
    getline(cin,cg);
    map<char,int> ms;
    for(auto &e : str)
    {
        ms[e]++;
    }
    int cnt = (ms.count(cg[0]) ? ms[cg[0]] : 0);
    cout<<cnt<<endl;
    return 0;
}