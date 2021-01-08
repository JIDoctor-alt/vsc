#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#define LL long long
using namespace std;
using pii = pair<LL,LL>;
struct edge
{
    int x,y,w;
};
vector<edge> g;
vector<LL> pa;
LL N,M;
LL find(LL x)
{
    return pa[x] == x ? x : find(pa[x]);
}
LL Kruscal()
{
    LL ans = 0,cnt = 0;
    iota(pa.begin(),pa.end(),0);
    sort(g.begin(),g.end(),[](auto &e1,auto &e2){return e1.w < e2.w;});
    for(auto e : g)
    {
        int nx = find(e.x);
        int ny = find(e.y);
        if(nx == ny)
            continue;
        ans += e.w;
        if(nx < ny)
            pa[ny] = nx;
        else 
            pa[nx] = ny;
        if(++cnt == N-1)
            break;
    }
    return (cnt == N - 1 ? ans : -1);
}
int main()
{
    cin>>N>>M;
    pa.resize(N+1);
    for(LL i = 0;i < M;++i)
    {
        LL x,y,z;
        cin>>x>>y>>z;
        g.push_back({x,y,z});
    }
    cout<<Kruscal()<<endl;
    return 0;
}
