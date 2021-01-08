#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string str;
    map<char,int> ms;
    getline(cin,str);
    string ctr;
    getline(cin,ctr);
    for(auto &w : str)
        ms[w]++;
    int cnt = (ms[ctr[0]]? ms[ctr[0]] : 0);
    cout<<cnt<<endl;
    return 0;
}