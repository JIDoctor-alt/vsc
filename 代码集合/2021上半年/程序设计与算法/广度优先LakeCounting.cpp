#include<iostream>
#include<queue>
#include<string>
using namespace std;
using pii = pair<int,int>;
const int MAX = 110;
char a[MAX][MAX];
int N,M;
void bfs(int i,int j)
{
    a[i][j] = '.';
    queue<pii> pq;
    pq.push({i,j});
    while(!pq.empty())
    {
        auto v  = pq.front();
        pq.pop();
        for(int i = -1;i < 2;++i)
        {
            for(int j = -1;j < 2;++j)
            {
                int ni = v.first + i, nj = v.second + j;
                if(ni >=0 && ni < N && nj >= 0 && nj < M && a[ni][nj] != '.')
                {
                    a[ni][nj] = '.';
                    pq.push({ni,nj});
                }
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    string str;
    getchar();
    for(int i = 0;i < N;++i)
    {
        getline(cin,str);
        for(int j = 0;j < str.length();++j)
            a[i][j] = str[j];
    }
    int cnt = 0;
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < M;++j)
        {
            if(a[i][j] != '.')
            {
                 bfs(i,j);
                 ++cnt;
            }        
        }
    }
    cout<<cnt<<endl;
    return 0;
}