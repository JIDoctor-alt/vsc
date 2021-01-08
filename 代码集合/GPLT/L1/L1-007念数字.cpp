#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    map<char,string> ms;
    ms['0'] = "ling";
    ms['1'] = "yi";
    ms['2'] = "er";
    ms['3'] = "san";
    ms['4'] = "si";
    ms['5'] = "wu";
    ms['6'] = "liu";
    ms['7'] = "qi";
    ms['8'] = "ba";
    ms['9'] = "jiu";
    ms['-'] = "fu";
    string str;
    getline(cin,str);
    for(int i = 0;i < str.size();++i)
    {
        cout<<ms[str[i]];
        if(i != str.size() - 1)
            cout<<" ";
        else 
            cout<<"\n";
    }
    return 0;
}