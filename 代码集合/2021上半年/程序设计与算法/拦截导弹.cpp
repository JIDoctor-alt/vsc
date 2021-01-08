#include<iostream>
#include<algorithm>
using namespace std;
int a[1005],dp[1005];
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
        cin>>a[i];
    fill(dp ,dp + 1005,1);
    for(int i = 1;i < N;++i)
        for(int j = 0;j < i;++j)
            if(a[i] <= a[j])
                dp[i] = max(dp[i],dp[j] + 1);
    cout<<*max_element(dp , dp + N)<<endl;
    return 0;
}