#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    int K;
    scanf("%d",&K);
    for(int i = 0;i < K;++i)
        scanf("%d", a + i);
    int ans = a[0], x = ans ,cur;
    for(int i = 1;i < K;++i)
    {
        cur = max(x ,0) + a[i];
        x = cur;
        ans = max(ans ,cur);
    }
    printf("%d\n",ans);
    return 0;
}