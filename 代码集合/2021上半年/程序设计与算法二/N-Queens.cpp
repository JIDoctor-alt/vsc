#include<iostream>

using namespace std;
int N,ans = 0;
int m[20][20];
bool c[20],d[20],ad[20];
void dfs(int k)
{   
    int i;
    if(k == N)
    {
        ans++;
        return;
    }
    for(i = 0;i < N;i++)
    {
        if(m[i][k] == 0&& !c[i] && !d[k-i+N] && !ad[k+i])
        {
            c[i] = d[k-i+N] = ad[k+i] = true;
            dfs(k+1);
             c[i] = d[k-i+N] = ad[k+i] = false;
        }
    }
}
int main(){
    cin>>N;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
            cin>>m[i][j];
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}