#include<iostream>
#include<iomanip>
#include<string>
#include<set>
using namespace std;
int a[110];
int main()
{   
    long long N;
    cin>>N;
    int k;
    cin>>k;
    int ans = 0;
    long  long sum = 1;
    for(int i = 1;i <= N;++i)
    {
        sum *= i;
    }
    string str = to_string(sum);
    int i;
    for( i = str.size()-1;i >= 0;--i)
    {
        if(str[i] != '0')
            break;
        else 
        {
            ++ans;
        }
    }
    string res = str.substr(0,i+1);
    if(res.size() >= k)
    {
        res = str.substr(i-k+1,k);
    }
    else 
    {
        for(int i = 0;i < k - res.size();++i)
        res = '0' + res;
    }
    cout<<res<<" "<<ans;
    return 0;
}