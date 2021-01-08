#include<iostream>
#include<string>
#include<vector>
using namespace std;
using pii = pair<string,string>;
vector<pii> re;
int ans;
char modified(char c)
{
    
    if(c == '0')
    {
        return '%';
    }
    else if(c == 'l')
    {
        return 'L';
    }else if(c == '1')
    {
        return '@';
    }else if(c == 'O')
    {
        return 'o';
    }
    else 
    {
        ++ans;
        return c;
    }

}
int main()
{
    int n;
    cin>>n;
    int cnt = 0;
    for(int i = 0;i < n;++i)
    {
        ans = 0;
        string str1,str2;
        cin>>str1>>str2;
        for(int j = 0;j < str2.size();++j)
        {
            str2[j] = modified(str2[j]);
        }
        if(ans != str2.size())
        {
            ++cnt;
            re.push_back({str1,str2});
        }
    }
    if(cnt == 0)
    {
        cout<<"There "<<(n == 1 ? "is" : "are")<<" "<<n<<" account"<<(n == 1 ? "" : "s")<<" and no account is modified\n";
    }
    else 
    {
        cout<<cnt<<endl;
        for(auto &w : re)
        {
            cout<<w.first<<" "<<w.second<<endl;
        }
    }
}