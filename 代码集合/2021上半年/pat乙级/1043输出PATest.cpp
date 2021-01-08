#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    map<char,int> ms;
    int cnt = 0,ans = 0;
    for(int i = 0;i < str.size();++i)
    {
        if(str[i] == 'P'|| str[i] == 'A' || str[i] == 'T' || str[i] == 'e'||str[i] == 's'||str[i] == 't')
        {
            ++cnt;
        }
        ++ms[str[i]];
    }
    while(true)
    {
        if(ms['P'])
        {
            cout<<"P";
            --ms['P'];
            ++ans;
        }
        if(ms['A'])
        {
            cout<<"A";
            --ms['A'];
            ++ans;
        }
        if(ms['T'])
        {
            cout<<"T";
            --ms['T'];
            ++ans;
        }
        if(ms['e'])
        {
            cout<<"e";
            --ms['e'];
            ++ans;
        }
        if(ms['s'])
        {
            cout<<"s";
            --ms['s'];
            ++ans;
        }
        if(ms['t'])
        {
            cout<<"t";
            --ms['t'];
            ++ans;
        }
        if(ans == cnt)
        {
            break;
        }
    }

    return 0;
}