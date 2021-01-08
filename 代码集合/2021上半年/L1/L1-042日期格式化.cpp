#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int x = str.rfind('-');
    string res = str.substr(x+1) + "-";
    res += str.substr(0,x);
    cout<<res<<endl;
    return 0;
}