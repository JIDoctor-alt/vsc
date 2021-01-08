#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
using pii = pair<int,int>;
const int MAX_V = 110;
string str = "DLRU";
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
char a[MAX_V][MAX_V];
bool visited[MAX_V][MAX_V];
int N,M;
int R,C;
struct edge
{
    int x,y;
    char w;
    int dis;
};
edge pre[MAX_V][MAX_V];
void printPath(edge v)
{
    string ans  = "";
    while(true)
    {
        ans = v.w + ans;
        v = pre[v.x][v.y];
        if(v.x == 0 && v.y == 0)
            break;
    }
    cout<<ans<<endl;
}
void bfs()
{
    memset(visited,0,sizeof(visited));
    queue<edge> pq;
    visited[0][0] = 1;
    pq.push({0,0,'-',1});
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();

        if(v.x == R && v.y == C)
        {
            printPath(v);
            break;
        }
        for(int i = 0;i < 4;++i)
        {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && a[nx][ny] == '0' && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                pre[nx][ny] = v;
                pq.push({nx,ny,str[i],v.dis + 1});
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    getchar();
    string cs;
    for(int i = 0;i < N;++i)
    {
        getline(cin,cs);
        for(int j = 0;j < cs.size();++j)
        {
            a[i][j] = cs[j];
        }
    }
    R = N - 1;
    C = M - 1;
    bfs();
    return 0;
}