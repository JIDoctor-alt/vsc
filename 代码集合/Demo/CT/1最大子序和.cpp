//f(i) = max(f(i - 1),0) + a[i];
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],dp[100005];
int main()
{
    int K;
    scanf("%d",&K);
    for(int i = 0;i < K;++i)
        scanf("%d",a + i);
    dp[0] = a[0];
    for(int i = 1;i < K;++i)
        dp[i] = max(dp[i - 1],0) + a[i];
    int ans = *max_element(dp , dp + K);
    printf("%d\n",ans);
    return 0;
}