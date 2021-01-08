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
        dp[i] = max(dp[i - 1],0) + a[i];//前一个最大序列

    int ans = *max_element(dp , dp + K);

    if(ans < 0)
    {
        cout<<"0 "<<a[0]<<" "<<a[K-1]<<endl;
    }
    else 
    {
        int i;
    for(i = 0;i < K;++i)
    {
        if(dp[i] == ans)
            break;
    }

    int j,cnt = ans;
    for(j = i;j >= 0;--j)
    {
        cnt -= a[j];

        if(cnt == 0)
            break;
    }

        printf("%d %d %d\n",ans,a[j],a[i]);
    }
    
    

    return 0;
}