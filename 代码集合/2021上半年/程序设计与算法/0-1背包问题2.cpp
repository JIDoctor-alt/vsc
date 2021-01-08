#include<iostream>
#include<algorithm>
using namespace std;
int dp[1005];
int v[1005],w[1005];
int f(int i,int j)
{
    if(i == 0)
        return 0;
    if(w[i] > j)
        return f(i - 1,j);
    return max(f(i - 1,j),f(i - 1,j - w[i]) + v[i]);
}
int main()
{
    int  N,C;
    cin>>N>>C;
    for(int i = 1;i <= N;++i)
        cin>>w[i]>>v[i];
    for(int i = 1;i <= N;++i)
        for(int j = C;j >= w[i];--j)//从右向左递推
            dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
    cout<<dp[C]<<endl;
  // cout<<f(N,C)<<endl; //AC
    return 0;
}