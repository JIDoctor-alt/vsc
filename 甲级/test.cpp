#include<iostream>
#include<algorithm>
using namespace std;
bool ad[20],rd[20],c[20];
int N,ans = 0;
int m[20][20];
void dfs(int k)
{

    if(k == N)
    {
        ++ans;
        return;
    }

    for(int i = 0;i < N;++i)
    {
        if(m[i][k] == 0 && !c[i] && !ad[k - i + N] && !rd[k + i])
        {
            c[i] = ad[k - i + N] = rd[k + i] = true;
            dfs(k+1);
            c[i] = ad[k - i + N] = rd[k + i] = false;
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
            cin>>m[i][j];
        }
    }
    //从第一列开始
    dfs(0);
    cout<<ans<<endl;
    return 0;
}