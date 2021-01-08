#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_V = 110;
char a[MAX_V][MAX_V];
int N,M;
void dfs(int x,int y)
{
    a[x][y] = '.';
    for(int i = -1;i < 2;++i)
    {
        for(int j = -1;j < 2;++j)
        {
            int nx = x + i,ny = y + j;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && a[nx][ny] != '.')
            {
                dfs(nx,ny);
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < M;++j)
        {
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < M;++j)
        {
            if(a[i][j] != '.')
            {
                dfs(i,j);
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}