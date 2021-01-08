#include<iostream>
#include<cstring>
#include<numeric>
using namespace std;
int pre[110];
int connect[110][110];
int N,M,K;
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y)
{
    int  nx = find(x), ny = find(y);
    if(nx == ny)
        return;
    if(nx < ny)
        pre[ny] = nx;
    else 
        pre[nx] = ny;
}
int main()
{
    memset(connect,sizeof(connect),0);
    iota(pre,pre + 110,0);
    cin>>N>>M>>K;
    for(int i = 0;i < M;++i)
    {
        int x,y,relation;
        cin>>x>>y>>relation;

        if(relation == 1)
           un(x,y);
        connect[x][y] = connect[y][x] = relation;
    }
    while (K--)
    {
        int a,b;
        cin>>a>>b;
        if(find(a) == find(b) && connect[a][b] != -1)
        {
            cout<<"No problem\n";
        }
        else if(find(a) != find(b) && connect[a][b] != -1)
        {
            cout<<"OK\n";
        }
        else if(find(a) == find(b) && connect[a][b] == -1)
        {
            cout<<"OK but...\n";
        }
        else if(find(a) != find(b) && connect[a][b] == -1)
        {
            cout<<"No way\n";
        }
    }
    
    return 0;
}