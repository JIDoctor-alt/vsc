#include<iostream>
#include<string>
using namespace std;
int ans = 0;
string str;
bool check()
{
    int cnt = 0;
    for(int i = 0;i < str.length();++i)
    {
        if(str[i] == '(')
        {
            ++cnt;
        }
        else 
        {
            --cnt;
            if(cnt < 0)
                return false;
        }
    }
    return cnt == 0;
}
void dfs(int k)
{
    if(k == str.length() )
    {
        if(check())
            ++ans;
        return;
    }
    

    if(str[k] == '?')
    {
        str[k] = '(';
        dfs(k+1);

        str[k] = ')';
        dfs(k + 1);

        str[k] = '?';
    }
    else 
        dfs(k + 1);
}
int main()
{
    getline(cin,str);
    dfs(0);
    cout<<ans<<endl;
    return 0;
}