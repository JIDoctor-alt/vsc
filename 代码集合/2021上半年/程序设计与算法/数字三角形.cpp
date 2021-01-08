#include<iostream>
#include<algorithm>
using namespace std;
int dp[105],a[105][105];
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;++i)
        for(int j = 0;j <= i;++j)
            cin>>a[i][j];
    for(int i = n-1;i >= 0;--i)
        for(int j = 0;j <= i;++j)
            dp[j] = max(dp[j],dp[j + 1]) + a[i][j];
    cout<<dp[0]<<endl;
    return 0;
}
f(i,j) = max(f(i + 1, j),f(i + 1,j + 1)) + a[i][j]