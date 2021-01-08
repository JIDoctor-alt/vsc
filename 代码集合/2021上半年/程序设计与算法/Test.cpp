#include<iostream>
#include<algorithm>
using namespace std;
int N,C;
int a[100100];
bool Valid(int c)
{
    int cnt  = 1,totalCur = a[0];
    for(int i = 1;i < N;++i)
    {
        if(a[i] - totalCur >= c)
        {
            ++cnt;
            totalCur = a[i];
        }
        else 
            continue;
    }
    return cnt >= C;
}
int main()
{
    cin>>N>>C;
    for(int i = 0;i < N;++i)
        cin>>a[i];
    sort(a,a+N);
    int L = 1,R = 1<<30;
    int lastPos;
    while(L <= R)
    {
        int mid = L + (R - L)/2;
        if(Valid(mid))
        {
            lastPos = mid;
            L = mid + 1;
        }
        else 
            R = mid - 1;
        
    }
    cout<<lastPos<<endl;
    return 0;
}