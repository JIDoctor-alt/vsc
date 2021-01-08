#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 100;
//定义该点的坐标，路径长度，方向
struct point
{
    int x,y,dis;
    char f;
};
//四个方向的行走顺序  
int dx[] = {1, 0 , 0, -1};//下走，左走，右走，上走
int dy[] = {0, -1, 1,  0};
string ds = "DLRU";
int a[MAX][MAX];//存储二维数组
int C,R;//定义行列的下标范围
bool visited[MAX][MAX];//是否访问过
point pa[MAX][MAX];//该坐标的父结点
void printPath(point p)//输出结果
{
    string ansStr = "";//利用字符串拼接的方法
    while(true)
    {
        ansStr = p.f + ansStr;
        p = pa[p.x][p.y];
        if(p.x == 0 && p.y == 0)
            break;
    }
    cout<< ansStr << "\n";
}
void bfs()
{
    memset(visited,0,sizeof(visited));
    queue<point> q;
    q.push({0,0,0,'-'});//起点的坐标入队，
    visited[0][0] = true;
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        if(p.x == R && p.y == C)//当访问到终点的时候结束，进行输出操作
        {
            printPath(p);
            break;
        }
        for(int i = 0;i < 4; ++i)//按照顺序访问没有访问的邻接点
        {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if(nx >= 0 && nx <= R && ny >= 0 && ny <= C && a[nx][ny] != 1 && !visited[nx][ny])
            {
                pa[nx][ny] = p;//记录父结点
                q.push({nx,ny,p.dis + 1,ds[i]});//对应结点的信息入队
                visited[nx][ny] = true;
            }
        }
    }
}
int main()
{
//    int n,m;
//    cin>>n>>m;
    string s;
    int r = 0;//记录行下标
    while(cin>>s)
    {
        for(int c = 0; c < s.length(); ++c)
        {
            a[r][c] = s[c] - '0';
        }
        ++r;
    }
    R = r - 1, C = s.length() - 1;//字符串的长度为列下标
    bfs();//广度优先搜索找到终点即使最短的
    return 0;
}