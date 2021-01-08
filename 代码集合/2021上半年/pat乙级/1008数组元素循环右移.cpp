#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
int a[110];
int main()
{
    cin>>N>>M;
    for(int i = 0;i < N;++i)
    {
        cin>>a[i];
    }
    M = M % 6;
    int ans = 0;
    for(int i = N - M ;i < N;i++)
    {
        ++ans;
        cout<<a[i];
        if(ans != N)
        {
            cout<<" ";
        }
        else 
        {
            cout<<endl;
        }
    }
    for(int i = 0;i < N - M;++i)
    {
       ++ans;
        cout<<a[i];
        if(ans != N)
        {
            cout<<" ";
        }
        else 
        {
            cout<<endl;
        } 
    }

    return 0;
}