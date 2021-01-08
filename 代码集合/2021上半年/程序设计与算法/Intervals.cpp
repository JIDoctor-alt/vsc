#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
pii v[500005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[i] = {x,y};
    }
    v[n] = {10000000,10000000};
    sort(v, v + n + 1);
    int s = v[0].first , e = v[0].second;
    for(int i = 0;i <= n;++i)
    {
        int x = v[i].first, y = v[i].second;
        if( x > e)
        {
            printf("%d %d\n",s ,e);
            s = x;
            e = y;
        }
        else 
        {
            e = max(e,y);
        }
    }
    return 0;
}