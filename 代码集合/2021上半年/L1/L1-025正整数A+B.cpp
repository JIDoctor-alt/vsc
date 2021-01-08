#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int Valid(string &s)
{
    int sum = 0;
    for(int i = 0;i < s.length();++i)
    {
        if(isdigit(s[i]))
             sum = sum *10 + (s[i] - '0');
        else 
            return -1;
    }
    if(sum > 1000 || sum < 1)
        return -1;
    return sum;
}
int main()
{
    
    string str;
    getline(cin,str);
    string st1 = str.substr(0,str.find(" "));
    string st2 = str.substr(str.find(" ")+1);
    int a = Valid(st1);
    int b = Valid(st2);
    if(a == -1)
        cout<<"?";
    else 
        cout<<a;
    cout<<" + ";
    if(b == -1)
        cout<<"?";
    else 
        cout<<b;
    if(a != -1 && b != -1)
        cout<<" = "<<(a+b);
    else 
        cout<<" = ?";
    return 0;
}