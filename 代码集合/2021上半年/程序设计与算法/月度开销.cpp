#include<iostream>
#define EPS 1e-6
using namespace std;
int a[100100];
int N,M;
bool Valid(int x)
{
    int cnt = 1,totalCost = 0;
    for(int i = 0;i < N;++i)
    {
        if(a[i] > x)
            return false;
        if(totalCost + a[i] <= x)
           totalCost += a[i];
        else 
        {
            totalCost = a[i];
            ++cnt;
        }
    }
    return cnt <= M;
}
int main()
{
    ios::sync_with_stdio(false);
    int L = 1<<30,R = 0;
    cin>>N>>M;

    for(int i = 0;i < N;i++)
    {
        cin>>a[i];
        L = min(L,a[i]);
        R += a[i];
    }
    int mid;
    while (R - L > EPS)
    {
       // mid = L + (R - L)/2;
       mid = (L+R)/2;
        if(Valid(mid))
            R  = mid  ;
        else 
            L = mid + 1;
    }
    cout<<R<<endl;
    return 0;
}