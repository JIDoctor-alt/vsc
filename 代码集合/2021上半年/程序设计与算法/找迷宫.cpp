#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 1010;
struct Point
{
    int x,y,dis;
    char c;
};
int dx[4] = {1,0,0,-1};//向下走（D），向左走(L)，向右走(R)，向上走(U)
int dy[4] = {0,-1,1,0};
Point pa[MAX][MAX];
bool visited[MAX][MAX];
string str = "DLRU";
int a[MAX][MAX];
int R ,C ;
void printPath(Point p)
{
    string ansPtr = "";
    while(true)
    {

        ansPtr = p.c + ansPtr;
        p = pa[p.x][p.y];
        if(p.x == 0 && p.y == 0)
            break;
    }
    cout<<ansPtr<<endl;
}
void bfs()
{
    memset(visited,0,sizeof(visited));
    queue<Point> pq;
    visited[0][0] = true;
    pq.push({0,0,0,'-'});
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        if(v.x == R && v.y == C)
        {
            printPath(v);
            break;
        }
        for(int i  = 0;i < 4; ++i)
        {
            int nx = v.x + dx[i], ny = v.y + dy[i];
            if(nx >= 0 && nx <= R && ny >= 0 && ny <= C &&!visited[nx][ny] && a[nx][ny] == 0)
            {
                visited[nx][ny] = true;
                pq.push({nx,ny,v.dis+1,str[i]});
                pa[nx][ny] = v;
            }
        }
    }
}
int main()
{
    string s;
    int r = 0;
    while (cin>>s)
    {
        for(int i = 0;i < s.length();++i)
        {
            a[r][i] = s[i]  - '0';

        }
        ++r;
    }
    R = r - 1;
    C = s.length() - 1;
    bfs();
    return 0;
}