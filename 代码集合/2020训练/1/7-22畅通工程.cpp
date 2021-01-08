#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
struct pii
{
    int x,to;
    bool operator<(const pii& e)const
    {
        return to < e.to;
    }
};
struct node
{
    int a,b,c;
    bool operator<(const node& e)const
    {
        return c < e.c;
    }
};
vector<vector<pii> > G;
vector<node> v;
int N,M,cnt = 0,ans = 0;
int pre[1005];
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y,int le)
{
    int nx = find(x), ny = find(y);
    if(nx == ny)
        return;
    ans += le;
    
    if(nx < ny)
    {
        pre[ny] = nx;
    }
    else 
    {
        pre[nx] = ny;
    }
    ++cnt;
}
int main()
{
    iota(pre ,pre + 1005,0);
    cin>>N>>M;
    G.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        v.push_back({x,y,c});
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }
    sort(v.begin(),v.end());
    for(auto &w : v)
    {
        int  x1 = w.a, y1 = w.b, z1 = w.c;
        un(x1,y1,z1);
    }
    if(cnt == N - 1)
        cout<<ans<<endl;
    else 
        cout<<"-1\n";
    return 0;
}