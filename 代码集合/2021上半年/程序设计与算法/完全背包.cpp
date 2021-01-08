#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_V = 1005;
int dp[MAX_V];
int v[MAX_V],w[MAX_V];
int main()
{
    int N,C;
    cin>>N>>C;
    for(int i = 1;i <= N;++i)
        cin>>w[i]>>v[i];
    for(int i = 1;i <= N;++i)
        for(int j = w[i];j <= C;++j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout<<dp[C]<<endl;
    return 0;
}