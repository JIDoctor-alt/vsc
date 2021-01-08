#include<iostream>
#include<iomanip>
#include<math.h>
#include<cfloat>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;
using pdd = pair<double,double>;
pdd a[10005];
int main()
{
    int n,d,k = 0;
    while(scanf("%d%d",&n,&d), n || d)
    {
        double f = true;
        ++k;
        for(int i = 0;i < n;++i)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            if(y > d)
            {
                f = false;
            }
            double  t = sqrt(d * d - y * y);
            a[i] = {x - t, x + t};
        }
        if(!f)
        {
            printf("Case %d: -1\n",k);
            continue;
        }
        sort(a, a + n);
        double pos = 0.0 - DBL_MAX;
        int ans = 0;
        for(int i = 0;i < n;++i)
        {
            auto x = a[i].first , y = a[i].second;
            if(x > pos)
            {
                ++ans;
                pos = y;
            }
            else 
            {
                pos = min(pos,y);
            }
        }
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}