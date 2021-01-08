#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
const int MAX_V = 50;
struct Edge
{
    int x,y,dis;
    char c;
};
Edge pre[MAX_V][MAX_V];
bool visited[MAX_V][MAX_V];
int g[MAX_V][MAX_V];
int n,m;
string ds = "DLRU";
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
void printPath(Edge p)
{
    string ans = "";
    while(true)
    {
        ans = p.c + ans;
        p = pre[p.x][p.y];
        if(p.x == 0 && p.y == 0)
            break;
    }        
    cout<<ans<<endl;
}
void bfs()
{
    memset(visited,false,sizeof(visited));
    queue<Edge> pq;
    
    visited[0][0] = true;
    pq.push({0,0,0,'-'});
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();

        if(v.x == n - 1 && v.y == m-1)
        {
            printPath(v);
            break;
        }
        for(int i = 0;i < 4;++i)
        {
            int nx = v.x + dx[i], ny = v.y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 0 && !visited[nx][ny])
            { visited[nx][ny] = true;
                pq.push({nx,ny,v.dis + 1,ds[i]});
                pre[nx][ny] = v;
               
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    string str;
    getchar();
    for(int i = 0;i < n;++i)
    {
        getline(cin,str);
        for(int j = 0;j < str.length();++j)
        {
            g[i][j] = (str[j] - '0');
        }
    }
    bfs();
    return 0;
}