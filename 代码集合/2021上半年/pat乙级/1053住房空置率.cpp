#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int N,D;
    double e;
    cin>>N>>e>>D;
    int cnt1 = 0,cnt2 = 0;
    for(int i = 0;i < N;++i)
    {
        int K;
        cin>>K;
        int ans = 0;
        for(int j = 0;j < K;++j)
        {
            double w;
            cin>>w;
            if(e - w > 0.001)
            {
                ++ans;
            }
        }
        if(ans > (K/2))
        {
            ++cnt1;
            if(K > D)
            {
                ++cnt2;
            }
        }
    }

   
    double t1 = cnt1/(N*1.00) *100;
    double t2 = cnt2/(N*1.00) * 100;
    printf("%.1f%% %.1f%%",t1,t2);
    return 0;
}