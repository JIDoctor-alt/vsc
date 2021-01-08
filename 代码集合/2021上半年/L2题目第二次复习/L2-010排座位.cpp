#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
vector<int> pre;
int N,M,K;
int visited[101][101];
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x);
    int ny = find(y);
    if(nx != ny)
        pre[nx] = ny;
}
int main()
{
    cin>>N>>M>>K;
    pre.resize(N+1);
    iota(pre.begin(),pre.end(),0);
    for(int i = 0;i < M;++i)
    {
        int x,y,f;
        cin>>x>>y>>f;
        if(f != -1)
            un(x,y);
        visited[x][y] = visited[y][x] = f;
    }
    while(K--)
    {
        int a,b;
        cin>>a>>b;
        if((find(a) == find(b)) &&(visited[a][b] != -1))
        {
            cout<<"No problem"<<endl;
        }
        if((find(a) != find(b)) && ( visited[a][b] != -1))
        {
            cout<<"OK"<<endl;
        }
        if((find(a) == find(b)) && ( visited[a][b] == -1))
        {
            cout<<"OK but..."<<endl;
        }
        if((find(a) != find(b)) &&( visited[a][b] == -1))
        {
            cout<<"No way"<<endl;
        }
    }
    return 0;
}