#include<iostream>
#include<string>
#include<vector>
using namespace std;
char g[110][110];
int N,M;
void dfs(int x,int y)
{
    g[x][y] = '.';
    for(int i = -1;i < 2;++i)
    {
        for(int j = -1;j < 2;++j)
        {
            int nx = x + i, ny = y + j;
            if(nx >= 0&& nx < N && ny >= 0 && ny < M)
                if(g[nx][ny] == 'W')
                    dfs(nx,ny);
        }
    }       
}
int main()
{
    string str;
    cin>>N>>M;
    getchar();//读走换行
    for(int i = 0;i < N;++i)
    {
        getline(cin,str);
        for(int j = 0;j < str.length();++j)
            g[i][j] = str[j];
    }
    int cnt  = 0;//计数器
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < M;++j)
        {
            if(g[i][j] == 'W')
            {
                ++cnt;
                dfs(i,j);
            }   
        }
    }
    cout<<cnt<<endl;
    return 0;
}