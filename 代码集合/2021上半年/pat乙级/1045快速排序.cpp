#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_S = 100005;
int a[MAX_S];
int res[MAX_S],w = 0;
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;++i)
    {
        cin>>a[i];
    }
    int cnt = 0;
    for(int i = 0;i < n;++i)
    {
        bool flag = true;
        for(int d = 0; d < i;++d)
        {
            if(a[d] > a[i])
            {
                flag = false;
                break;
            }
        }
        for(int d = n - 1; d > i;--d)
        {
            if(a[d] < a[i])
            {
                flag = false;
            }
        }
        if(!flag)
        {
            ++cnt;
        }
        else 
        {
            res[w++] = a[i];
        }
    }
    cout<<(n - cnt)<<endl;
    for(int i = 0;i < w;++i)
    {
        if(i != 0)
        cout<<" ";
        cout<<res[i];
    }
    return  0;
}