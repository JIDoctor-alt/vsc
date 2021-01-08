#include<iostream>
using namespace std;
const int MAX_V = 20;
int a[MAX_V][MAX_V];
bool c[MAX_V] , ad[MAX_V], d[MAX_V];
int N,ans = 0;
void dfs(int k)
{
    int i;
    if(k == N)
    {
        ++ans;
        return;
    }
    for( i = 0;i < N;++i)
    {
        if(!c[i] && !ad[k - i + N] && a[i][k] == 0 && !d[k + i])
        {
            c[i] = ad[k - i + N] = d[k + i]  = true;
            dfs(k + 1);
            c[i] = ad[k - i + N] = d[k + i]  = false;
        }

    }
}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < N;++j)
        {
            cin>>a[i][j];
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}