#include<iostream>
#include<iomanip>
using namespace std;
const int MAX_S = 100005;
double h[MAX_S],w[MAX_S];
int N,K;
bool judge(int c)
{
    int cnt = 0;
    for(int i = 0;i < N;++i)
    {
        cnt += (h[i]/c)*(w[i]/c);
    }
    return cnt >= K;
}
int main()
{
    cin>>N>>K;
    for(int i = 0;i < N;++i)
    {
        cin>>h[i]>>w[i];
    }
    int l = 1,r = 1<<30;
    while(l < r)
    {
        int mid = (l + r + 1)/2;
        if(judge(mid))
        {
            l = mid;
        }
        else 
        {
            r = mid - 1;
        }
    }
    cout<<l<<endl;

    return 0;
}